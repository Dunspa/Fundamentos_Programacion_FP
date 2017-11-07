//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Intercambiar tres variables 

#include <iostream>
using namespace std;

int main (){
	double caja_x, caja_y, caja_z, guardar1;
	
	cout << "¿Valor que hay en la caja X? ";
	cin >> caja_x;
	cout << "¿Valor que hay en la caja Y? ";
	cin >> caja_y;
	cout << "¿Valor que hay en la caja Z? ";
	cin >> caja_z;
	
	guardar1 = caja_z;											//Se guarda el valor de Z
	caja_z = caja_y;											//El valor de Y pasa a Z
	caja_y = caja_x;											//El valor de Y se sobreescribe, X pasa a Y
	caja_x = guardar1;											//El valor de Z guardado anteriormente pasa a X
	
	cout << "Ahora el valor de la derecha es " << caja_x << ", el de la izquierda es " << caja_y << " y el del centro es " << caja_z;
}
