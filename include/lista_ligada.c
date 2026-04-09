#include 'lista_ligada.h'
#include 'nodo.h'

ListaDL *ListaDL_crear(ListaDL *l) {
    ListaDL *l= (ListaDL*)malloc(sizeof(ListaDL));
    l->head=l->tail=NULL;
    return(l);
}

bool lista_insertar_vacia(ListaDL *l, void *info, size) {
    if(l!=NULL) {
        return false;
    }else {
        Nodo *n=nodo_crear(info, size);
        l->head=n;
        l->tail=n;
        return true;
    }
}

bool lista_insertar_inicio(ListaDL *l, void *info, size_t size){
    if(l==NULL) {
        return false;
    }else {
        Nodo *new= nodo_crear(info,size);
        new->sig= l->head;
        l->head->ant=new;
        l->head=new;
        return true;
    }

}
bool lista_insertar_fin(ListaDL *l, void *info, size_t size) {
    if(!l) return false;
    Nodo *new=nodo_crear(info,size);
    new->ant=l->tail;
    l->tail->sig=new;
    l->tail=new;
    return true;
}

bool lista_es_vacia(ListaDL *l){
    if(l->head == NULL && l->tail =NULL) {
        return true;
    } else {
        return false;
    }
}
    
bool lista_insertar_pos(ListaDL *l,int pos, void *info, size_t size) {
    if(!l) return false;
    if(lista_es_vacia(l)) 
}
