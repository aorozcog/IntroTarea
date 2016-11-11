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
    node *actual = ptr; //Crea un nodo auxiliar "actual" //Actual, sera el nodo HEAD 
    while(actual!=NULL){ //Recorrera los nodos hasta que sea NULL
        cout << actual->value << endl; //Muestra el ->valor del nodo actual
        actual = actual->next; //Actual ahora sera el siguiente nodo
    }
}

void buscar_nodes(node *ptr, int buscado){
    node *actual = ptr; //Nodo aux //Primero sera el HEAD
    while(actual != NULL){ //recorre la lista
        if(actual->value == buscado){ 
            cout << "Coincidencia encontrada!" << endl;
        }
        actual = actual->next; //Avanza el la lista
    }
}

void get_indice(node *ptr, int buscado){
	node *actual = ptr;
	int indx = 0;
	while(actual != NULL){
		if (actual->value == buscado){
			cout << "El int buscado (" << buscado << ") se encuentra en el indice " << indx << endl;
		}
		indx++;
		actual = actual->next;
	}
}

void add_node_final(node *ptr, int valor){
	node *nuevo = new node; //Se crea el nuevo nodo
	node *actual = ptr; //Se crea nodo aux para iterar
	node *ultimo = new node; //Se crea nodo aux para saber cual es el ultimo
	nuevo->value = valor; //Se le asgina el valor al nuevo
	nuevo->next = NULL; //Como esta al final, el valor es NULL
	while(actual != NULL){
		if(actual->next == NULL){ //Si es que es el ultimo de la lista
			ultimo = actual; //Se quiere que se convierta en el otro auxiliar
		}
		actual = actual->next;
	}
	ultimo->next = nuevo; //para finalmente agregar el nuevo al final de la lista
}

int main(){
    node *ptr;
    ptr = new node; //Crea un nodo
    ptr -> value = 1; //Le asigna el valor 1 al primer nodo
    ptr -> next = NULL; //Deja el next hacia NULL
    add_node(ptr, 34);
    add_node(ptr, 56);
    add_node(ptr, 78);
    add_node_final(ptr,233);
    add_node_final(ptr,5234);
    list_nodes(ptr);
    buscar_nodes(ptr, 34);
    get_indice(ptr, 5234);
    return 0;
}
