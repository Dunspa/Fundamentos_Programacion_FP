//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Uso de constantes: Reescribir práctica 6 Tarifa aérea con descuento

#include <iostream>
using namespace std;

int main (){
	double precio;						
	double descuento1;					
	double descuento2;
	const double VALOR_DESCUENTO1 = 0.96, VALOR_DESCUENTO2 = 0.98;					
	
	cout << "Introduzca el precio de su billete de avión para que se le apliquen los dos tipos de descuento: ";
	cin >> precio;
	
	descuento1 = (precio * VALOR_DESCUENTO1);
	descuento2 = (precio * VALOR_DESCUENTO2);
	
	cout << "Con un descuento del 4% el precio de su billete es de " << descuento1 << " euros, y con el descuento del 2% el precio es de " << descuento2 << " euros. ";
	
}
