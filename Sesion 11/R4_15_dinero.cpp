//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Dinero

#include <iostream>
using namespace std;

class Dinero{
private:
	int euros, centimos;
public:
	Dinero (){
		euros = 0;
		centimos = 0;
	}
	
	void SetDinero (int eur, int cent){
		const int CENTIMOS_EN_EURO = 100;
		
		while (cent >= CENTIMOS_EN_EURO){
			cent = cent - CENTIMOS_EN_EURO;
			eur++;
		}
			
		euros = eur;
		centimos = cent;
	}
	
	int GetEuros (){
		return euros;
	}
	
	int GetCentimos (){
		return centimos;
	}
};

int main (){
	double euros1, euros2, centimos1, centimos2;
	double euros_totales, centimos_totales;
	Dinero cantidad1, cantidad2, cantidad3;
	
	cout << "Euros y céntimos de la primera cantidad: ";
	cin >> euros1 >> centimos1;
	cout << "Euros y céntimos de la segunda cantidad: ";
	cin >> euros2 >> centimos2;
	
	cantidad1.SetDinero (euros1, centimos1);
	cantidad2.SetDinero (euros2, centimos2);
	
	euros_totales = cantidad1.GetEuros() + cantidad2.GetEuros();
	centimos_totales = cantidad1.GetCentimos() + cantidad2.GetCentimos();
	
	cantidad3.SetDinero (euros_totales, centimos_totales);
	
	cout << "\nEuros: " << cantidad3.GetEuros() 
		  << "\nCéntimos: " << cantidad3.GetCentimos();
	
}
