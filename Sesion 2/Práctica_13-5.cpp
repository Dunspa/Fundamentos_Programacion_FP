#include <iostream>
using namespace std;

int main (){
	double kilometros;														
	double precio;						
	const double TARIFA_FIJA = 150, CENTIMOS_POR_KILOMETRO = 0.10;
	
	cout << "Para calcular el precio de su billete de avi�n, introduzca la distancia en kil�metros que hay al destino: ";
	cin >> kilometros;
	
	precio = (TARIFA_FIJA + (CENTIMOS_POR_KILOMETRO * kilometros));
	
	cout << "El precio de su billete es de " << precio << " euros.";
	
}
