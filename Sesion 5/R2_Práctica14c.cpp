#include <iostream>
using namespace std;

int main (){
	int a, b;
	bool mismo_signo;
		
	cout << "Mismo signo sin condicionales. \nIntroduzca el primer entero: ";
	cin >> a;
	cout << "Introduzca el segundo entero: ";
	cin >> b;
	
	mismo_signo = (a > 0) && (b > 0) || (a < 0) && (b < 0);
	cout << "Mismo signo --> 1, Distinto signo --> 0. El valor es: " << mismo_signo;
		
}
