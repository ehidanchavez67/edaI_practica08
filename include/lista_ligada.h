#ifndef __LISTA_LIGADA_H_
#define __LISTA_LIGADA_H_
#include 'nodo.h'
typedef struct ListaDL {
    struct Nodo *head;
    struct Nodo *tail;
}ListaDL;
ListaDL *ListaDL_crear(ListaDL *l);
bool lista_insertar_vacia(ListaDL *l, void *info, size);
bool lista_insertar_inicio(ListaDL *l, void *info, size_t size);
bool lista_insertar_fin(ListaDL *l, void *info, size_t size);
bool lista_es_vacia(ListaDL *l);
bool lista_insertar_pos(ListaDL *l,int pos, void *info, size_t size);
int lista_num_nodos(ListaDL *l);
typedef int (*ComparaFunc)(void* a, void* b);
Nodo* lista_buscar(ListaDL *l, void *dato_buscado, ComparaFunc comparar);

#endif


