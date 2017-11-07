//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Cuadro de límites de velocidad

#include <iostream>
using namespace std;

int main (){
	int i, j, numero_columna;
	const int PRIMER_NUMERO = 31, SUMA_FILA1 = 10, SUMA_FILA2 = 20, SUMA_FILA3 = 30;
	const int FILA1 = 1, FILA2 = 2, FILA3 = 3, COLUMNA3 = 3, NUMERO_COLUMNAS = 10;
	
	numero_columna = 31;
	for (i = 1 ; i <= 5 ; i++){
		if (i == 1)
			numero_columna = PRIMER_NUMERO;
			
		else
			numero_columna = PRIMER_NUMERO + i * 10;
			
		cout << "\n" << numero_columna;
		for (j = 1 ; j < NUMERO_COLUMNAS ; j++){
			if (i == FILA1){
				numero_columna = numero_columna + SUMA_FILA1;
				cout << " " << numero_columna;
			}
			
			if (i == FILA2){
				if (j == COLUMNA3){
					numero_columna = numero_columna + SUMA_FILA2;
					cout << " " << numero_columna;
				}
				
				else{
					numero_columna = numero_columna + SUMA_FILA1;
					cout << " " << numero_columna;
				}
			}
			
			if (i >= FILA3){
				if (j == COLUMNA3){
					numero_columna = numero_columna + SUMA_FILA3;
					cout << " " << numero_columna;
				}
				
				else{
					numero_columna = numero_columna + SUMA_FILA1;
					cout << " " << numero_columna;
				}
			}
		}
	}
}
