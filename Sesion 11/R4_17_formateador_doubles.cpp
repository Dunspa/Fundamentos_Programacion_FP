//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Formateador de doubles

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class FormateadorDoubles{
private:
	string cadena, delimitador_izda, delimitador_dcha, separador;
	double redondeado;
	
	double Redondear (double numero, int redondear){
		const int BASE10 = 10;
		double potencia, redondeo;
		
		potencia = numero * pow (BASE10, redondear);																			
		redondeo = round (potencia);																						
		numero = redondeo / pow (BASE10, redondear);
		
		return numero;
	}
	
	void SetSeparador (string separa){
		separador = separa;
	}
	
	void SetDelimitadores (string delim_izda, string delim_dcha){
		delimitador_izda = delim_izda;
		delimitador_dcha = delim_dcha;
	}
public:
	FormateadorDoubles (){
		delimitador_izda = "<<";
		delimitador_dcha = ">>";
		separador = ".";
	}
	
	void DoubleToString (double numero, int redondear, string separa, string delim_izda, string delim_dcha){
		double numero_redondeado;
		string redondeado_cadena;
		const int BASE10 = 10;
		const char A_BORRAR = '0';
		char convertir_char;
		int parte_entera, parte_decimal;
		
		SetSeparador (separa);
		SetDelimitadores (delim_izda, delim_dcha);
		
		redondeado_cadena = redondeado_cadena + delimitador_izda; 
		
		numero_redondeado = Redondear (numero, redondear);
		parte_entera = numero_redondeado / 1;
		convertir_char = parte_entera + A_BORRAR;
		redondeado_cadena.push_back (convertir_char);
		
		redondeado_cadena = redondeado_cadena + separador;
		numero_redondeado = numero_redondeado - parte_entera;
		numero_redondeado = Redondear (numero_redondeado, redondear);
		
		for (int i = 0 ; i < redondear ; i++){
			numero_redondeado = numero_redondeado * BASE10;
			parte_decimal = numero_redondeado / 1;
			convertir_char = parte_decimal + A_BORRAR;
			redondeado_cadena.push_back (convertir_char);
			numero_redondeado = numero_redondeado - parte_decimal;
		}
		
		redondeado_cadena = redondeado_cadena + delimitador_dcha; 
		
		cadena = redondeado_cadena;
	}
	
	string GetCadena (){
		return cadena;
	}
	
};

int main (){
	double numero;
	int redondear;
	string separa, delim_izda, delim_dcha;
	FormateadorDoubles cadena1;
	
	cout << "Introduzca un número decimal: ";
	cin >> numero;
	cout << "Número de cifras decimales a redondear: ";
	cin >> redondear;
	cout << "Introduzca un punto para separar el decimal por un punto o una coma"
		  << " para separarlo por una coma: ";
	cin >> separa;
	cout << "Introduzca el delimitador izquierdo y derecho para el string decimal: ";
	cin >> delim_izda >> delim_dcha;
	
	cadena1.DoubleToString (numero, redondear, separa, delim_izda, delim_dcha);
	
	cout << cadena1.GetCadena ();
}
