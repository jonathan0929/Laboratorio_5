#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{ 
	int dato;
	struct nodo *siguiente; // ponemos puntero al elemento siguiente
	struct nodo *anterior; //ponemos puntero al elemento anterior.
}NODO; // finalizamos la estructura del nodo, poniendo el nombre de la estructura.



NODO *NuevoNodo(int dato); // Funcion para crear nuevo nodo, a este nuevo nodo le pasamos el dato que va a tener el nodo inicialmente.
int InsertarInicio(NODO **head, int dato);// Insertar nodo al inicio, le pasamos head con ** para que no se pierda y le pasamos un dato.
int InsertarFinal(NODO **head, int dato);// Insertar nodo al final, le pasamos la cabeza y el dato que se va  a insertar
void ImprimirLista (NODO *head); // Funcion imprimir lista y usamos solo un * porque se va a consultar y no modificar.
int EliminarNodo(NODO **head, int dato);// Funcion para eliminar un nodo.
void InsertarAntes(int n, NODO **head, int dato); // Funcion insertar nodo antes de un nodo especifico.
void InsertarDespues (int n, NODO **head, int dato); // Funcion insertar nodo despues de un nodo especifico.
void EliminarLista(NODO **head); //Funcion eliminar lista
void TerminarNodo(NODO* nuevo);//funcion terminar nodo


// creamos funcion main

int main()
{
	NODO *head = NULL; //declaramos head y lo inicializamos en NULL

	InsertarInicio (&head, 3); // LLamamos funcion de insertar inicio, se le pasa la direccion de la head y le ponemos un dato.
	InsertarInicio (&head, 2);
	InsertarInicio (&head, 1);
	InsertarFinal(&head, 4); // llamamos funcion de insertar final, se le pasa direccion head y le ponemos un dato a imprimir.
	InsertarAntes(0,&head, 5); //llamamos funcion de insertar antes, n es igual a la posicion que ocupar.
	InsertarDespues(0,&head, 8); //llamamos funcion insertar despues, n es posicion, y le ponemos el dato a imprimir.
	EliminarNodo(&head, 3); // llamamos a eliminar nodo, le paso direccion head, y el nodo a eliminar.
	ImprimirLista(head); // imprimimos la lista y le pasamos la head.
	printf("\n");
	EliminarLista(&head); // Funcion eliminar lista.
   
	return 0;
}

void ImprimirLista (NODO *head) //Implementamos funcion
{
	NODO *NodoAux = head; // Este auxiliar para no perder el apuntador de la cabeza original y que corra la lista por medio del auxiliar. 

	while ( NodoAux != NULL) // Mientras Nodo Auxiliar sea diferente de NULL, es uqe existe un dato
	{
		printf ("%d" , NodoAux -> dato); // Si existe que me imprima el dato del nodo
		NodoAux = NodoAux -> siguiente; // y nos desplazamos al siguiente nodo
	}
}

void EliminarLista(NODO **head)//implementamos funcion
{
	NODO *NodoAux= NULL, *NodoActual=*head; 
	if (*head != NULL) //si head es diferente de NULL
	{
		while (NodoActual->anterior) //mientras nodo actual se le asigne nodo anterior
		{
			NodoActual=NodoActual->anterior; //nodo actual es igual a nodo actual asignar anterior
		}
		while (NodoActual) //mientras nodo actual
		{
			NodoAux=NodoActual; //nodo auxiliar es igual a nodo actual
			NodoActual=NodoActual->siguiente; //nodo actual = nodo actual y asignar el siguiente nodo
			TerminarNodo(NodoAux); // terminar nodo actual
		}
		*head=NULL; // le pedimos que apunte a NULL

	}
}



int InsertarInicio(NODO **head, int dato)// implemetacion agregar nodo al inicio
{
	NODO *nuevo = NULL; 
	nuevo = NuevoNodo(dato);// pasamos el dato que se nos dio al en la funcion de insertar al inicio 
	if (nuevo != NULL) // validamos que el nuevo nodo se haya creado.
	{
		nuevo -> siguiente = *head; //nuevo se le asigan siguiente y esto es igual al puntero head
		nuevo -> anterior =NULL; // nuevo se le asigna anterior y le pido que apunte a NULL
		if (*head != NULL) // quiere decir que el nodo ya tiene un dato si esto se cumple
			(*head) -> anterior = nuevo;
		*head = nuevo; // para que apunte al nuevo nodo que acabamos de crear
		return 1; // si todo sale bien que returne 1 para saber que si se pudo insertar
	}
	return 0; // para saber que no se inserto al inicio
}


