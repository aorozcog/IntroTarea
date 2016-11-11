#include <iostream>

using namespace std;

struct node{
    int value;
    node *next;
};


void add_node(node *ptr, int value){ //Inserta un nodo despues del head
    node *new_node = new node; //Crea el nuevo nodo
    new_node -> value = value; //Le agrega el valor al nuevo nodo
    new_node -> next = (ptr -> next); //Pone en el next del nuevo nodo, el next del nodo que habia antes
    ptr -> next = new_node; //El next del anterior ahora apunta al nuevo noda
}

void list_nodes(node *ptr){
    node *actual; //Crea un nodo auxiliar "actual"
    actual = ptr; //Actual, sera el nodo HEAD 
    while(actual!=NULL){ //Recorrera los nodos hasta que sea NULL
        cout << actual->value << endl; //Muestra el ->valor del nodo actual
        actual = actual->next; //Actual ahora sera el siguiente nodo
    }
}

void buscar_nodes(node *ptr, int buscado){
    node *actual; //Nodo aux
    actual = ptr; //Primero sera el HEAD
    while(actual != NULL){ //recorre la lista
        if(actual->value == buscado){ 
            cout << "Coincidencia encontrada!" << endl;
        }
        actual = actual->next; //Avanza el la lista
    }
}

int main(){
    node *ptr;
    ptr = new node; //Crea un nodo
    ptr -> value = 1; //Le asigna el valor 1 al primer nodo
    ptr -> next = NULL; //Deja el next hacia NULL
    add_node(ptr, 34);
    add_node(ptr, 56);
    add_node(ptr, 78);
    list_nodes(ptr);
    buscar_nodes(ptr, 34);
    return 0;
}
