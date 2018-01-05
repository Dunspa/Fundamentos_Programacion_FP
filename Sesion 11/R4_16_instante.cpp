//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Instante

#include <iostream>
using namespace std;

const int SEXAGESIMAL = 60, SEGUNDOS_EN_HORAS = 3600;
		
class Instante{
private:
	int horas, minutos, segundos;
public:
	Instante (){
		horas = 0;
		minutos = 0;
		segundos = 0;
	}
	
	int SegundosTranscurridos (int hor, int min, int sec){
		int segundos_totales;
	
		segundos_totales = hor * SEGUNDOS_EN_HORAS + min * SEXAGESIMAL + sec;
	
		
		return segundos_totales;
	}
	
	int MinutosTranscurridos (int hor, int min, int sec){
		int minutos_totales;
		
		minutos_totales = SegundosTranscurridos (hor, min, sec) / SEXAGESIMAL;
		
		
		return minutos_totales;
	}
	
	int InstanteHoras (){
		int hor;
		
		hor = segundos / SEGUNDOS_EN_HORAS;
		
		return hor; 
	}
	
	int InstanteMinutos (){
		int min;
		
		min = segundos / SEXAGESIMAL;
		
		while (min >= SEXAGESIMAL)
			min = min - SEXAGESIMAL;	
	
		return min;
	}
	
	int InstanteSegundos (){
		int sec;
		
		sec = segundos - SEGUNDOS_EN_HORAS - SEXAGESIMAL - SEXAGESIMAL;
		
		while (sec >= SEXAGESIMAL)
			sec = sec - SEXAGESIMAL;
		
		return sec;
	}
	
	void SetSegundos (int sec){
		segundos = sec;
	}
	
	void SetMinutos (int min){
		minutos = min;	
	}
	
	int GetSegundos (){
		return segundos;
	}
	
	int GetMinutos (){
		return minutos;
	}
};

int main (){
	int horas1, horas2, minutos1, minutos2, segundos1, segundos2;
	int diferencia_segundos, diferencia_minutos;
	Instante instante_inicial, instante_final, instante_diferencia;
	
	cout << "Horas, minutos y segundos del instante inicial: ";
	cin >> horas1 >> minutos1 >> segundos1;
	cout << "Horas, minutos y segundos del instante final: ";
	cin >> horas2 >> minutos2 >> segundos2;
	
	diferencia_segundos = 
		instante_final.SegundosTranscurridos (horas2, minutos2, segundos2)
		- instante_inicial.SegundosTranscurridos (horas1, minutos1, segundos1);

	diferencia_minutos = 
		instante_final.MinutosTranscurridos (horas2, minutos2, segundos2)
		- instante_inicial.MinutosTranscurridos (horas1, minutos1, segundos1);
	
	instante_diferencia.SetSegundos (diferencia_segundos);
	instante_diferencia.SetMinutos (diferencia_minutos);
	
	cout << "\nDiferencia: " 
		  << instante_diferencia.InstanteHoras() 
		  << "h " 
        << instante_diferencia.InstanteMinutos() 
		  << "' " 
		  << instante_diferencia.InstanteSegundos()
		  << "''";
	
	cout << "\nTotal segundos diferencia: " << instante_diferencia.GetSegundos ();
	cout << "\nTotal minutos diferencia: " << instante_diferencia.GetMinutos (); 
}
