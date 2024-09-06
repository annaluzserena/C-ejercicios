#include <stdio.h>

// Ejercicios recursión. 1) Sumar los elementos de un vector. 2) Sumar los elementos pares de un vector. 
// 3) Sumar los elementos pares e impares de un vector. 4) Calcular el promedio de notas cargadas en un vector, devolver las notas que
// superan el promedio.

int sumar(int vector[], int cant);
int sumarPares(int vector[], int cant);
void sumarParesImpares(int vector[], int cant, int *par, int *impar);
int contadorNotas(int vector[], int cant, float promedio);

int main() {
	int cant, par=0, impar=0;
	float promedio;

	printf("Ingrese la cantidad de notas a ser cargadas: ");
	scanf("%d", &cant);

	int vector[cant];

	// Carga de las notas
	for(int i=0; i<cant; i++) {
		printf("Ingrese la nota N° %d: ", i+1);
		scanf("%d", &vector[i]);
	}

	printf("Calculo de la suma de las notas mediante funcion recursiva \n");
	printf("El total de la suma es: %d\n", sumar(vector, cant));

	printf("Calculo de la suma de las notas con indice par mediante funcion recursiva \n");
	printf("El total de la suma es: %d\n", sumarPares(vector, cant));

	printf("Calculo de la suma de las notas con indice par e impar mediante funcion recursiva \n");
	sumarParesImpares(vector, cant, &par, &impar);
	printf("El total de la suma de pares es: %d\n", par);
	printf("El total de la suma de impares es: %d\n", impar);

	promedio = (par + impar)/cant;

	printf("Calculo del promedio y cantidad de notas que lo superan mediante funcion recursiva \n");
	printf("El promedio es: %.2f\n", promedio);
	printf("Cantidad de notas que superan el promedio: %d\n", contadorNotas(vector, cant, promedio));

	return 0;
}

int sumar(int vector[], int cant) {
	int suma=0, n=cant;

	if(n==1) {
		// Caso base
		return vector[0];
	} else {
		return suma+=vector[n-1] + sumar(vector, n-1);
	}
}

int sumarPares(int vector[], int cant) {
	int suma=0, n=cant;

	if(n==2) {
		return vector[1];
	} else {
		if(n%2==0) {
			return suma+=vector[n-1] + sumarPares(vector, n-1);
		} else {
			return sumarPares(vector, n-1);
		}
	}
}

void sumarParesImpares(int vector[], int cant, int *par, int *impar) {
	int n=cant;

	if(n==1) {
		*impar+=vector[0];
	} else {
		if(n%2==0) {
			*par+=vector[n-1];
		} else {
			*impar+=vector[n-1];
		}
		sumarParesImpares(vector, n-1, &*par, &*impar);	
	}
}

int contadorNotas(int vector[], int cant, float promedio) {
	int n=cant;

	if(n==1) {
		if(vector[0] > promedio) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if(vector[n-1] > promedio) {
			return 1 + contadorNotas(vector, n-1, promedio);
		} else {
			return contadorNotas(vector, n-1, promedio);
		}
	}
}
