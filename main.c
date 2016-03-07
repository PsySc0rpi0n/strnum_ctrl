#include <stdio.h>
#include "text.h"
#include "mem.h"

void help_menu (void);

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

    printf ("The string is: %s\n", string);
    string = reverse_string (string);

    printf ("The inverted string is: %s\n", string);
    string = insertion_up_sort (string);

    printf ("The insertion up sorted string is: %s\n", string);
    string = insertion_down_sort (string);

    printf ("The insertion down sorted string is: %s\n", string);

    switch (string_cmp (string, "carlo")) {
      case 2:  printf ("Cannot Compare. Sizes mismatch!\n");
                break;
      case 0:   printf ("String are equal!\n");
                break;
      case 1:   printf ("Strings are different!\n");
                break;
      default:  printf ("Unkown result!\n");
    }

    mem_free (string, dbm);
    return 0;
}


void help_menu (){
  puts ("\x1b[H\x1b[2J");
  printf ("Help Menu\n");
  printf ("Use <./string --debug-mode> or <./string -dbm> to enable debug mode!\n");
  printf ("To display this help menu, type <./string --help> or <./string -h>\n");
  printf ("Press any key to continue!\n");
  getchar ();
}
