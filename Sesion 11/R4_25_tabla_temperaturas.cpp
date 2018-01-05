//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Tabla de temperaturas 

#include <iostream>
#include <cmath>
using namespace std;

struct ParFilaColumna{
	int fila;
	int columna;
};

class TablaTemperaturas{
private:
	static const int FILAS = 10;
	static const int COLUMNAS = 24;
	
	double matriz_temperaturas[FILAS][COLUMNAS];
	
	int Minimo (int ciudad){
		int hora;
		int hora_minima;
		double temperatura_minima;
		
		hora = 0;
		temperatura_minima = matriz_temperaturas[ciudad][hora];
		
		for (hora = 0 ; hora < COLUMNAS ; hora++){
			if (Valor (ciudad, hora) < temperatura_minima){
				temperatura_minima = Valor (ciudad, hora);
				hora_minima = hora;
			}
		}
		
		return hora_minima;	
	}
public:
	TablaTemperaturas (){
		for (int i = 0 ; i < FILAS ; i++){
			for (int j = 0 ; j < COLUMNAS ; j++){
				matriz_temperaturas[i][j] = NAN;
			}
		}
	}
	
	int GetFilas (){
		return FILAS;
	}
	
	int GetColumnas (){
		return COLUMNAS;
	}
	
	double Valor (int ciudad, int hora){
		return matriz_temperaturas[ciudad][hora];
	}
	
	void Modifica (int ciudad, int hora, double temperatura){
		matriz_temperaturas[ciudad][hora] = temperatura;
	}
	
	int MinimoCiudad (int ciudad){
		int col_minima;
		double minima;
		
		col_minima = 0;
		minima = Valor (ciudad, 0);
		
		for (int col = 1 ; col < COLUMNAS ; col ++){
			if (Valor (ciudad, col) < minima){
				minima = Valor (ciudad, col);
				col_minima = col;
			}
		}

		return col_minima;	
	}
	
	ParFilaColumna MaxMinimos (){
		ParFilaColumna maxminimos;
		int columna_minimos[FILAS];
		int col_min;
		double temperatura_maxima;
		
		for (int i = 0 ; i < FILAS ; i++){
			columna_minimos[i] = MinimoCiudad (i);
			// Rellenar columna_minimos llamando a MinimoCiudad (i)
		}											 
		
		temperatura_maxima = Valor (0, 0);
		
		for (int i = 0 ; i < FILAS ; i++){
			col_min = columna_minimos[i];
			if (Valor (i, col_min) > temperatura_maxima){
				temperatura_maxima = Valor (i, col_min);
				maxminimos.fila = i;
				maxminimos.columna = col_min;
			}
		}
		
		return maxminimos;
	}
};

int main (){
	TablaTemperaturas tabla;
	ParFilaColumna maxminimos;
	double valor_temperatura;
	
	cout << "Introduzca las temperaturas: \n";
	
	for (int i = 0 ; i < tabla.GetFilas () ; i++){
		for (int j = 0 ; j < tabla.GetColumnas () ; j++){
			cin >> valor_temperatura;
			tabla.Modifica (i, j, valor_temperatura);
		}
	}
	
	maxminimos = tabla.MaxMinimos ();
	
	cout << "\nCiudad: " << maxminimos.fila;
	cout << "\nHora: " << maxminimos.columna;
	cout << "\nTemperatura: " << tabla.Valor (maxminimos.fila, maxminimos.columna);
}
