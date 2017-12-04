//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Diferencia entre instantes

#include <iostream>
using namespace std;

const int SEXAGESIMAL = 60;
const int SEGUNDOS_EN_HORAS = 3600;
const int DIA = 24;

int SegundosTotales (int horas, int minutos, int segundos){
	int segundos_totales;
	
	segundos_totales = (horas * SEGUNDOS_EN_HORAS + minutos * SEXAGESIMAL + segundos);
							
	return segundos_totales;
}

int SegundosEntreInstantes (int hora1, int hora2, int minuto1, int minuto2, int segundo1, int segundo2){
	int segundos1, segundos2, segundos_totales;
	
	segundos1 = SegundosTotales (hora1, minuto1, segundo1);
	segundos2 = SegundosTotales (hora2, minuto2, segundo2);
	segundos_totales = segundos2 - segundos1;
	
	return segundos_totales;
}	

int MinutosEntreInstantes (int hora1, int hora2, int minuto1, int minuto2, int segundo1, int segundo2){
	int minutos_totales;
	
	minutos_totales = SegundosEntreInstantes (hora1, hora2, minuto1, minuto2, segundo1, segundo2) / SEXAGESIMAL;
		
	return minutos_totales;
}

int main (){
	int hora1, hora2, minuto1, minuto2, segundo1, segundo2;
	int minutos_entre_instantes, segundos_entre_instantes;
	
	cout << "Instante inicial: ";
	cin >> hora1 >> minuto1 >> segundo1;
	cout << "Instante final: ";
	cin >> hora2 >> minuto2 >> segundo2; 
	
	segundos_entre_instantes = SegundosEntreInstantes (hora1, hora2, minuto1, minuto2, segundo1, segundo2);
	minutos_entre_instantes = MinutosEntreInstantes (hora1, hora2, minuto1, minuto2, segundo1, segundo2);	
	
	cout << "\nSegundos transcurridos entre los dos instantes: " << segundos_entre_instantes;
	cout << "\nMinutos transcurridos entre los dos instantes: " << minutos_entre_instantes;
}
