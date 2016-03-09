#include <stdlib.h>
#include "menu_Main.h"
#include "text.h"
 
void menu_Main (void){
  printf ("Main Menu\n");
  printf ("\tSelect an Option:\n");
  printf ("\t\t[1] - Strings\n");
  printf ("\t\t[2] - Numbers\n");
  printf ("\t\t[0] - Exit\n");
  //CLEAR_SCREEN;
}
 
void menu_Strings (void){
  printf ("Menu Strings\n");
  printf ("\t[1] - Reverse String\n");
  printf ("\t[2] - Up Sort String\n");
  printf ("\t[3] - Down Sort String\n");
  printf ("\t[0] - Back\n");
  //CLEAR_SCREEN;
}
 
void menu_Numbers (void){
  printf ("Menu Numbers\n");
  printf ("\t[1] - Reverse Number\n");
  printf ("\t[2] - Up Sort Number\n");
  printf ("\t[3] - Down Sort Number\n");
  printf ("\t[0] - Back\n");
  //CLEAR_SCREEN;
}
 
void func_select (const unsigned short int opt, const unsigned short int mflag, void* value){
  switch (opt){
    case 0:  if (mflag == MAIN_MENU)
               exit (0);
             else
               menu_Main();
             break;
    case 1:  if (mflag == STRING_MENU)
               reverse_string (value);
             /*if (mflag == NUMBERS_MENU)
               reverse_number (value);*/
             break;
    case 2:  printf ("Case 2\n");
             insertion_up_sort (value);
             break;
    case 3:  insertion_down_sort(value);
             break;
    default: printf("Invalid option!!!\n");
             CLEAR_SCREEN;
             menu_Main();
  }
}
 
void print_result (void* value, const unsigned short int opt, const unsigned short int mflag) {
  if (mflag == STRING_MENU)
    switch (opt){
      case 1:   printf ("The reversed string is: %s\n", (char*) value);
                break;
      case 2:   printf ("The up sorted string is: %s\n", (char*) value);
                break;
      case 3:   printf ("The down sorted string is: %s\n", (char*) value);
                break;
      default:  printf ("Unkown Error\n");
    }else if (mflag == NUMBERS_MENU)
      switch (opt){
        case 1: printf ("The reversed number is: %s\n", (char*) value);
                break;
        case 2: printf ("The up sorted number is: %s\n", (char*) value);
                break;
        case 3:  printf ("The down sorted number is: %s\n", (char*) value);
                break;
      default:  printf ("Unkown Error\n");
      }
}
