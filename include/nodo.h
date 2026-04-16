#ifndef __NODO_H__
#define __NODO_H__
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Nodo {
    struct Nodo *info;
    struct Nodo *sig;
    struct Nodo *ant;

} Nodo;
Nodo *nodo_crear(void *info, size_t size);
void *nodo_eliminar(Nodo *n);
bool *nodo_actualizar(void *info, size_t size);


#endif 
