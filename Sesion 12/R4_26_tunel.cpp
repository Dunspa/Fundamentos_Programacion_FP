//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Túnel

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class FormateadorDoubles{
private:
   enum class SeparadorDecimal {PUNTO, COMA};
   string izda = "";  
   string dcha = "";  
   int decimales = 1;   
   SeparadorDecimal separador = SeparadorDecimal::PUNTO;   

   void SetDelimitadores(string delimitador_izda, string delimitador_dcha){
      izda = delimitador_izda;
      dcha = delimitador_dcha;
   }
   
   double PotenciaEntera(double base, int exponente){
   	double potencia;
   	int exponente_positivo;

   	if (base == 0 && exponente == 0)
   		potencia = NAN;				
   	else{
   		exponente_positivo = abs(exponente);
   		potencia = 1;

   		for (int i = 1; i <= exponente_positivo; i++)
   			potencia = potencia * base;
   	}

   	if (exponente < 0)
   		potencia = 1/potencia;

   	return potencia;
   }


   double Redondea(double real, int num_decimales){
      double real_redondeado;
      long long potencia_10;

      potencia_10 = PotenciaEntera(10, num_decimales);
      real_redondeado = round(real * potencia_10);
      real_redondeado = real_redondeado / potencia_10;

      return real_redondeado;
   }

   string EliminaUltimos(string cadena, char a_borrar){
      while (! cadena.empty() && cadena.back() == a_borrar)
         cadena.pop_back();

      return cadena;
   }
public:
   void SetSeparadorPunto(){
      separador = SeparadorDecimal::PUNTO;
   }
   void SetSeparadorComa(){
      separador = SeparadorDecimal::COMA;
   }

   string GetCadena(double real){
      const int MAX_DIGITOS_PRECISION_DOUBLE = 15;
      int parte_entera;
      int num_digitos_precision;
      string cadena_separador;
      string cadena = "";  

      if (real < 0)
         cadena = "-";

      real = abs(real);
      real = Redondea(real, decimales);
      parte_entera = trunc(real);
      cadena = cadena + to_string(parte_entera);
      num_digitos_precision = cadena.size();

      if (real != parte_entera
         && decimales > 0
         && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE){

         if (separador == SeparadorDecimal::PUNTO)
            cadena_separador = ".";
         else
            cadena_separador = ",";

         cadena = cadena + cadena_separador;

         for (int i = 0; i < decimales && num_digitos_precision < MAX_DIGITOS_PRECISION_DOUBLE; i++){
            real = Redondea(real - parte_entera, decimales);
            real = real * 10;
            parte_entera = trunc(real);
            cadena = cadena + to_string(parte_entera);
            num_digitos_precision++;
         }

         while (cadena.back() == '0')
            cadena.pop_back();
      }

      cadena = izda + cadena + dcha;

      return cadena;
   }
};

class Instante{
private:
   static const int SEGUNDOS_POR_MINUTO = 60,
          MINUTOS_POR_HORA = 60,
          HORAS_EN_DIA = 24;
   int hora    = -1;
   int minuto  = -1;
   int segundo = -1;
public:
	Instante (){
	}
   
	Instante(int hora_instante, int minuto_instante, int segundo_instante)
      :hora(hora_instante),
      minuto(minuto_instante),
      segundo(segundo_instante)
   {
   }
   
   void SetSegundosTotalesTranscurridos(int segundos_totales){
      int minutos_enteros;
      const int SEGUNDOS_EN_1_DIA = SEGUNDOS_POR_MINUTO
                                    * MINUTOS_POR_HORA
                                    * HORAS_EN_DIA;
                                    
      if (segundos_totales < SEGUNDOS_EN_1_DIA){
         segundo = segundos_totales % SEGUNDOS_POR_MINUTO;
         minutos_enteros = segundos_totales / SEGUNDOS_POR_MINUTO;
         minuto = minutos_enteros % MINUTOS_POR_HORA;
         hora = minutos_enteros / MINUTOS_POR_HORA;
      }
   }

   int SegundosTotalesEnterosTranscurridos(){
      return SEGUNDOS_POR_MINUTO * (hora * MINUTOS_POR_HORA + minuto)
             + segundo;
   }

   double MinutosTotalesDecimalTranscurridos(){
      return 1.0 * SegundosTotalesEnterosTranscurridos() / SEGUNDOS_POR_MINUTO;
   }

   double HorasTotalesDecimalTranscurridas(){
      return 1.0 * MinutosTotalesDecimalTranscurridos() / MINUTOS_POR_HORA;
   }
};

class Tunel{
private:
	static const int TAMANIO = 100;
	
	double longitud;
	string matriculas[TAMANIO];
	int entradas[TAMANIO] = {0};
	int salidas[TAMANIO] = {0};
	int utilizados = 0;
public:
	Tunel (double longit){
		longitud = longit;
	}
	
	void Entra (string matricula, int segundos){		
		matriculas[utilizados] = matricula;
		entradas[utilizados] = segundos;
		utilizados++;
	}
	
	void Sale (string matricula, int segundos){
		for (int i = 0 ; i < utilizados ; i++){
			if (matriculas[i] == matricula){
				salidas[i] = segundos;
			}				
		}
	}
	
	double Velocidad (int indice){
		double velocidad;
		double entrada, salida;
		Instante instante_inicial, instante_final;
		
		instante_final.SetSegundosTotalesTranscurridos (salidas[indice]);
		instante_inicial.SetSegundosTotalesTranscurridos (entradas[indice]);
		
		entrada = instante_inicial.HorasTotalesDecimalTranscurridas ();
		salida = instante_final.HorasTotalesDecimalTranscurridas ();
		
		velocidad = longitud / (salida - entrada);
		
		return velocidad;
	}
	
	int TotalEntradas (){
		return utilizados;
	}
	
	string Matricula (int indice){
		return matriculas[indice];
	}
};

int main (){
	int hora, minuto, segundo, segundos_transcurridos;
	double longit;
	const char TERMINADOR = '#', ENTRADA = 'E', SALIDA = 'S';
	char tipo_movimiento;
	string matricula_vehiculo;
	FormateadorDoubles cadena_velocidad;
	
	cout << "Introduzca la longitud del túnel (en Km): ";
	cin >> longit;
	
	Tunel tunel (longit);
	
	cout << "\nIntroduzca los siguientes datos (para terminar introduzca '#'):"
		  << "\n- Tipo de movimiento. Entrada: E, Salida: S."
		  << "\n- Matrícula del vehículo."
		  << "\n- Instante en el que se produce el movimiento.\n";
	cin >> tipo_movimiento;
	while (tipo_movimiento != TERMINADOR){
		cin >> matricula_vehiculo;
		cin >> hora >> minuto >> segundo;
		
		Instante instante (hora, minuto, segundo);
		segundos_transcurridos = instante.SegundosTotalesEnterosTranscurridos ();
		if (tipo_movimiento == ENTRADA){ 
			tunel.Entra (matricula_vehiculo, segundos_transcurridos);
		}	
		else if (tipo_movimiento == SALIDA){
			tunel.Sale (matricula_vehiculo, segundos_transcurridos);
		}
		
		cin >> tipo_movimiento;
	}
	
	for (int i = 0 ; i < tunel.TotalEntradas () ; i++){
		cout << "\n\nMatrícula: " << tunel.Matricula (i);
		if (tunel.Velocidad (i) > 0){
			cout << "\nVelocidad: " << cadena_velocidad.GetCadena (tunel.Velocidad (i));
		}
		else{
			cout << "\nVelocidad: No ha salido";
		}
   }
}

