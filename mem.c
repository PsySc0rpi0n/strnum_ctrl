#include "mem.h"

/*****Memory Control*****/
int mem_error = MEM_ERROR_OK;

void* mem_alloc (const int size, unsigned short int dbm){
    void* result = NULL;

    if ((result = malloc(size)) == NULL)
      mem_error = MEM_ERROR_NO_MEMORY;
    else if (dbm == 1)
      printf ("Allocated memory: %p\n", result);

    return result;
}

void mem_free (void* ptr, unsigned short int dbm){
  if (!ptr)
    return;
  if (dbm == 1)
    printf ("Free'ed memory: %p\n", ptr);
  free (ptr);
}

int mem_get_error(void){
    return mem_error;
}

int mem_clear_error(void){
    return mem_error = MEM_ERROR_OK;
}
