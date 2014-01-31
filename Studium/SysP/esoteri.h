/*
 * ============================================================================
 *
 *       Filename:  esoteri.h
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

#ifndef ESOTERI_H
#define ESOTERI_H

#define LICENSE "GPL"
#define AUTHOR "Manuel Bellersen <manuel.bellersen@stud.htwk-leipzig.de>"
#define DESCRIPTION "Esoteric ..."
#define SUCCESS 0
#define DEVICE_NAME "esoteric"
//#define DEVICE_MAJOR_ID 249 // see ioctl_esoteric.h
#define DEVICE_MAX_MEMORY 1024


#define MORSE { " ",".-","-...","-.-.","-.. ",". ","..-. ","--.","....","..",".---",".-.-",".-..","--","-. ","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." }
#define ASCII { " ","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" }

/* ************************************************************************* */
/* ******************** */
/* function definitions */
/* ******************** */

/* **** */
/* INIT */
/* **** */
static int __init esoteric_start(void);

/* **** */
/* EXIT */
/* **** */
static void __exit esoteric_end(void);


/* *********** */
/* OPEN device */
/* *********** */
static int esoteric_open( struct inode *, struct file *);

/* ************ */
/* CLOSE device */
/* ************ */
static int esoteric_release( struct inode *, struct file *);

/* ******************************** */
/* READ                             */
/* -------------------------------- */
/* Reading from device into *buffer */
/* ******************************** */
static ssize_t esoteric_read( struct file *, char *, size_t, loff_t *);

/* ******************************** */
/* WRITE                            */
/* -------------------------------- */
/* Writing from *buffer into device */
/* ******************************** */
static ssize_t esoteric_write( struct file *, const char *, size_t, loff_t *);

/* ***** */
/* IOCTL */
/* ***** */
static long esoteric_ioctl( struct file *, unsigned int, unsigned long);
                                               

/* ******************************* */
/* setMemory                       */
/* ------------------------------- */
/* Allocating memory to store data */
/* ******************************* */
static int esoteric_setMemory(int);

/* ******************* */
/* freeMemory          */
/* ------------------- */
/* Freeing used memory */
/* ******************* */
static void esoteric_freeMemory(void);

/* ****************************************************** */
/* toASCII                                                */
/* ------------------------------------------------------ */
/* Converts morse-code in mbsbMSG to there ASCII code */
/* ****************************************************** */
static int esoteric_toASCII(void);

/* ****************************************************** */
/* toMorse                                                */
/* ------------------------------------------------------ */
/* Converts ASCII-code in mbsbMSG to there morse-code */
/* Will remove special-things first                       */
/* ****************************************************** */
static int esoteric_toMorse(void);

/* *********************************************************** */
/* toLower                                                     */
/* ----------------------------------------------------------- */
/* Converts characters from mbsbMSG into there lower parts */
/* *********************************************************** */
static int esoteric_toLower(void);

/* *************************************************************/
/* toUpper                                                     */
/* ----------------------------------------------------------- */
/* Converts characters from mbsbMSG into there upper parts */
/* *************************************************************/
static int esoteric_toUpper(void);

/* ************************************** */
/* noSpecial                              */
/* -------------------------------------- */
/* Removes special codes from mbsbMSG */
/* ************************************** */
static int esoteric_noSpecial(void);

/* **************************** */
/* waitForChange                */
/* ---------------------------- */
/* Returns when *buffer changed */
/* **************************** */
static int esoteric_waitForChange(void);

/* *********************** */
/* clearMemory             */
/* ----------------------- */
/* Setting *buffer to '\0' */
/* *********************** */
static void clearMemory(void);

/* ************************************************************************* */
/* ***************** */
/* globale variables */
/* ***************** */
static short int mbsbSizeOfMemory = 80;

static int mbsbDevice_Open = 0;
static long mbsbWritten = 0;
static long mbsbOldWritten = 0;
static char* mbsbMSG;
static char* mbsbMSG_PTR;
static struct file_operations mbsbFOps = {
    .read    = esoteric_read,
    .write   = esoteric_write,
    .unlocked_ioctl   = esoteric_ioctl,
    .open    = esoteric_open,
    .release = esoteric_release
};
static char morsecode2[27][5] = { " ",".-  ","-...","-.-.","-.. ",".   ","..-.","--. ","....","..  ",".---",".-.-",".-..","--  ","-.  ",
"--- ",".--.","--.-",".-. ","... ","-   ","..- ","...-",".-- ","-..-","-.--","--.." };
static char morsecode[27][5] = { " ",".-","-...","-.-.","-.. ",".","..-.","--.","....","..",".---",".-.-",".-..","--","-. ","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
static char asciicode[27][2] = { " ","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };

#endif