#include <iostream>
using namespace std;

int main (){
	double kilometros;					//N�mero de kil�metros al destino
	double precio;						//Precio final del billete
	
	cout << "Para calcular el precio de su billete de avi�n, introduzca la distancia en kil�metros que hay al destino: ";
	cin >> kilometros;
	
	precio = (150+(0.10*kilometros));
	
	cout << "El precio de su billete es de " << precio << " euros.";
	
}
