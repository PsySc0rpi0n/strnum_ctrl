#include <stdio.h>
#include "text.h"
#include "mem.h"

/*****Reverse String*****/
char* reverse_string (char* string){
  size_t len = strlen (string) - 1;
  size_t check = len / 2;
  unsigned int i;
  char tmp_char;

  for (i = 0; i <= check; i++){
    tmp_char = string [i];
    string [i] = string [len - i];
    string [len - i] = tmp_char;
  }
  return string;
}

/*Insertion Up Sort*/
char* insertion_up_sort (char* string){
  short unsigned int y = 0, index_min = 0, x;
  size_t len = 0;
  char tmp_char;

  len = strlen (string);
  for (x = 0; x < len; x++){
    index_min = x;
    for (y = x; y < len; y++){
      if (string [index_min] > string [y])
        index_min = y;
    }
    tmp_char = string [x];
    string [x] = string [index_min];
    string [index_min] = tmp_char;
  }
  return string;
}

/*Insertion Down Sort*/
char* insertion_down_sort (char* string){
  short unsigned int y = 0, index_min = 0, x;
  size_t len = 0;
  char tmp_char;

  len = strlen (string);
  for (x = 0; x < len; x++){
    index_min = x;
    for (y = x; y < len; y++){
      if (string [index_min] < string [y])
        index_min = y;
    }
    tmp_char = string [x];
    string [x] = string [index_min];
    string [index_min] = tmp_char;
  }
  return string;
}

unsigned short int string_cmp (char* str_a, char* str_b){
  size_t len_a = strlen (str_a), len_b = strlen (str_b);
  unsigned short int i, diff;

  if (len_a != len_b)
    printf ("Cannot copy strings... Sizes mismatches!\n");
  else{
    for (i = 0; i < len_a; i++){
      if (str_a [i] != str_b [i])
        diff = 1;
      else
        diff = 0;
    }
  }
  return diff;
}
