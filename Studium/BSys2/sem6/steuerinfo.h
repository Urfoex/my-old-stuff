/*
 * =====================================================================================
 *
 *       Filename:  steuerinfo.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29.03.10 15:21:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Manuel Bellersen (mbellers), manuel.bellersen@stud.htwk-leipzig.de
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef STEUERINFO_H
#define STEUERINFO_H

#include <stropts.h>

char* MASTERPIPE;
mode_t MASTERMODE;

void setMaster();
void unsetMaster();

/* Kann 10 Byte entgegen nehmen */
struct strbuf control;

/* Kann 80 Byte entgegen nehmen */
struct strbuf data;

void setControl();
void unsetControl();
void setData();
void unsetData();

#endif
