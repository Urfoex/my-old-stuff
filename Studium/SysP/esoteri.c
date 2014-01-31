/*
 * ============================================================================
 *
 *       Filename:  esoteri.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Manuel Bellersen , manuel.bellersen@stud.htwk-leipzig.de
 *        License:  GPLv3 or newer
 *
 * ============================================================================
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/ioctl.h>
#include <linux/sched.h>

#include "esoteri.h"
#include "ioctl_esoteric.h"

/* Setting parameter mbellesSizeOfMemory at beginning */
module_param( mbsbSizeOfMemory, short, 0000);
MODULE_PARM_DESC( mbsbSizeOfMemory, "Size of memory");

DECLARE_WAIT_QUEUE_HEAD( WaitForChangeQ);

/* ************************************************************************* */
static int __init esoteric_start(void){
    int ret = 0;

    printk( KERN_INFO "-- Starting esoteric --\n");
    printk( KERN_INFO "-- Size of memory will be: %d byte\n",
            mbsbSizeOfMemory);
    
    ret = register_chrdev(DEVICE_MAJOR_ID, DEVICE_NAME, &mbsbFOps);
    if( ret < 0){
        printk( KERN_ALERT "-- Could not register device: %d @%d\n",
                ret, DEVICE_MAJOR_ID);
        return ret;
    }

    ret = esoteric_setMemory( mbsbSizeOfMemory);
    if( ret != 0){
        return ret;
    }

    snprintf( mbsbMSG, mbsbSizeOfMemory*sizeof(char),
    "If you see this text nothing else were put here before.\n");

    printk( KERN_INFO "-- Now please run:\n");
    printk( KERN_INFO "-- 'mknod -m0777 /dev/%s c %d 0'\n",
            DEVICE_NAME, DEVICE_MAJOR_ID);
    printk( KERN_INFO "-- Please remove the file at the end.\n");

    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_setMemory(int v_mem){
    if( mbsbSizeOfMemory == v_mem && mbsbMSG > 0){
        printk( KERN_INFO "-- Requested size already there: %d\n", v_mem);
        return SUCCESS;
    }
    esoteric_freeMemory();
    mbsbSizeOfMemory = v_mem + 1;
    if( mbsbSizeOfMemory > DEVICE_MAX_MEMORY){
        mbsbSizeOfMemory = DEVICE_MAX_MEMORY;
        printk( KERN_INFO "-- Requested size to big: %d\n", v_mem);
        printk( KERN_INFO "-- Setting to max: %d\n", DEVICE_MAX_MEMORY);
    }else{
        if( mbsbSizeOfMemory <= 0){
            mbsbSizeOfMemory = 1;
            printk( KERN_INFO "-- Requested size to small: %d\n", v_mem);
            printk( KERN_INFO "-- Setting to 1\n");
        }
    }
    printk( KERN_INFO "-- Trying to get %d byte...\n", mbsbSizeOfMemory);
    mbsbMSG = (char*)vmalloc( mbsbSizeOfMemory * sizeof( char));
    if( mbsbMSG == NULL){
        printk( KERN_ALERT "-- Not enough space.\nClosing...\n");
        return -ENOMEM;
    }

    clearMemory();
    /* Setting moveable pointer to head of MSG */
    mbsbMSG_PTR = mbsbMSG;
    printk( KERN_INFO "-- Memory allocated.");
    return SUCCESS;
}

/* ************************************************************************* */
static void clearMemory(){
    int i = 0;
    mbsbMSG_PTR = mbsbMSG;
    for( i=0; i < mbsbSizeOfMemory; i += sizeof(char) ){
        (*(mbsbMSG_PTR+i))= '\0';
    }
    printk(KERN_INFO "-- ->i: %d\n",i);
    mbsbMSG_PTR = mbsbMSG;
}

/* ************************************************************************* */
static void __exit esoteric_end(void){
    printk( KERN_INFO "-- Closing esoteric --\n");
    unregister_chrdev( DEVICE_MAJOR_ID, DEVICE_NAME);
    esoteric_freeMemory();
    printk( KERN_INFO "-- esoteric closed. --\n");
}

/* ************************************************************************* */
static void esoteric_freeMemory(void){
    printk( KERN_INFO "-- Freeing %d byte memory...\n", mbsbSizeOfMemory);
    if( mbsbMSG > 0){
        vfree( mbsbMSG);
        printk( KERN_INFO "-- Done.\n");
    }else{
        printk( KERN_ALERT "-- Error while freeing memory...\n");
    }
    mbsbMSG = NULL;
    mbsbMSG_PTR = NULL;
}

/* ************************************************************************* */
static int esoteric_open( struct inode *inode, struct file *file){
    printk( KERN_INFO "-- Opening %s...\n", DEVICE_NAME);
    if( mbsbDevice_Open != 0){
        printk( KERN_INFO "-- %s already open\n", DEVICE_NAME);
        printk( KERN_INFO "-- %d times\n", mbsbDevice_Open);
/*        return -EBUSY;*/
    }
    ++mbsbDevice_Open;
    try_module_get( THIS_MODULE);
    /* Setting moveable pointer to head of MSG */
    mbsbMSG_PTR = mbsbMSG;
    printk( KERN_INFO "-- Done.\n");
    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_release( struct inode *inode, struct file *file){
    printk( KERN_INFO "-- Closing %s...\n", DEVICE_NAME); 
    printk( KERN_INFO "-- %d left\n", mbsbDevice_Open-1);
    --mbsbDevice_Open;
    module_put( THIS_MODULE);
    printk( KERN_INFO "-- Done.\n");
    return SUCCESS;
}

/* ************************************************************************* */
static ssize_t esoteric_read( struct file *ptrFile, char *buffer,
        size_t length, loff_t *offset){
    int bytes_read = 0;

    if( *mbsbMSG_PTR == 0){
        printk( KERN_INFO "-- READ Done.\n");
        return SUCCESS;
    }
    printk( KERN_INFO "-- Writeing into *buffer ...\n");
    while( (length != 0) && (*mbsbMSG_PTR != '\0')){
        if( put_user( *(mbsbMSG_PTR++), buffer++) != 0){
            printk( KERN_ALERT "-- Error on READ: %c\n",
                    *(mbsbMSG_PTR - sizeof(char)));
        }
        --length;
        ++bytes_read;
    }
    if( length != 0){
        put_user( *mbsbMSG_PTR, buffer);
    }


/*    --mbsbIsReading;*/

    return bytes_read;
}

/* ************************************************************************* */
static ssize_t esoteric_write( struct file *ptrFile, const char *buffer,
        size_t length, loff_t *offset){
    int sizeOfBuffer = mbsbSizeOfMemory*sizeof(char);
    int bytes_read = 0;
    
        printk( KERN_INFO "-- =B= %d | =L= %d\n", sizeOfBuffer, length);
    if( sizeOfBuffer < length){
        printk( KERN_ALERT "-- Message is to big. Adjusting...\n");
        esoteric_setMemory( length);
    }
    sizeOfBuffer = length;

    printk( KERN_INFO "-- Clearing old stuff...\n");
    clearMemory();
    mbsbMSG_PTR = mbsbMSG;
    printk( KERN_INFO "-- Reading from *buffer...\n");
    while(sizeOfBuffer != 0 && *buffer != 0){
        if( get_user( *(mbsbMSG_PTR++), buffer++) < 0){
            printk( KERN_ALERT "-- Error on WRITE: %c\n",
                    *(buffer - sizeof(char)));
        }
        --sizeOfBuffer;
        ++bytes_read;
    }

    ++mbsbWritten;
    wake_up( &WaitForChangeQ);
    printk( KERN_INFO "-- WRITE Done.\n");

    return bytes_read;
}

/* ************************************************************************* */
static long esoteric_ioctl( struct file *ptrFile, unsigned int ioctl_num,
        unsigned long ioctl_param){
    int length = 0;
    char *tmp;
    char ch;
    
    switch(ioctl_num){
        case SET_ESOTERIC_MESSAGE: /* SET_MSG */
            printk( KERN_INFO "-- -> SET_MSG\n");
            tmp  = (char*) ioctl_param;
            get_user( ch, tmp);
            for( length = 0; ch ; ++length, ++tmp){
                get_user( ch, tmp);
            }
            return esoteric_write( ptrFile, (char*) ioctl_param, length, NULL);
            break;
        case GET_ESOTERIC_MESSAGE: /* GET_MSG */
            printk( KERN_INFO "-- -> GET_MSG\n");
            mbsbMSG_PTR = mbsbMSG;
            return esoteric_read( ptrFile, (char*) ioctl_param,
                    mbsbSizeOfMemory, NULL);
            break;
        case SET_ESOTERIC_MEMORY: /* SET_SIZE_OF_MEMORY */
            printk( KERN_INFO "-- -> SET_MEM\n");
            return esoteric_setMemory( ioctl_param);
            break;
        case GET_ESOTERIC_MEMORY: /* GET_SIZE_OF_MEMORY */
            printk( KERN_INFO "-- -> GET_MEM\n");
            return mbsbSizeOfMemory;
            break;
        case SET_ESOTERIC_MORSE: /* CONVERT_TO_MORSE */
            printk( KERN_INFO "-- -> SET_MORESE\n");
            return esoteric_toMorse();
            break;
        case SET_ESOTERIC_ASCII: /* CONVERT_TO_ASCII */
            printk( KERN_INFO "-- -> SET_ASCII\n");
            return esoteric_toASCII();
            break;
        case SET_ESOTERIC_LOWER: /* TO_LOWER */
            printk( KERN_INFO "-- -> SET_LOWER\n");
            return esoteric_toLower();
            break;
        case SET_ESOTERIC_UPPER: /* TO_UPPER */
            printk( KERN_INFO "-- -> SET_UPPER\n");
            return esoteric_toUpper();
            break;
        case SET_ESOTERIC_NOSPECIAL: /* REMOVE_SPECIAL */
            printk( KERN_INFO "-- -> SET_NOSPEC\n");
            return esoteric_noSpecial();
            break;
        case GET_ESOTERIC_WAITFORCHANGE: /* WAIT_FOR_CHANGE */
            printk( KERN_INFO "-- -> GET_WAIT\n");
            return esoteric_waitForChange();
            break;
        default:
            printk( KERN_INFO "-- -> Default\n");
            break;
    }
    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_toASCII(void){
    int i = 0;
    int j = 0;
    int k = 0;
    int _i = 0;
    int counter = 0;
    char *c = NULL;
    char *kette;
    char *oldK;
    char zeichen[10];
    if( mbsbMSG[0] != '.' && mbsbMSG[0] != '-'){
	return 0;
    }

    kette = (char*)vmalloc( mbsbSizeOfMemory * sizeof( char));
    oldK = kette;
    if( kette == NULL){
        printk( KERN_ALERT "-- Not enough space.\nClosing...\n");
        return -ENOMEM;
    }

    for( i = 0; i < mbsbSizeOfMemory; i += sizeof(char)){
	for( _i = 0; _i < 10; zeichen[_i++]='\0');
	if( *(mbsbMSG + i) == 0){
            break;
	}
        for( j = 0;  j < 10; j++ ){                               
	    c = mbsbMSG + i + j;
            printk(KERN_INFO "--> c: %c\n", *c);
            if( ((*c==32) && (j>0))  || (*c == '\n') ){                
                i = i + j;
                break;
            }
            else{
                zeichen[j] = *c;
            }
        }
	for(; j < 4; zeichen[j++] = ' ');
	printk( KERN_INFO "--> z: %s\n", zeichen);
        for( k = 0; k < sizeof(morsecode2)/sizeof(*morsecode2); k++){
            if(strcmp(zeichen,morsecode2[k])==0){
		printk( KERN_INFO "--> z: %s :: %s :: %s\n", zeichen, morsecode2[k], asciicode[k]);
		strcat(kette, asciicode[k]);
		++counter;
                break;
            }
        }
    }
    strcat(kette, "\n\0");
    counter += 2;
    printk( KERN_INFO "--> k2: %s\n", oldK);
    esoteric_setMemory(counter);
    strncpy( mbsbMSG, oldK, counter);

    vfree( oldK);
    wake_up( &WaitForChangeQ);

    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_toMorse(void){
    int ret = 0;
    int i = 0;
    int j = 0;

    char *c = NULL;
    char *kette;
    char *oldK;

    kette = (char*)vmalloc( mbsbSizeOfMemory*5 * sizeof( char));
    oldK = kette;
    if( kette == NULL){
        printk( KERN_ALERT "-- Not enough space.\nClosing...\n");
        return -ENOMEM;
    }

    ret = esoteric_noSpecial();
    if( ret != SUCCESS){
        return ret;
    }
    esoteric_toUpper();

    for( i = 0; i < mbsbSizeOfMemory; i += sizeof(char)){
        c = mbsbMSG+i;
    printk( KERN_INFO "--> c: %c\n", *c);
	if( *c == '\0'){
	    strcat(kette, "\n\0");
	    break;
	}
        for( j = 0; j < sizeof(asciicode); j++){
           if( *c == asciicode[j][0] ){
    printk( KERN_INFO "--> c: %c\n", *c);
    printk( KERN_INFO "--> z: %s\n", kette);
               strcat(kette,morsecode[j]);
               strcat(kette," ");
    printk( KERN_INFO "--> z2: %s\n", kette);
	       break;
           }
        }
    }
    printk( KERN_INFO "--> z3: %s\n", kette);
    
    esoteric_setMemory(i*5);

    strncpy( mbsbMSG, oldK, i*5);
    vfree(oldK);
    wake_up( &WaitForChangeQ);

    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_toLower(void){
    int i = 0;
    char *c = NULL;
    for( i = 0; i < mbsbSizeOfMemory; i += sizeof(char)){
        c = mbsbMSG+i;
        if( *c > 64 && *c < 91){
            *c += 32;
        }
    }
    wake_up( &WaitForChangeQ);
    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_toUpper(void){
    int i = 0;
    char *c = NULL;
    for( i = 0; i < mbsbSizeOfMemory; i += sizeof(char)){
        c = mbsbMSG+i;
        if( *c > 96 && *c < 123){
            *c -= 32;
        }
    }
    wake_up( &WaitForChangeQ);
    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_noSpecial(void){
    int i = 0;
    int j = 0;
    char *c = NULL;
    char *d = NULL;    
    for( i = 0; i < mbsbSizeOfMemory; i += sizeof(char)){
        c = mbsbMSG+i;
        d = mbsbMSG+j;
        if( (*c >= 48 && *c <= 57) || 
	(*c >=65 && *c <= 90) || (*c >=97 && *c <= 122) ||
	( *c ==32 )){
            *d = *c;
            j++;
        }else if( *c == 0)
        {
            *d = *c;
            break;
        }
    }
    wake_up( &WaitForChangeQ);
    return SUCCESS;
}

/* ************************************************************************* */
static int esoteric_waitForChange(void){
    wait_event_interruptible( WaitForChangeQ,
            mbsbWritten != mbsbOldWritten);
    printk( KERN_INFO "-- NEW: %li | OLD: %li\n", mbsbWritten,
            mbsbOldWritten);
    mbsbOldWritten = mbsbWritten;
    return SUCCESS;
}

/* ************************************************************************* */

/* Setting init and end function */
module_init( esoteric_start);
module_exit( esoteric_end);

/* Setting information about this module */
MODULE_LICENSE( LICENSE);
MODULE_AUTHOR( AUTHOR);
MODULE_DESCRIPTION( DESCRIPTION);
MODULE_SUPPORTED_DEVICE( "none");
