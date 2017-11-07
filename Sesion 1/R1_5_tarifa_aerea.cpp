//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Tarifa aérea según km

#include <iostream>
using namespace std;

int main (){
	double kilometros;					//Número de kilómetros al destino
	double precio;						//Precio final del billete
	
	cout << "Para calcular el precio de su billete de avión, introduzca la distancia en kilómetros que hay al destino: ";
	cin >> kilometros;
	
	precio = (150+(0.10*kilometros));
	
	cout << "El precio de su billete es de " << precio << " euros.";
	
}
