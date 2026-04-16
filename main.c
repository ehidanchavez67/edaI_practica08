#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista_ligada.h"
#include "nodo.h"

int comparar_enteros(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    ListaDL* mi_lista = ListaDL_crear();
    
    int n1 = 10, n2 = 20, n3 = 30, n4 = 40;

    lista_insertar_vacia(mi_lista, &n1, sizeof(int));
    lista_insertar_inicio(mi_lista, &n2, sizeof(int));
    lista_insertar_fin(mi_lista, &n3, sizeof(int));
    lista_insertar_pos(mi_lista, 1, &n4, sizeof(int));

    printf("Nodos: %d\n", lista_num_nodos(mi_lista));
    printf("Vacia: %s\n", lista_es_vacia(mi_lista) ? "Si" : "No");

    int buscar = 10;
    Nodo* encontrado = lista_buscar(mi_lista, &buscar, comparar_enteros);
    if (encontrado) {
        printf("Encontrado: %d\n", *(int*)encontrado->info);
    }

    Nodo* tmp = mi_lista->head;
    printf("Lista: ");
    while (tmp) {
        printf("%d ", *(int*)tmp->info);
        tmp = tmp->sig;
    }
    printf("\n");

    return 0;
}