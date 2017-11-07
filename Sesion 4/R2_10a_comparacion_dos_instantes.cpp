//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Comparación de dos instantes versión a 

#include <iostream>
using namespace std;

int main (){
	int hora1, hora2, minuto1, minuto2, segundo1, segundo2, tiempo_en_segundos1, tiempo_en_segundos2, tiempo_transcurrido;
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
	
	tiempo_en_segundos1 = (hora1 * HORAS_EN_SEGUNDOS) + (minuto1 * MINUTOS_EN_SEGUNDOS) + segundo1;								
	tiempo_en_segundos2 = (hora2 * HORAS_EN_SEGUNDOS) + (minuto2 * MINUTOS_EN_SEGUNDOS) + segundo2;
	tiempo_transcurrido = tiempo_en_segundos2 - tiempo_en_segundos1;
	
	if (tiempo_transcurrido > 0){
		cout << "El primer instante es anterior al segundo.";
	}
	else{
		cout << "El segundo instante es anterior al primero.";
	}
	
}
