//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Lee entero mayor o igual que otro
// Función añadida a la solución del ejercicio 2: Lee entero en rango

#include <iostream>  
// #include <limits>
using namespace std; 

int LeeIntMayorIgualQue (int minimo){
	int maximo;
	
	do{
		cin >> maximo;
	}while (maximo < minimo);
	
	return maximo;
}

/* 
Ampliación con la biblioteca #include <limits>

int LeeIntMayorIgualQue (int minimo){
	int a_leer;
	
	a_leer = LeeIntRango(minimo, numeric_limits<int>::max());
	
	return a_leer;
}
*/


int LeeIntRango(int minimo, int maximo) {
   int a_leer;
   
   do{
      cin >> a_leer;
   }while (minimo > a_leer || maximo < a_leer);
   
   return a_leer;
}

int main(){
   const int TOTAL_A_INTRODUCIR = 3;
   int minimo, maximo, dato, suma;
   
   cout << "\nIntroduzca el valor mínimo y el máximo"
        << "\nA continuación introduzca "
        << TOTAL_A_INTRODUCIR << " enteros en el rango anterior\n";
        
   cin >> minimo;
   maximo = LeeIntMayorIgualQue (minimo);
   suma = 0;
   
   for (int i = 0; i < TOTAL_A_INTRODUCIR; i++){
      dato = LeeIntRango(minimo, maximo);
      suma = suma + dato;
   }

   cout << "\nSuma total: " << suma;
}
