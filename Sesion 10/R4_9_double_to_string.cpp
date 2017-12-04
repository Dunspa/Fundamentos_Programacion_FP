//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Double to string

#include <iostream>
#include <cmath>
#include <string>
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

string EliminaUltimos (string cadena, char a_borrar){
	int i;
	
	i = cadena.size () - 1;
	while (cadena[i] == a_borrar){
		cadena.pop_back ();
		i--;
	}
	
	return cadena;
}

string DoubleToString (double numero_real, int redondear){
	double numero_redondeado;
	string numero_redondeado_cadena;
	const char A_BORRAR = '0';
	
	numero_redondeado = Redondea (numero_real, redondear);
	numero_redondeado_cadena = to_string (numero_redondeado);
	numero_redondeado_cadena = EliminaUltimos (numero_redondeado_cadena, A_BORRAR);

	return numero_redondeado_cadena;
}


int main (){
	double numero_real;
	int redondear;
	string numero_redondeado;
	
	cout << "¿Número real que quiere aproximar? ";
	cin >> numero_real;
	cout << "¿A cuántas cifras decimales? ";
	cin >> redondear;
	
	numero_redondeado = DoubleToString (numero_real, redondear);
	
	cout << "El número redondeado como cadena de caracteres es: "
		  << numero_redondeado;
	
}
