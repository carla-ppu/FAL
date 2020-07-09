#include <iostream>

/*

N GRUPO:

NOMBRE Y APELLIDOS DE LOS MIEMBROS:
Rocío García y Carla Peñarrieta

OBSERVACIONES:


*/



using namespace std;

const int TMAX = 1000;  // No habr� vectores de m�s de 1000 elementos




/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
0<=n<=long(a)
*/
int pares_menos_impares(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'
  es_par(a,n):para todo i: 0<=i<n :a[i]%2 ==0
  es_impar(a,n):no(es_par(a,n))
  resul=sum i :0<=i<n :es_par(a,n)-es_impar(a,n)

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el algoritmo

 PASO 1: Variables
	a,n,sum e i

 PASO 2: Invariante

 resul=sum k :0<=k<n :es_par(a,n)-es_impar(a,n)



 PASO 3: Inicio
sum empieza en 0 y vamos a ver las 2 primeras posiciones
en a[o] hay un 2 y en a[1] hay 1
en la 1º pos hay num_par sum = 0+2
acontinuacon en la 2º pos hay un 1
por lo que sum = 0+2-1 


 PASO 4: Continuaci�n y finalizaci�n

 Si no se sale del rango va calculando la suma=es_par(a,n)-es_impar(a,n)
 Si se sale de rango es porque la i alcanza el valor de la n

 PASO 5: Bloque del bucle

 Si es_par(a,n) -->sum=+a[i]
 Si es_impar(a,n) -->sum=-a[i]
 sum= es_par(a,n)-es_impar(a,n)




 PASO 6: Terminaci�n.

 <inicio>
	<for>{
		<bloque>
			<condicion>
	}
 <fin>

 */



int pares_menos_impares(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int sum =0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			sum += a[i];
		}
		else {
			sum -= a[i];
		}
	}
	return sum;
}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo

Complejidad O(n)
Las variables y asignaciones son constantes 
y solo se necesita recorrer una vez el array


 */


 /* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

bool ejecuta_caso() {
	int a[TMAX];
	int n;
	lee_vector(a, n);
	if (n >= 0) {
		cout << pares_menos_impares(a, n) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	while (ejecuta_caso());
}