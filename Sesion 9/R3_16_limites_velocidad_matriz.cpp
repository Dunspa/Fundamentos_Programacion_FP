//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Límites de velocidad -en una matriz-

#include <iostream>
using namespace std;

int main (){
	const int PRIMER_NUMERO = 31, SUMA_FILA1 = 10, SUMA_FILA2 = 20, SUMA_FILA3 = 30;
	const int FILA1 = 0, FILA2 = 1, FILA3 = 2, COLUMNA3 = 2;
	const int NUMERO_FILAS = 5, NUMERO_COLUMNAS = 10;
	int cuadro_velocidad[NUMERO_FILAS][NUMERO_COLUMNAS];
	int i, j;
	
	i = 0;
	j = 0;
	
	for (i = 0 ; i < NUMERO_FILAS ; i++){
		if (i == 0)
			cuadro_velocidad[i][j] = PRIMER_NUMERO;
		else
			cuadro_velocidad[i][j] = PRIMER_NUMERO + (i + 1) * 10;
			
		for (j = 0 ; j < NUMERO_COLUMNAS ; j++){
			if (i == FILA1){
				cuadro_velocidad[i][j+1] = cuadro_velocidad[i][j] + SUMA_FILA1;
			}
			
			if (i == FILA2){
				if (j == COLUMNA3){
					cuadro_velocidad[i][j+1] = cuadro_velocidad[i][j] + SUMA_FILA2;
				}
				
				else{
					cuadro_velocidad[i][j+1] = cuadro_velocidad[i][j] + SUMA_FILA1;
				}
			}
			
			if (i >= FILA3){
				if (j == COLUMNA3){
					cuadro_velocidad[i][j+1] = cuadro_velocidad[i][j] + SUMA_FILA3;
				}
				
				else{
					cuadro_velocidad[i][j+1] = cuadro_velocidad[i][j] + SUMA_FILA1;
				}
			}
		}
		j = 0;
	}
	
	for (i = 0 ; i < NUMERO_FILAS ; i++){
		cout << "\n";
		for (j = 0 ; j < NUMERO_COLUMNAS ; j++){
			cout << " " << cuadro_velocidad[i][j];
		}
	}
}
