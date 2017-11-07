//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Multa autovía 

#include <iostream>
using namespace std;

int main (){
	int velocidad_vehiculo, multa_euros, multa_puntos;
	
	cout << "Límite de velocidad 120 km/h. \n¿A qué velocidad iba el vehículo?: ";
	cin >> velocidad_vehiculo;
	
	if (velocidad_vehiculo > 120){
		if (velocidad_vehiculo < 150){
			cout << "Se supera el primer exceso de velocidad, deberá pagar una multa de 100 euros.";
		}
		else
			if (velocidad_vehiculo < 170){
				cout << "Se supera el segundo exceso de velocidad, deberá pagar una multa de 300 euros y se le retirarán 2 puntos del carnet.";
			}
			else{
				if (velocidad_vehiculo < 180){
					cout << "Se supera el tercer exceso de velocidad, deberá pagar una multa de 400 euros y se le retirarán 4 puntos del carnet.";
				}
				else{
					if (velocidad_vehiculo < 190){
						cout << "Se supera el cuarto exceso de velocidad, deberá pagar una multa de 500 euros y se le retirarán 6 puntos del carnet.";
					}
					else{
						cout << "Se supera el quinto exceso de velocidad, deberá pagar una multa de 600 euros y se le retirarán 6 puntos del carnet.";
					}
				}
			}
	}
	else{
		cout << "Al vehículo no se le aplica ninguna infracción puesto que no supera la velocidad límite de 120 km/h.";
	}
}
