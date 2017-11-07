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
using namespace std;

int main (){
	// Entradas
	char F, M, tipo_radar;
	int velocidad_captada;
	// Salidas
	double velocidad_imputada;
	// Constantes
	const int MARGEN_ERROR_F = 5, MARGEN_ERROR_M = 7;
	const double PORCENTAJE_ERROR_F = 5.0/100.0, PORCENTAJE_ERROR_M = 7.0/100.0;

	cout << "�Cu�l es la velocidad captada por el radar? ";
	cin >> velocidad_captada;
	cout << "\n�Qu� tipo de radar es? Movil(M), Fijo(F): ";
	cin >> tipo_radar;

	// C�mputos
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

	// Salida de resultados
	cout << "La velocidad imputada por el radar es " << velocidad_imputada << " km/h.";

}
