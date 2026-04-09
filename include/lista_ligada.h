#ifndef __LISTA_LIGADA_H_
#define __LISTA_LIGADA_H_
#include 'nodo.h'
typedef struct ListaDL {
    Nodo *head;
    Nodo *tail;
}ListaDL;
ListaDL *ListaDL_crear(ListaDL *l);
bool insertar_vacia(ListaDL *l, void *info, size);
bool ListaDL_insertar_inicio(ListaDL *l, void *info, size_t size);
bool ListaDL_insertar_fin(ListaDL *l, void *info, size_t size);
bool ListaDL_insertar_fin(ListaDL *l,int pos, void *info, size_t size);
bool ListaDL_es_vacia(ListaDL *l);

#endif


