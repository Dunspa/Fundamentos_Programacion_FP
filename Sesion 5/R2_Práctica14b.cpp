#include <iostream>
using namespace std;

int main (){
	int a, b;
		
	cout << "Mismo signo con condicionales. \nIntroduzca el primer entero: ";
	cin >> a;
	cout << "Introduzca el segundo entero: ";
	cin >> b;
	
	if (a > 0){ 
		if (b < 0)
        	cout << "El primer número es positivo y el segundo es negativo";    	
	
		else
    		cout << "Ambos son positivos";
	}
	
	else if (a < 0) {
		if (b > 0)
    		cout << "El primer número es negativo y el segundo es positivo";
    	
		else
    		cout << "Ambos son negativos";
	}
	
}
