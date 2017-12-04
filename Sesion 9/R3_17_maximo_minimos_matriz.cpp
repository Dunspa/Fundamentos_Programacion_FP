//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Máximo de los minimos

#include <iostream>
using namespace std;

int main (){
	const int MAX_FIL = 10, MAX_COL = 10;
   double matriz[MAX_FIL][MAX_COL];
   double minimos_fila[MAX_FIL];
   int pos_col[MAX_FIL], pos_fil[MAX_FIL];
   int util_filas, util_columnas, mayor_numero, i, j, pos_max_col, pos_max_fil;
   
   cout << "Número de filas de la matriz: ";
   cin >> util_filas;
   cout << "Número de columnas de la matriz: ";
   cin >> util_columnas;

   for (i = 0 ; i < util_filas ; i++)
      for (j = 0 ; j < util_columnas ; j++)
         cin >> matriz[i][j];
   
   for (i = 0 ; i < util_filas ; i++){
   	j = 0;
   	minimos_fila[i] = matriz[i][j];
      for (j = 0 ; j < util_columnas ; j++){
			if (matriz[i][j] < minimos_fila[i]){
				minimos_fila[i] = matriz[i][j];
				pos_col[i] = j;
				pos_fil[i] = i;
			}
		}
	}
	
	mayor_numero = minimos_fila[0];
	pos_max_col = pos_col[0];
	pos_max_fil = pos_fil[0];
	for (i = 0 ; i < util_filas ; i++){
		
		if (minimos_fila[i] > mayor_numero){
			mayor_numero = minimos_fila[i];
			pos_max_col = pos_col[i];
			pos_max_fil = pos_fil[i];
		}
	}
	
	
	cout << "El mayor número de entre los mínimos de cada fila es: "
		  << mayor_numero << " cuya posición es: " << "(" << pos_max_fil 
		  << "," << pos_max_col << ")";
}
