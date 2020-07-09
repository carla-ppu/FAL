#include <iostream>

using namespace std;

const int TMAX = 1000;  // No habr� vectores de m�s de 1000 elementos




/*
NOMBRES: ROCÍO GARCÍA NÚÑEZ Y CARLA PAOLA PEÑARRIETA URIBE

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.

  1<=n<=long(a)

*/
bool es_gaspariforme(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):

  sumaParcial(a,i): para todo j: 0<=j < i: a[j]
  

  (2) Postcondici�n
  res=para todo i:0<=i<n sumaParcial(a,i) >=0 && sumaParcial(a,u)=0

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo

 PASO 1. Variables

 i -> es la variable de control
 suma -> acumulamos la suma de los elementos
 es -> booleano para saber si se cumple la condición de si es gaspariforme 



 PASO 2. Invariante

 res=para todo k, m :0<=k<m sumaParcial(a,k) >= 0 ^ sumaParcial(a,m)==0 ^ i>=n


 PASO 3. Inicializaci�n:
 i = 0 para que comience desde la 1º posicion del array
 sum = 0 para acumular las sumas parciales
 es = true para que se cumpla el 1º caso donde hay un elemento y en esa posición tiene guardado un 0

 PASO 4: Continuaci�n y finalizaci�n

	1. sumaParcial(a,i) >e, si esto no se cumple --> es=false y dejamos de recorrer el array
	Si no es falso se tiene que cumplir:
	res=para todo i:0<=i<n sumaParcial(a,i) >=0 && sumaParcial(a,u)=0 que esto quiere decir, que la sumaParcial > 0 
	y que la sumaParcial + el último elemento del array sea 0, en ese caso si es gaspariforme.





 PASO 5: Cuerpo del bucle.
 Si se cumple que i < n-1 y es gaspariforme vamos acumulando las sumas parciales: sum += a[i];
 Si no se cumple que i < n-1 y es gaspariforme (inicialmente a true para poder acceder while) podemos
 decir que no es gaspariforme por lo que se viola el invariante , entonces necesitamos restablecerlo
 para ello incrementamos la i (i++). 


PASO 6: Terminaci�n
Como n no es negativa e i crece en cada iteración podemos 
tomar como cota n-i


*/



bool es_gaspariforme(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int i = 0, sum = 0;
	bool es = true;
	
	//compruebas el 1 elemento
	if (n == 1 && a[i] == 0) es = true;
	else {
		//2º elemento hasta n-1
		while (i < n - 1 && es) {
			//suma parcial
			sum += a[i];
			if (sum > 0) i++;
			else es = false;


		}
		//Comprobación ultimo elemento
			
			sum = sum + a[n - 1];
			//si
			if (sum == 0 && es) es = true;
			else es = false;
		
	}
	return es;
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo

k0 es el coste de código de inicio y trerminación
k1 es el coste de codigo en cada iteracion
t(n)= nk1 + k0
lim n cuando tiende a infinito t(n)/ n = k1 > 0
Por lo tanto t(n) pertenece a  O(n)


*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n > 0) {
			if (es_gaspariforme(a, n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n != 0);
}