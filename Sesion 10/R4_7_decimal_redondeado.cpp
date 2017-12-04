//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Decimal redondeado

#include <iostream>
#include <cmath>
using namespace std;

double PotenciaEntera (double base, int exponente){
	double potencia;
	
	potencia = 1;
	for (int i = 0 ; i < exponente; i++){
		potencia = base * potencia;
	}
	
	return potencia;
}

double Redondea (double numero_real, int redondear){
	const int BASE10 = 10;
	double potencia, redondeo, numero_redondeado;
	
	potencia = numero_real * PotenciaEntera (BASE10, redondear);																			
	redondeo = round(potencia);																						
	numero_redondeado = redondeo / PotenciaEntera (BASE10, redondear);
	
	return numero_redondeado;
}

int main (){
	double numero_real, numero_redondeado;
	int redondear;
	
	cout << "�N�mero real que quiere aproximar? ";
	cin >> numero_real;
	cout << "�A cu�ntas cifras decimales? ";
	cin >> redondear;
	
	numero_redondeado = Redondea (numero_real, redondear);
	
	cout << "El n�mero redondeado a " << redondear << " cifras decimales es: "
		  << numero_redondeado;

}
