#include <iostream>
using namespace std;

int main (){
	
	/* 
	
	a) Es un problema de desbordamiento ya que la multiplicación da un número mayor al rango que tiene int. 
	Para arreglarlo lo cambiaría por un tipo de dato long long.
	
	long long chico, chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	chico = chico1 * chico2; 	
	
	b) Es un problema de desbordamiento puesto que primero se evalúa la expresión de la derecha, que son dos int, por tanto se desborda 
	antes de llegar si quiera a meterse en un long. Para arreglarlo cambiaría todos los datos a long long.
	
	long long grande, chico1, chico2;
	chico1 = 1234567;
	chico2 = 1234567;
	grande = chico1 * chico2;
	
	c) Se devuelve un valor aproximado.
	
	double resultado, real1, real2;
	real1 = 123.1;
	real2 = 124.2;
	resultado = real1 * real2;
	
	d) Problema de desbordamiento, la multiplicación da lugar a un número que no cabe en el rango de double.
	Para arreglarlo usaría un tipo de dato mayor que double.
	
	e) Problema de desbordamiento, el número no cabe en un double, por lo que se almacena un número basura y la última ejecución no tendría sentido.
	Para arreglarlo usaría un tipo de dato más grande que double.

	f) Problema de desbordamiento, la multiplicación da lugar a un número que no cabe en el rango de double.
	Para arreglarlo usaría un tipo de dato mayor que double.
  
	g) Problema de precision. El 2 elevado a 150 se guarda primero en un doble, pero luego no cabe en un float por lo que se trunca.
	Para arreglarlo haría que "chico" fuese double.
	
	double chico;
	double grande;
	grande = 2e+150;
	chico = grande;
	
	*/

	
	
	
	
	
	
	
	
	
}