int InsertarFinal(NODO **head, int dato) // implemtamos funcion
{
	NODO *nuevo = NULL, *NodoAux = *head; //  Se define nuevo nodo que vamos a crear y un puntero que apunte al puntero head. 
					     // NodoAux lo utilizamos para irlo recorriendo hasta que llegue al ultimo elemento de la lista.	
	nuevo = NuevoNodo(dato); // se llama la funcion Nuevo Nodo y le asignamos el dato
	if (nuevo != NULL) // se comprueba que se haya creado el nuevo nodo
	{
		while (NodoAux -> siguiente !=NULL) {NodoAux = NodoAux -> siguiente;} // mientras NodoAux-> siguiente, sea diferente de NULL 
	 // con esto sabemos que es el ultimo de la lista, se recorre el puntero auxiliar al siguiente de la lista.                                            

		nuevo -> anterior = NodoAux;// este viene siendo el ultimo de la lista.
		NodoAux -> siguiente = nuevo; // al nuevo que estamos creando.
		return 1; // si se inserto
	}
       return 0; // por si no se inserto.
}

void InsertarAntes(int n, NODO **head, int dato) //implementamos  funcion insertar antes
{

	NODO *nuevo = NuevoNodo(dato); // Nodo nuevo es igual al nuevo nodo y a este se le pasa un dato
	if ( nuevo != NULL) // si nuevo es diferente de NULL
	{
		NODO *NodoAux=*head; // puntero NodoAux que apunte a head, nodoaux se utiliza para irlo recorriendo
		NODO *anterior =NULL; //puntero anterior apunta a NULL
		int posicion=0; // se le asigna posicion cero
		while (posicion < n && NodoAux -> siguiente) //mientras posicion sea menor a n y a  nodoaux se le asigne el siguiente
		{
			NodoAux=NodoAux->siguiente; // nodo auxiliar es igual a nodo auxiliar y a este se le signa siguiente nodo
			posicion ++; // posicion aumenta de uno en uno
		}
		if (posicion == 0) // si posicion es igual a cero
		{
			nuevo->siguiente =NodoAux; // a nuevo se le asigna el siguiente y este es igual al nodo auxiliar
		        nuevo->anterior=NULL; // nuevo se le asigna anterior y este apunta a NULL
		

		        if (*head != NULL) // si head es diferente de NULL
				(*head) -> anterior = nuevo; //al puntero head se le asigna el anterior y este seria igual al nuevo
		        *head = nuevo; //para que apunte al  uevo nodo que acabamos de crear
		}
	 
		else // sino
		{
			nuevo->siguiente=NodoAux; // nuevo se le asigna el siguinte y este sera igual al nodo auxiliar
			anterior=NodoAux->anterior; // anterior sera igual al nodo auxiliar y a este se le asigna el anterior
			anterior->siguiente=nuevo; // anterior se le asigna siguiente y este sera igual al  uevo
			nuevo->anterior =NodoAux->anterior; // nuevo se le asigna anterior y este sera igual al nodo auxiliar
			                                    // que se aigna al anterior
			NodoAux->anterior=nuevo; //  nodo auxiliar se le asigna anterior y este sera igual a nuevo

		}
	}
	else
	{
		*head =  nuevo; // para que apunte al nuevo nodo que acabamos de crear

	}

}

		



