void menu_Main (void){
  printf ("Main Menu\n");
  printf ("\tSelect an Option:\n");
  printf ("\t\t[1] - Strings\n");
  printf ("\t\t[2] - Numbers\n");
  printf ("\t\t[0] - Exit\n");
  puts ("");
}

void menu_Strings (void){
  printf ("Menu Strings\n");
  printf ("\t[1] - Reverse String\n");
  printf ("\t[2] - Up Sort String\n");
  printf ("\t[3] - Down Sort String\n");
  printf ("\t[4] - Compare Strings\n");
  printf ("\t[0] - Back\n");
  puts ("");
}

void menu_Numbers (void){
  printf ("Menu Numbers\n");
  printf ("\t[1] - Reverse Number\n");
  printf ("\t[2] - Up Sort Number\n");
  printf ("\t[3] - Down Sort Number\n");
  printf ("\t[4] - Compare Numbers\n");
  printf ("\t[0] - Back\n");
  puts ("");
}

void func_select (const unsigned short int opt, const unsigned short int mflag, void* value){
  switch (opt){
    case 1:  if (mflag == 1)
               reverse_string (value);
             else
               reverse_number (value);
             break;
    case 2:  if (mflag == 1)
               insertion_up_sort (string);
             else
               ;
             break;
  }
}