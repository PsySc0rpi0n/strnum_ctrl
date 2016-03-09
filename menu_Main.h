#pragma once
 
#include <stdio.h>
 
#ifndef _WIN64
#define CLEAR_SCREEN system ("cls")
#else
#define CLEAR_SCREEN puts ("\x1b[H\x1b[2J")
#endif
 
 
 
#define MAIN_MENU    0
#define STRING_MENU  1
#define NUMBERS_MENU 2
 
void menu_Main    (void);
void menu_Strings (void);
void menu_Numbers (void);
void func_select  (const unsigned short int opt, const unsigned short int mflag, void* value);
void print_result (void* value, const unsigned short int opt, const unsigned short int mflag);
