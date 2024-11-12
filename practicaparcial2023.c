#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Programa - Resolucion de segundo parcial del año 2023

/* La gomeria Juan o Juan recibe pedidos de ventas a traves de su tienda de internet. Al comenzar el dia se tienen los pedidos cargados en una cola para ser procesados, con la siguiente informacion: cod_producto, cantidad, zona de envio (norte, sur, este, oeste).
Se tiene ademas el listado de productos con la siguiente informacion: cod_producto, descripcion, stock y precio.
Se desea realizar la operatoria para procesar dichos pedidos, generando el ticket de entrega con la siguiente informacion: cod_producto, descripcion, zona, cantidad y precio total. Se debera actualizar el stock de la lista de productos por cada pedido procesado, y ademas se desea generar una lista final con la cantidad de pedidos por cod_producto y zona, y cantidad total que se pidio por cod_producto y zona.
Recorrer recursivamente la lista final e informar la cantidad de pedidos por zona, y la cantidad total de pedidos en general.*/

void procesarPedido(struct Pedido pedido, struct ListaProductos **LProd, struct ListaFinal **LFinal);
void recorrerRecursion(struct ListaFinal **LFinal, int *cont_norte, int *cont_sur, int *cont_este, int *cont_oeste, int *cont_total);

// Strings que utilizo para la comparacion en el recorrido recursivo.
char* norte = "norte";
char* sur = "sur";
char* este = "este";
char* oeste = "oeste";

int main() {
	struct ListaPedidos *LPed;
	struct ListaProductos *LProd;
	struct ListaFinal *LFinal;
	int cont_norte=0, cont_sur=0, cont_este=0, cont_oeste=0, cont_total=0;

	// Proceso de pedidos. Se recorre la lista de pedidos y se genera un ticket para cada pedido.
	// Manejo de la cola de pedidos
	
	struct ListaPedidos *aux;
	aux = LPed;
	
	while(aux!=0) {
		procesarPedido(aux->dato, &LProd, &LFinal);
		LPed = aux->psig;
		free(aux);
		aux = LPed;
	}

	// Recorrer la lista final recursivamente y devolver los contadores.
	
	recorrerRecursion(LFinal, &cont_norte, &cont_sur, &cont_este, &cont_oeste, &cont_total);
}

void procesarPedido(struct Pedido pedido, struct ListaProductos *LProd, struct ListaFinal **LFinal) {
	// Operatoria para procesar un pedido pasado por copia y generar el ticket.
	
	struct ListaProductos *auxProd;
	struct ListaFinal *auxFinal;
	struct ListaFinal *nodo;
	*nodo = 0;

	auxProd = LProd;
	auxFinal = *LFinal;

	while((auxProd->dato.cod_producto != pedido.cod_producto) && (auxProd->psig!=0)) {
		auxProd = auxProd->psig;
	}

	//Imprimir el ticket del pedido.
	
	printf("Ticket: \n");
	printf("Codigo de producto: %d \n", pedido.cod_producto);
	printf("Descripcion: %s \n", auxProd->dato.descripcion);
	printf("Zona: %s \n", pedido.zona);
	printf("Cantidad: %d \n", pedido.cantidad);
	printf("Precio total: %.2f \n", pedido.cantidad * auxProd->dato.precio);

	//Actualizacion del stock del producto.
	
	auxProd->dato.stock -= pedido.cantidad;

	//Generacion de un nodo nuevo para la lista final o actualizacion de un nodo existente.

	while(auxFinal!=0) {
		if((auxFinal->dato.cod_producto == pedido.cod_producto) && strcmp(auxFinal->dato.zona, pedido.zona)) {
			nodo = auxFinal;
			auxFinal = 0;
		} else {
			auxFinal = auxFinal->psig;
		}
	}

	if(nodo==0) {
                struct ListaFinal *nuevo = malloc(sizeof(struct ListaFinal));
                nuevo->dato.cod_producto = pedido.cod_producto;
                nuevo->dato.zona = pedido.zona;
                nuevo->dato.cantidad_pedidos = 1;
                nuevo->dato.cantidad_total = pedido.cantidad;   
                auxFinal->psig = nuevo;
                nuevo->psig = 0;
        } else {
		nodo->dato.cantidad_pedidos++;
		nodo->dato.cantidad_total += pedido.cantidad;
	}
}

void recorrerRecursion(struct ListaFinal *LFinal, int *cont_norte, int *cont_sur, int *cont_este, int *cont_oeste, int *cont_total) {
	//Recorrido recursivo de la lista final, incrementando los contadores.
	
	if(LFinal==0) {
		printf("Lista vacia o final de la lista. \n");
	} else {
		if(strcmp(norte, LFinal->dato.zona)) {
			*cont_norte += LFinal->dato.cantidad_pedidos;
		} else if(strcmp(sur, LFinal->dato.zona)) {
			*cont_sur += LFinal->dato.cantidad_pedidos;
		} else if(strcmp(este, LFinal->dato.zona)) {
			*cont_este += LFinal->dato.cantidad_pedidos;
		} else if(strcmp(oeste, LFinal->dato.zona)) {
			*cont_oeste += LFinal->dato.cantidad_pedidos;
		}
		*cont_total += LFinal->dato.cantidad_pedidos;
		recorrerRecursion(LFinal->psig, cont_norte, cont_sur, cont_este, cont_oeste, cont_total);
	}
}
