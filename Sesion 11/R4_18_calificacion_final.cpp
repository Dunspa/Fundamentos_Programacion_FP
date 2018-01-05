//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Calificación final

#include <iostream>
using namespace std;

class CalificacionFinal{
private:
	double evaluacion_continua, examen_practico1, examen_practico2;
	double examen_escrito, nota_final;
	double PORCENTAJE_CONTINUA_PRACTICO1;
	double PORCENTAJE_PRACTICO2;
	double PORCENTAJE_ESCRITO;
	int MINIMO_PARA_APROBAR;
	
	double Media (double continua, double practico1, 
					  double practico2, double escrito){
	
		double media;
		const double CAMBIAR_PORCENTAJE_CONTINUA_PRACTICO1 = 5.0/100.0;
		const double CAMBIAR_PORCENTAJE_PRACTICO2 = 20.0/100.0;
		const double CAMBIAR_PORCENTAJE_ESCRITO = 70.0/100.0;
		const int MINIMO_PARA_APROBAR2 = 4.4;
			
		media = escrito * PORCENTAJE_ESCRITO + practico2 * PORCENTAJE_PRACTICO2 
				+ continua * PORCENTAJE_CONTINUA_PRACTICO1 
				+ practico1 * PORCENTAJE_CONTINUA_PRACTICO1;
		
		PORCENTAJE_CONTINUA_PRACTICO1 = CAMBIAR_PORCENTAJE_CONTINUA_PRACTICO1;
		PORCENTAJE_PRACTICO2 = CAMBIAR_PORCENTAJE_PRACTICO2;
		PORCENTAJE_ESCRITO = CAMBIAR_PORCENTAJE_ESCRITO;
		MINIMO_PARA_APROBAR = MINIMO_PARA_APROBAR2;
		
		return media;
	}
	
	void AjustarNota (){
		int cortar_decimal;
		
		cortar_decimal = nota_final;
		
		nota_final = cortar_decimal;
	}
public:
	CalificacionFinal (){
		PORCENTAJE_CONTINUA_PRACTICO1 = 10.0/100.0;
		PORCENTAJE_PRACTICO2 = 20.0/100.0;
		PORCENTAJE_ESCRITO = 60.0/100.0;
		MINIMO_PARA_APROBAR = 4;
	}
	
	double NotaFinal (double subida_lineal, double continua, double practico1, 
					   	double practico2, double escrito){
				   	
		const int MINIMO_PARA_SUBIDA = 5;
		const int NOTA_MAXIMA = 10;
		
		if (escrito >= MINIMO_PARA_APROBAR){
			escrito = escrito + subida_lineal;
			nota_final = Media (continua, practico1, practico2, escrito);
		
			if (nota_final < MINIMO_PARA_SUBIDA){
				escrito = escrito - subida_lineal;
				nota_final = Media (continua, practico1, practico2, escrito);
			}
		}
		else{
			nota_final = escrito;
		}
		
		if (nota_final > NOTA_MAXIMA)
			AjustarNota ();
				
		return nota_final;
	}
};

int main (){
	double subida_lineal, continua, practico1, practico2, escrito;
	const int TERMINADOR = -1;
	
	cout << "Subida lineal: ";
	cin >> subida_lineal;
	
	while (subida_lineal != TERMINADOR){
		cout << "Notas: ";
		cin >> continua;
		
		while (continua != TERMINADOR){
			cin >> practico1 >> practico2 >> escrito;
			
			CalificacionFinal calificacion;
			
			cout << "Nota final: " 
				  << calificacion.NotaFinal (subida_lineal, continua, practico1, practico2, escrito)
				  << "/" << calificacion.NotaFinal (subida_lineal, continua, practico1, practico2, escrito);
			
			cout << "\n\nNotas: ";
			cin >> continua;
		}
		
		cout << "Subida lineal: ";
		cin >> subida_lineal;
	}
	
	cout << "Fin del programa";
}
