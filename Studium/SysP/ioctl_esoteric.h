/*
 * ============================================================================
 *
 *       Filename:  ioctl_esoteric.h
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

#ifndef IOCTL_ESOTERIC_H
#define IOCTL_ESOTERIC_H

#define DEVICE_MAJOR_ID 249

#define SET_ESOTERIC_MESSAGE _IOR( DEVICE_MAJOR_ID, 0, char*)
#define GET_ESOTERIC_MESSAGE _IOR( DEVICE_MAJOR_ID, 1, char*)
#define SET_ESOTERIC_MEMORY _IOR( DEVICE_MAJOR_ID, 2, int)
#define GET_ESOTERIC_MEMORY _IOR( DEVICE_MAJOR_ID, 3, void*)
#define SET_ESOTERIC_MORSE _IOR( DEVICE_MAJOR_ID, 4, void*)
#define SET_ESOTERIC_ASCII _IOR( DEVICE_MAJOR_ID, 5, void*)
#define SET_ESOTERIC_LOWER _IOR( DEVICE_MAJOR_ID, 6, void*)
#define SET_ESOTERIC_UPPER _IOR( DEVICE_MAJOR_ID, 7, void*)
#define SET_ESOTERIC_NOSPECIAL _IOR( DEVICE_MAJOR_ID, 8, void*)
#define GET_ESOTERIC_WAITFORCHANGE _IOR( DEVICE_MAJOR_ID, 9, void*)

#endif