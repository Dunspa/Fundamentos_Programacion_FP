#include <iostream>
using namespace std;

int main (){
	int a, b;
	
	cout << "Mismo signo con condicionales. \nIntroduzca el primer entero: ";
	cin >> a;
	cout << "Introduzca el segundo entero: ";
	cin >> b;
	
	if (a > 0 && b > 0)
		cout << "Los dos n�meros son positivos";
	else if (a > 0 && b < 0)
		cout << "El primer n�mero es positivo y el segundo negativo";
	else if (a < 0 && b > 0)
		cout << "El primer n�mero es negativo y el segundo positivo";
	else
		cout << "Los dos n�mero son negativos";
	
}
