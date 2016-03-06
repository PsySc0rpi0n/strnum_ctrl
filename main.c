#include <stdio.h>
#include "text.h"
#include "mem.h"

int main (int argc, char** argv){
    char* string = NULL;

    string = mem_alloc (BUFFER);
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
    free (string);
    return 0;
}
