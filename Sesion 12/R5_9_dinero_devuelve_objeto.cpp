//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Dinero (Suma devolviendo un objeto nuevo)

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
	
	Dinero Suma (Dinero cantidad1, Dinero cantidad2){
		Dinero cantidad3;

		cantidad3.euros = cantidad1.euros + cantidad2.euros;
		cantidad3.centimos = cantidad1.centimos + cantidad2.centimos;
		
		cantidad3.CentimosToEuros ();

		return cantidad3;
	}

	int GetEuros (){
		return euros;
	}
	
	int GetCentimos (){
		return centimos;
	}

	string ToString(){
    	string cadena;

        cadena = "Euros: " + to_string (euros) 
        		 + "\nCéntimos: " + to_string (centimos); 

        return cadena;
    }
};

int main (){
	double euros1, euros2, centimos1, centimos2;
	Dinero cantidad1, cantidad2, suma_dineros;
	string cadena;
	
	cout << "Euros y céntimos de la primera cantidad: ";
	cin >> euros1 >> centimos1;
	cout << "Euros y céntimos de la segunda cantidad: ";
	cin >> euros2 >> centimos2;
	
	cantidad1.SetDinero (euros1, centimos1);
	cantidad2.SetDinero (euros2, centimos2);
	
	suma_dineros = suma_dineros.Suma (cantidad1, cantidad2);
	
	cadena = suma_dineros.ToString ();

	cout << cadena;
}
