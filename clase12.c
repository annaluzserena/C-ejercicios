#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Clase 12

struct Pedido {
	int codProd;
	int cuilCliente;
	int cant;
};

struct Producto {
	int cod;
	char descr[30];
	float precio;
	int stock;
};

struct Cliente {
	int cuil;
	char nombre[30];
	char apellido[30];
	char domicilio[50];
};

struct Ticket {
	int cuilCliente;
	char nombreApellido[50];
	char domicilio[50];
	char descripcion[30];
	float total;
};

struct LisPedidos {
	struct Pedido dato;
	struct LisPedidos *psig;
};

struct Cola {
	struct LisPedidos *ini;
	struct LisPedidos *fin;
};

struct LisProduc {
	struct Producto dato;
	struct LisProduc *psig;
};

struct LisClientes {
	struct Cliente dato;
	struct LisClientes *psig;
};

struct LisTickets {
	struct Ticket dato;
	struct LisTickets *psig;
};

struct LisPedidos *LPed = 0;
struct LisProduc *LProd = 0;
struct LisClientes *LCli = 0;
struct LisTickets *LTick = 0;

struct Cola *Pedidos=0;

void cargarProductos(void);
void cargarClientes(void);
void cargarPedido(void);
void generarTickets(void);


int main() {
	int a,b,c;
	
	printf("Ingreso de productos. \n");
	
	printf("Elija una opcion: \n");
	printf("0- Cargar un producto.\n");
	printf("1- Finalizar.\n");
	scanf("%d", &a);
	
	while(a==0) {
		cargarProductos();
		
		printf("Elija una opcion: \n");
		printf("0- Cargar un producto.\n");
		printf("1- Finalizar.\n");
		scanf("%d", &a);
	}
	
	printf("Ingreso de clientes. \n");
	
	printf("Elija una opcion: \n");
	printf("0- Cargar un cliente.\n");
	printf("1- Finalizar.\n");
	scanf("%d", &b);
	
	while(b==0) {
		cargarClientes();
		
		printf("Elija una opcion: \n");
		printf("0- Cargar un cliente.\n");
		printf("1- Finalizar.\n");
		scanf("%d", &b);
	}
	
	printf("Ingreso de pedidos. \n");
	
	printf("Elija una opcion: \n");
	printf("0- Cargar un pedido.\n");
	printf("1- Finalizar.\n");
	scanf("%d", &c);
	
	while(c==0) {
		cargarPedido();
		
		printf("Elija una opcion: \n");
		printf("0- Cargar un pedido.\n");
		printf("1- Finalizar.\n");
		scanf("%d", &c);
	}
	
	printf("Generacion de tickets. \n");
	
	
	
	
}

void cargarProductos(void) {
	
	struct LisProduc *nuevo = malloc(sizeof(struct LisProduc));
		
	printf("Ingrese el codigo de producto: ");
	scanf("%d", &nuevo->dato.cod);
	printf("Ingrese la descripcion del producto: ");
	scanf("%s", nuevo->dato.descr);
	printf("Ingrese el precio del producto: ");
	scanf("%f", &nuevo->dato.precio);
	printf("Ingrese el stock del producto: ");
	scanf("%d", &nuevo->dato.stock);
		
	nuevo->psig = LProd;
	LProd = nuevo;
}

void cargarClientes(void) {
	
	struct LisClientes *nuevo = malloc(sizeof(struct LisClientes));
		
	printf("Ingrese el cuil del cliente: ");
	scanf("%d", &nuevo->dato.cuil);
	printf("Ingrese el nombre del cliente: ");
	scanf("%s", nuevo->dato.nombre);
	printf("Ingrese el apellido del cliente: ");
	scanf("%s", nuevo->dato.apellido);
	printf("Ingrese el domicilio de entrega: ");
	scanf("%s", nuevo->dato.domicilio);
		
	nuevo->psig = LCli;
	LCli = nuevo;
}

void cargarPedido(void) {

	struct LisPedidos *nuevo = malloc(sizeof(struct LisPedidos));
		
	printf("Ingrese el codigo de producto: ");
	scanf("%d", &nuevo->dato.codProd);
	printf("Ingrese el cuil del cliente: ");
	scanf("%d", &nuevo->dato.cuilCliente);
	printf("Ingrese la cantidad del producto: ");
	scanf("%d", &nuevo->dato.cant);
		
	nuevo->psig = 0;
	Pedidos->fin.psig = nuevo;
	Pedidos->fin = nuevo;
}

void generarTickets(void) {
	
	struct LisTickets *nuevo = malloc(sizeof(struct LisClientes));
	struct LisPedidos *auxPed;
	struct LisProduc *auxProd;
	struct LisClientes *auxCli;
	
	auxPed = Pedidos->ini;
	auxProd = LProd;
	auxCli = LCli;
	
	while(aux!=0) {
		nuevo->dato.cuilCliente = aux->dato.cuilCliente;
		
		// Buscar datos producto
		//Buscar datos cliente
	}
}
