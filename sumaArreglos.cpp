// sumaArreglos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

#define N 1000
#define chunk 100
#define mostrar 10

// Función para imprimir los primeros 'mostrar' valores de un arreglo
void imprimeArreglo(float *d);

int main()
{
	// Inicialización de la semilla para la generación de números aleatorios
	std::srand(std::time(nullptr));

	std::cout << "Sumando Arreglos en Paralelo!\n";

	// Declaración e inicialización de arreglos a, b, y c
	float a[N], b[N], c[N];
	int i;

	// Inicialización de los arreglos a y b con valores aleatorios en el rango de 1 a 100
	for (i = 0; i < N; i++)
	{
		a[i] = std::rand() % 100 + 1; // Números aleatorios en el rango de 1 a 100
		b[i] = std::rand() % 100 + 1;
	}

	// Número de pedazos para la paralelización
	int pedazos = chunk;

	// Uso de OpenMP para realizar la suma de arreglos en paralelo
	#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	// Impresión de los primeros 'mostrar' valores de los arreglos a, b, y c
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);
}

// Implementación de la función para imprimir los primeros 'mostrar' valores de un arreglo
void imprimeArreglo(float *d)
{
	for (int x = 0; x < mostrar; x++)
	{
		std::cout << d[x];
		if (x < mostrar - 1)
			std::cout << " - ";
	}
	std::cout << std::endl;
}
