//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Tarifa aérea según descuento

#include <iostream>
using namespace std;

int main (){
	double precio;						//Precio completo del billete sin aplicar descuento
	double descuento1;					//Descuento del 4%
	double descuento2;					//Descuento del 2%
	
	cout << "Introduzca el precio de su billete de avión para que se le apliquen los dos tipos de descuento: ";
	cin >> precio;
	
	descuento1 = (precio*0.96);
	descuento2 = (precio*0.98);
	
	cout << "Con un descuento del 4% el precio de su billete es de " << descuento1 << " euros, y con el descuento del 2% el precio es de " << descuento2 << " euros. ";
	
}
