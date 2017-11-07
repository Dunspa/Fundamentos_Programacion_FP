//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
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
	cout << "Introduzca a qu� cifra decimal desea redondear el n�mero: ";			
	cin >> redondear;																								//Se introducen cuantas cifras se quiere redondear
	
	potencia = numero * pow(10,redondear);																			//Se mueve la coma hacia la derecha tantos lugares como cifras decimales se pidieron
	redondeo = round(potencia);																						//El numero obtenido se redondea al entero m�s cercano
	numerofinal = redondeo / pow(10,redondear);																		//Se vuelve a mover la coma, ahora a la izquierda, para volver el n�mero a la normalidad
	
	cout << "El n�mero redondeado a " << redondear << " cifra(s) decimales es: " << numerofinal;					//Se da el n�mero ya redondeado
	
}