void InsertarDespues (int n, NODO **head, int dato) // implementamos funcion llamar despues
{
	NODO *nuevo = NULL, *NodoAux = *head; // puntero nuevo que apunta a NULL y puntero que apunte a head
	int posicion = 0; // otrogamos posicion que inice en cero
	nuevo = NuevoNodo(dato); //nuevo es igual al nuevo nodo y le pasamos un dato 
	if (nuevo != NULL) //si nuevo es diferente de NULL le pido que
	{
		NODO *anterior = NULL; //puntero anterior que apunte a NULL
		while(posicion < n && NodoAux->siguiente != NULL) //mientras posicion sea menor a n que es la posicion que le indico
			                                          // y nodo auxiliar se le asigne a siguiente y este sea diferente de NULL
		{
			NodoAux = NodoAux->siguiente; //nodo auxiliar es igual a nodo auxiliar y se le asigna el siguiente nodo
			posicion ++;
		}
		nuevo -> siguiente = NodoAux ->siguiente; //nuevo se le asigan el siguiente nodo y esto es igual al nodo auxiliar
		                                          // y se le asigna el siguiente
		NodoAux->siguiente = nuevo; // nodo auxiliar se le asigna el siguiente y esto sera igual al  nuevo
		nuevo->anterior=NodoAux; //nuevo se le asigna anterior y esto es igual al nodo auxiliar
		anterior=NodoAux->siguiente; //anterior es igual al nodo auxiliar y a este se le asigna el siguiente nodo
		anterior->anterior=nuevo; //anterior se le asigna anterior y este sera igual al nuevo nodo
	}
	else
	{
		*head=nuevo; //para que apunte al nuevo nodo que acabamos de crear
	
	}

}


int EliminarNodo(NODO **head, int dato) // realizamos implementacion eliminar nodo
{       
// se crean 3 punteros, uno al nodo actual que va apuntar hacia head, el puntero anterior que apunta a NULL al igual que el puntero siguiente 
	NODO *actual = *head, *anterior = NULL, *siguiente = NULL; 

	while (actual != NULL) //mientras actuan sea diferente de NULL
	{
		if (actual -> dato == dato) // preguntamos si el dato actual es igual al dato que nos pasaron en la funcion
		{ 
			// considerar 3 opciones, si el nodo actual es head, el ultimo o un nodo intermedio

			if (actual == *head) // si nodo actual es igual a head
			{
				*head = actual -> siguiente; // si es igual a head, ponemos head igual  al siguiente nodo
				if (actual -> siguiente != NULL) //  si el actual siguiente es diferente de NULL
					actual -> siguiente -> anterior = NULL; // eliminamos enlace anterior del nodo
			}
			else if (actual -> siguiente == NULL) // cuando nuestro actual siguiente es igual al ultimo elemento de la lista 
			{
				anterior = actual ->anterior=NULL; // puntero anterior, es igual al actual anterior
				actual -> anterior = NULL; // actual anterior apuntan a NULL
				anterior -> siguiente = NULL; // eliminamos enlace cuando el nodo es el ultimo de la lista.

			}
			else  // Y cuando se trata de un nodo intermedio
			{ 
				anterior = actual-> anterior; // anterior es igual al actual anterior
				actual ->anterior = NULL; // actual anterior apunta a NULL, para quitar enlace
				siguiente = actual->siguiente; // siguiente es igual al actual siguiente
				actual -> siguiente = NULL; // quitamos el enlace nuevamente
				anterior -> siguiente= siguiente; //anterior siguiente es igual al siguiente
				siguiente -> anterior=anterior; //siguiente anterior es igual al anterior
			}
		        TerminarNodo(actual); // liberarmos memoria del nodo actual
			return 1; // que me retorne 1 si se pudo eliminar
		}
		actual = actual -> siguiente; // si se sale de la condicion while
	}
	return 0; // que no se elimino
}

NODO *NuevoNodo(int dato) // realizamos la implementacion del nuevo nodo
{
	NODO* nuevo = NULL; // Declarar estructura de nodo y que inicialice en null
	nuevo = (NODO*)malloc(sizeof(NODO)); // se reserva memoria para este nuevo nodo
	if (nuevo != NULL) // si nuevo es diferente de NULL quiere decir que si pudo reservar memoria
	{
		nuevo -> dato = dato; // Nuevo se le signa dato y esto es igual al dato que nos dan
		nuevo -> siguiente = NULL; // Nuevo se le asigna siguiente, apuntan a NULL
		nuevo -> anterior = NULL; // nuevo se le asigna anterior, apuntan a NULL
	}
	return nuevo; // que me retorne puntero que cree
}

void TerminarNodo(NODO* nuevo) // implementar funcion terminar nodo
{
	free(nuevo); //liberar puntero nuevo
}
