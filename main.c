#include <stdio.h>
#include "headers/text.h"
#include "mem.h"
#include "menu_Main.h"
 
void help_menu (void);
 
int main (int argc, char** argv){
    char* string = NULL;
    unsigned short int dbm = 0;
    unsigned int opt;
 
      if (argc == 2){
        if (!strcmp (argv [1], "-dbm") || !strcmp (argv [1], "--debug-mode"))
          dbm = 1;
        else
          dbm = 0;
 
        if (!strcmp (argv [1], "-h") || !strcmp (argv [1], "--help"))
          help_menu ();
      } else if (argc != 1 && argc != 2){
          printf ("Invalid arguments passed!!\n");
          help_menu();
          exit (0);
      }
        string = mem_alloc (BUFFER, dbm);
 
    //testing (string);
 
    do {
        menu_Main ();
        printf ("Choose an option:\n");
        scanf (" %u", &opt);
        switch (opt){
            case 0:   CLEAR_SCREEN;
                      exit (0);
            case 1:   CLEAR_SCREEN;
                      printf ("Insert a string:\n");
                      CLEAR_INPUT;
                      fgets (string, BUFFER, stdin);
                      if (string [strlen (string) - 1] == '\n')
                        string [strlen (string) - 1] = '\0';
                      menu_Strings ();
                      printf ("Choose an option:\n");
                      scanf (" %d", &opt);
                      func_select (opt, STRING_MENU, string);
                      print_result (string, opt, STRING_MENU);
                      break;
            case 2:   menu_Numbers ();
                      printf ("Choose an option:\n");
                      scanf (" %d", &opt);
                      func_select (opt, NUMBERS_MENU, string);
                      break;
            default:  printf ("Invalid option!\n");
        }
    }while (opt != 0);
 
    /*switch (string_cmp (string, "carlo")) {
      case 0:   printf ("String are equal!\n");
                break;
      case 1:   printf ("Strings are different!\n");
                break;
      case 2:   printf ("Cannot Compare. Sizes mismatch!\n");
                break;
      default:  printf ("Unkown result!\n");
    }*/
 
    mem_free (string, dbm);
    return 0;
}
 
 
void help_menu (void){
  CLEAR_SCREEN;
  printf ("Help Menu\n");
  printf ("Use <./string --debug-mode> or <./string -dbm> to enable debug mode!\n");
  printf ("To display this help menu, type <./string --help> or <./string -h>\n");
  printf ("Press any key to exit!\n");
  getchar ();
}
