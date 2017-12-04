//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Comprobación fecha separando E/S de los cómputos

#include <iostream>
using namespace std;

int main (){
	const int NUM_MESES = 12, MAX_FECHAS = 100;
	int anio, utilizados;
	int dias_meses[NUM_MESES] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int vector_dia[MAX_FECHAS], vector_mes[MAX_FECHAS], vector_anio[MAX_FECHAS];
	bool es_bisiesto;
	bool fecha_correcta[MAX_FECHAS];

	// Entradas
	utilizados = 0;
	cin >> vector_dia[utilizados];
	
	while (vector_dia[utilizados] > 0){
		cin >> vector_mes[utilizados];
		cin >> vector_anio[utilizados];
		utilizados++;
		
		cin >> vector_dia[utilizados];
	}
	
	// Cómputos
	es_bisiesto = (anio % 4 == 0 && !(anio % 100 == 0)) || anio % 400 == 0;
	
	if (es_bisiesto){
		dias_meses[2] = 29;
	}
	else{
		dias_meses[2] = 28;
	}
	
	for (int i = 0 ; i < utilizados ; i++){
		fecha_correcta[i] = vector_dia[i] <= dias_meses[i] && 
								  vector_dia[i] > 0;
								  
		fecha_correcta[i] = vector_mes[i] <= NUM_MESES && 
								  vector_mes[i] > 0;
	}
	
	// Salidas
	for (int i = 0 ; i < utilizados ; i++){
		if (fecha_correcta[i]){
			cout << " SI ";
		}
		else{
			cout << " NO ";
		}
	}
}
