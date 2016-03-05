#include "mem.h"

/*****Memory Control*****/
int mem_error = MEM_ERROR_OK;

void* mem_alloc (const int size){
    void* result = NULL;
    if ((result = malloc(size)) == NULL)
        mem_error = MEM_ERROR_NO_MEMORY;
    return result;
}

int mem_get_error(void){
    return mem_error;
}

int mem_clear_error(void){
    return mem_error = MEM_ERROR_OK;
}
