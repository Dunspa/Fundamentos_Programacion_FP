//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Multa autov�a 

#include <iostream>
using namespace std;

int main (){
	int velocidad_vehiculo, multa_euros, multa_puntos;
	
	cout << "L�mite de velocidad 120 km/h. \n�A qu� velocidad iba el veh�culo?: ";
	cin >> velocidad_vehiculo;
	
	if (velocidad_vehiculo > 120){
		if (velocidad_vehiculo < 150){
			cout << "Se supera el primer exceso de velocidad, deber� pagar una multa de 100 euros.";
		}
		else
			if (velocidad_vehiculo < 170){
				cout << "Se supera el segundo exceso de velocidad, deber� pagar una multa de 300 euros y se le retirar�n 2 puntos del carnet.";
			}
			else{
				if (velocidad_vehiculo < 180){
					cout << "Se supera el tercer exceso de velocidad, deber� pagar una multa de 400 euros y se le retirar�n 4 puntos del carnet.";
				}
				else{
					if (velocidad_vehiculo < 190){
						cout << "Se supera el cuarto exceso de velocidad, deber� pagar una multa de 500 euros y se le retirar�n 6 puntos del carnet.";
					}
					else{
						cout << "Se supera el quinto exceso de velocidad, deber� pagar una multa de 600 euros y se le retirar�n 6 puntos del carnet.";
					}
				}
			}
	}
	else{
		cout << "Al veh�culo no se le aplica ninguna infracci�n puesto que no supera la velocidad l�mite de 120 km/h.";
	}
}
