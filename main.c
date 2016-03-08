#include <stdio.h>
#include "text.h"
#include "mem.h"
#include "menu_Main.h"

//void help_menu (void);

int main (int argc, char** argv){
    char* string = NULL;
    unsigned short int dbm;

      if (!strcmp (argv [1], "-dbm") || !strcmp (argv [1], "--debug-mode"))
        dbm = 1;
      else
        dbm = 0;

      if (!strcmp (argv [1], "-h") || !strcmp (argv [1], "--help"))
        help_menu ();

    string = mem_alloc (BUFFER, dbm);

    printf ("Insert a string:\n");
    fgets (string, BUFFER, stdin);
    if (string [strlen (string) - 1] == '\n')
      string [strlen (string) - 1] = '\0';

    //testing (string);

    do {
        menu_Main ();
        print ("Choose an option:\n");
        scanf (" %d", opt);
        switch (opt){
            case 1:   menu_Strings ();
                      break;
            case 2:   menu_Numbers ();
                      break;
            default:  print ("Invalid option!\n");
        }
    }while (opt != 0);

    switch (string_cmp (string, "carlo")) {
      case 0:   printf ("String are equal!\n");
                break;
      case 1:   printf ("Strings are different!\n");
                break;
      case 2:   printf ("Cannot Compare. Sizes mismatch!\n");
                break;
      default:  printf ("Unkown result!\n");
    }

    mem_free (string, dbm);
    return 0;
}


void help_menu (void){
  puts ("\x1b[H\x1b[2J");
  printf ("Help Menu\n");
  printf ("Use <./string --debug-mode> or <./string -dbm> to enable debug mode!\n");
  printf ("To display this help menu, type <./string --help> or <./string -h>\n");
  printf ("Press any key to exit!\n");
  getchar ();
}