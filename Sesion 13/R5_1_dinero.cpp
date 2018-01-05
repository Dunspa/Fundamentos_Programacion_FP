//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Dinero (Suma sobre el mismo objeto)

#include <iostream>
using namespace std;

class Dinero{
private:
	int euros, centimos;

	void CentimosToEuros (){
		const int CENTIMOS_EN_EURO = 100;
		
		while (centimos >= CENTIMOS_EN_EURO){
			centimos = centimos - CENTIMOS_EN_EURO;
			euros++;
		}
	}
public:
	Dinero (){
		euros = 0;
		centimos = 0;
	}
	
	void SetDinero (int eur, int cent){
		euros = eur;
		centimos = cent;
	}
	
	void Suma (Dinero cantidad2){
		euros = euros + cantidad2.GetEuros ();
		centimos = centimos + cantidad2.GetCentimos ();
		
		CentimosToEuros ();
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
	Dinero cantidad1, cantidad2;
	
	cout << "Euros y c�ntimos de la primera cantidad: ";
	cin >> euros1 >> centimos1;
	cout << "Euros y c�ntimos de la segunda cantidad: ";
	cin >> euros2 >> centimos2;
	
	cantidad1.SetDinero (euros1, centimos1);
	cantidad2.SetDinero (euros2, centimos2);
	
	cantidad1.Suma (cantidad2);
	
	cout << "\nEuros: " << cantidad1.GetEuros() 
		  << "\nCéntimos: " << cantidad1.GetCentimos();
	
}
