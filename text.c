#include <stdio.h>
#include "text.h"
#include "mem.h"

/*****Invert String*****/
char* reverse_string (char* string){
  char *tmp_str = NULL;
  short int i = 0;
  size_t len = 0;

  len = strlen (string);
  tmp_str = mem_alloc (BUFFER);

  for (i = len; i > 0; i--)
    tmp_str [len - i] = string [i - 1];

  tmp_str [len + 1] = '\0';

  free (string);
  return tmp_str;
}

/*****Sort Up*****/
char* up_sort (char* string){
  char* tmp_string = NULL;
  char tmp_char_lower, tmp_char;
  short unsigned int i = 0, j;
  size_t len = 0;

  len = strlen (string);
  tmp_string = mem_alloc (BUFFER);

  tmp_char_lower = string [i];
  for (j = 0; j < len; j++){
    i = j;
    while (string [i] != '\0'){           //faz enquato não chego ao fim da string
      if (string [i] < tmp_char_lower) {  //compara o char actual com o char em tmp_char_lower
        tmp_char_lower = string [i];      //se for mais pequeno, guarda em tmp_char_lower
      }
      i++;                                //avança para o próximo char na string
    }
    tmp_char = string [j];                //guarda em tmp_char, o char mais à esquerda antes de guardar lá o char mais pequeno
    string [j] = tmp_char_lower;          //guarda o menor char na posição mais à esquerda na string, posição 'j'
    string [i - 1] = tmp_char;            //coloca o char guardado em tmp_char na posição onde estava antes o char mais pequeno
  //i = j;                                //recomeça a pesquisa pelo char mais pequeno a partir da posição anterior + 1 já que a posição anterior já tem o char mais pequeno encontrado em toda a string
  }
  string [len + 1] = '\0';
  free (string);
  return tmp_string;
}
