//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Comparación de dos instantes versión b 

#include <iostream>
using namespace std;

int main (){
	int hora1, hora2, minuto1, minuto2, segundo1, segundo2;
	const int HORAS_EN_SEGUNDOS = 60 * 60, MINUTOS_EN_SEGUNDOS = 60;
	
	cout << "Calcular el tiempo en segundos entre dos instantes. \nIntroduzca el instante inicial en horas: ";				
	cin >> hora1;
	cout << "Minutos: ";
	cin >> minuto1;
	cout << "Segundos: ";
	cin >> segundo1;
	cout << "Ahora introduzca el instante final en horas: ";																
	cin >> hora2;
	cout << "Minutos: ";
	cin >> minuto2;
	cout << "Segundos: ";
	cin >> segundo2;
	
	if (hora1 < hora2){
		cout << "El primer instante es anterior al segundo. ";
	}
	else{
		if (minuto1 < minuto2){
			cout << "El primer instante es anterior al segundo. ";
		}
		else{
			if (segundo1 < segundo2){
				cout << "El primer instante es anterior al segundo. ";
			}
			else{
				cout << "El segundo instante es anterior al primero. ";
			}
		}
	}
	
}
