//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Velocidad imputada

#include <iostream>
#include <string>
using namespace std;

int main (){
	
	char tipo_radar;
	double velocidad_captada, velocidad_imputada, acumulador;
	string matricula, guardar_matricula;
	const string terminador = "#";
	const int MARGEN_ERROR_F = 5, MARGEN_ERROR_M = 7;
	const double PORCENTAJE_ERROR_F = 5.0/100.0, PORCENTAJE_ERROR_M = 7.0/100.0;
	
	
	cout << "\nNúmero de matrícula: ";
	cin >> matricula;
	acumulador = 0;
	while (matricula != terminador){
		cout << "\n¿Qué tipo de radar es? Movil(M), Fijo(F): ";
		cin >> tipo_radar;
		cout << "\n¿Cuál es la velocidad captada por el radar? ";
		cin >> velocidad_captada;
		
		if (tipo_radar == 'F' || tipo_radar == 'f'){
			
			if (velocidad_captada <= 100){
				velocidad_imputada = velocidad_captada - MARGEN_ERROR_F;
				
			}
			else{
				velocidad_imputada = velocidad_captada - velocidad_captada * PORCENTAJE_ERROR_F;
				
			}
		}
		if (tipo_radar == 'M' || tipo_radar == 'm'){
			
			if (velocidad_captada <= 100){
				velocidad_imputada = velocidad_captada - MARGEN_ERROR_M;
				
			}
			else{
				velocidad_imputada = velocidad_captada - velocidad_captada * PORCENTAJE_ERROR_M;
				
			}
		}
		
		if (velocidad_imputada > acumulador){

			acumulador = velocidad_imputada;
			guardar_matricula = matricula;
		}
		
		cout << "Número de matrícula: ";
		cin >> matricula;
		
	}

	cout << "\nLa velocidad imputada por el radar es " << acumulador << " km/h"
		 << " para el coche con matrícula " << guardar_matricula;

}
