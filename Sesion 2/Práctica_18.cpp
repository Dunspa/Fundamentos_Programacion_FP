#include <iostream>
using namespace std;

int main (){
	int minimo, maximo, desplazamiento, a_desplazar, numero_desplazado;
	
	cout << "Desplazamiento de entero dentro de un intervalo. \nValor mínimo del intervalo: ";
	cin >> minimo;
	cout << "Valor máximo del intervalo: ";
	cin >> maximo;
	cout << "Número de posiciones a desplazar: ";
	cin >> desplazamiento;
	cout << "Número dentro del intervalo para desplazar: ";
	cin >> a_desplazar;
	
	numero_desplazado = ((a_desplazar + desplazamiento - minimo) % (maximo - minimo + 1)) + minimo;									//Restando el numero completo por el minimo se obtiene cuantos numeros sobran a partir del maximo
																																	//El modulo & mas la diferencia en el intervalo devuelve un valor del intervalo	
																																	//+1 porque del 0 al X hay X+1 numeros
																																	//En resumen, se desplazan las posiciones hasta el 90, y luego las sobrantes se suman al minimo																								
	cout << "El número dentro del intervalo desplazado " << desplazamiento << " posiciones es: " << numero_desplazado;
	
}
