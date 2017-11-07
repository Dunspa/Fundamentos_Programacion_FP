//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Decimal redondeado

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double numero, redondear, potencia, redondeo, numerofinal;
	
	cout << "Introduzca la cifra que quiere redondear: ";
	cin >> numero;																									//Se introduce el numero decimal
	cout << "Introduzca a qué cifra decimal desea redondear el número: ";			
	cin >> redondear;																								//Se introducen cuantas cifras se quiere redondear
	
	potencia = numero * pow(10,redondear);																			//Se mueve la coma hacia la derecha tantos lugares como cifras decimales se pidieron
	redondeo = round(potencia);																						//El numero obtenido se redondea al entero más cercano
	numerofinal = redondeo / pow(10,redondear);																		//Se vuelve a mover la coma, ahora a la izquierda, para volver el número a la normalidad
	
	cout << "El número redondeado a " << redondear << " cifra(s) decimales es: " << numerofinal;					//Se da el número ya redondeado
	
}
