#include "lista_ligada.h"
#include "nodo.h"

ListaDL *ListaDL_crear() {
    ListaDL *l= (ListaDL*)malloc(sizeof(ListaDL));
    l->head=l->tail=NULL;
    return(l);
}

bool lista_insertar_vacia(ListaDL *l, void *info, size_t size) {
    if(l==NULL) {
        return false;
    }else {
        Nodo *n=nodo_crear(info, size);
        l->head=n;
        l->tail=n;
        return true;
    }
}

bool lista_insertar_inicio(ListaDL *l, void *info, size_t size) {
    if(l==NULL) return false;
    if(lista_es_vacia(l)) return lista_insertar_vacia(l, info, size);

        Nodo *new= nodo_crear(info,size);
        new->sig= l->head;
        l->head->ant=new;
        l->head=new;
        return true;
    }

bool lista_insertar_fin(ListaDL *l, void *info, size_t size) {
    if(!l) return false;
    if (lista_es_vacia(l)) return lista_insertar_vacia(l, info, size);
        Nodo *new=nodo_crear(info,size);
        new->ant=l->tail;
        l->tail->sig=new;
        l->tail=new;
        return true;
}

bool lista_es_vacia(ListaDL *l){
    if(l->head == NULL && l->tail ==NULL) {
        return true;
    } else {
        return false;
    }
}
    
bool lista_insertar_pos(ListaDL *l, int pos, void *info, size_t size) {
    if (!l) return false;
    
    int total_nodos = lista_num_nodos(l);
    
    if (pos < 0 || pos > total_nodos) return false;
    if (total_nodos == 0) return lista_insertar_vacia(l, info, size);
    if (pos == 0) return lista_insertar_inicio(l, info, size);
    if (pos == total_nodos) return lista_insertar_fin(l, info, size);

    Nodo* newNodo = nodo_crear(info, size);
    if (!newNodo) return false;

    Nodo* tmp = l->head;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->sig;
    }

    newNodo->sig = tmp;
    newNodo->ant = tmp->ant;
    
    if (tmp->ant != NULL) {
        tmp->ant->sig = newNodo;
    }
    
    tmp->ant = newNodo;

    return true;
}

int lista_num_nodos(ListaDL *l) {
    int i=0;
    for(Nodo *tmp = l->head; tmp !=NULL; tmp= tmp->sig, i++);
    return i;
}

Nodo* lista_buscar(ListaDL *l, void *dato_buscado, ComparaFunc comparar) {
    if (l == NULL || comparar == NULL) return NULL;
    Nodo *tmp = l->head;
    while (tmp != NULL) {
        if (comparar(tmp->info, dato_buscado) == 0) {
            return tmp; 
        }
        tmp = tmp->sig;
    }
    return NULL; 
}

int comparar_enteros(void* a, void* b) {
    int val_a = *(int*)a;
    int val_b = *(int*)b;
    return val_a - val_b; 
}
