#include <iostream>
using namespace std;

int main (){
	int hora1, hora2, minuto1, minuto2, segundo1, segundo2, tiempototal;
	
	cout << "Calcular el tiempo en segundos entre dos instantes. \nIntroduzca el instante inicial en horas: ";				//Se introduce la hora exacta inicial
	cin >> hora1;
	cout << "Minutos: ";
	cin >> minuto1;
	cout << "Segundos: ";
	cin >> segundo1;
	cout << "Ahora introduzca el instante final en horas: ";																//Se introduce la hora exacta final
	cin >> hora2;
	cout << "Minutos: ";
	cin >> minuto2;
	cout << "Segundos: ";
	cin >> segundo2;
	
	tiempototal = (((hora2*3600)+(minuto2*60)+segundo2)-((hora1*3600)+(minuto1*60)+segundo1));								//La resta entre el instante final y el inicial 
	
	cout << "El tiempo transcurrido entre los dos instantes es de " << tiempototal << " segundos.";							//da el tiempo transcurrido total entre los instantes
	
}
