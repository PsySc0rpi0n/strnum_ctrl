#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MEM_ERROR_OK             0
#define MEM_ERROR_NO_MEMORY     -1

void* mem_alloc(const int size, unsigned short int dbm);
void mem_free (void* ptr, unsigned short int dbm);

int   mem_get_error(void);
int   mem_clear_error(void);
