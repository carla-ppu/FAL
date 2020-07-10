/*
GRUPO:24
COMPONENTES DEL GRUPO:
Carla Peñarrieta Uribe y Rocio Garcia Nuñez
*/


#include <iostream>


using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
P={n>=0}

*/
bool es_sobrado(int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
    dig(n,i): devuelve el digito i-esimo de n
	dig(n,i) => n[i] (de esta manera tratamos los enteros como vectores de dígitos)
	n' = tamaños del vector n
    creciente(n,n'):para todo u,v:0<u<v<n' :n[u] < n[v]
    es_sobrado(k,n'):para todo k:0<=k<n' : es creciente(k,n')
  (2) Postcondici�n
	q={resul=es_sobrado(k,n')}

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo

 PASO 1. Variables
 int n-> almacena el numero entero y además es una variable que va cambiando su valor
 según avanza el bucle. Antes del bucle n es igual al último digito del entero n.
 bool es -> booleano que indica si un número es o no sobrado
 int n_ant-> son los digitos anteriores a n

  Un ejemplo:
  4  3  2  1
  1 iteración: n=1, n_ant=234
  2 iteración del bucle: n= 2, n_ant=34
  3 iteración del bucle: n=3 n_ant = 4



 PASO 2. Invariante
 n'-> es el tamaño del vector n
 resul= es_sobrado(h,n')

 I={resul= es_sobrado(h, n') ^ tam(h) = n'}

 PASO 3. Inicializaci�n:
 Existen dos casos:

 Si n<10 && n>=0, entonces solo hay un dígito por lo que es sobrado -> resul = es_sobrado(n,tam(n))= 1
 En caso contrario, continuaria la ejecución mientras sea creciente. Por lo que la iniciacizalición
 de las variables será:
	n_ant = n / 10;
	n = n % 10; //n actual
	
	resul = es_sobrado(n, tam(n) = n')

 PASO 4: Continuaci�n y finalizaci�n:
 Se cumplirá siempre durante el bucle que: n > 0 && es && n_ant>0

 PASO 5: Cuerpo del bucle
 Existen dos casos:
 1. n_ant%10<=n, en este caso resul= false ya que no sería un entero en el que sus digitos
 son estrictamente crecientes
 2. n_ant>n, condición que nos permitirá seguir iterando ya que los dígitos son crecientes.
 violamos resul = es_sobrado(n), para restaurarlo basta con  actualizar el valor de n,
 siendo n = n_ant%10 (con esto nos quedamos con el último dígito) y n_ant = n_ant/10 (disminuimos
 el valor de n_ant)
 Por ejmplo:
  4  3  2  1
   Inicialización antes del bucle -> n=1, n_ant=234
   1 iter: n = 1,  n_ant= 2 (se coontinua si n_ant>n)
   Se actulizan los valores de n y n_ant explicados anteriormente
  2 iteración del bucle: n= 2 , n_ant=3
	Se vuelven a actualizar los valores de n y n_ant
  3 iteración del bucle: n=3 n_ant = 4



PASO 6: Terminaci�n
Basta con tomar como cota |n_ant| ya que en cada iteración se le va quitando un dígito, por lo que
dicho valor absoluto decrece
*/


bool es_sobrado(int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	bool es = true;
	int n_ant = 0;

	if (n < 10 && n>=0) es= true;
	n_ant = n / 10;
	n = n % 10; //n actual

	while (n > 0 && es && n_ant>0) {
		if ((n_ant % 10) <= n) es = false;
		n = n_ant % 10;
		n_ant = n_ant / 10;
	}
	
	return	es;
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo
Hay dos formas de analizarlo:

1. Si tenemos en cuenta como tamaño del problema el número de dígitos(d) del número entero n:
t(d) = K0 + K1 d, con K0 y K1 (son constantes al inicio/ terminación y cuerpo del bucle)
por lo que su coste es O(d)

2. Si tomamos como medida directamente n como tamaño del problema:
n es potencia de 10 entonces, n = 10^d que es lo mismo que d = log10(n). 
Por eso la complejidad es  O(log (n))

*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


int main() {
	int n_casos;
	cin >> n_casos;
	while (n_casos > 0) {
		int n;
		cin >> n;
		if (es_sobrado(n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		n_casos--;
	}
	return 0;
}