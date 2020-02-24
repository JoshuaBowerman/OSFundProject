#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdint.h>
#include <stdio.h>
#include "macros.h"

int8_t Memory[ADDRESS_SPACE];		//The "Physical Memory"

//backing store file pointer
FILE *backing_fp;

//Statistics Variables
uint32_t Addresses_Translated = 0;
uint32_t Page_Faults = 0;
uint16_t Physical_Address = 0;


#endif