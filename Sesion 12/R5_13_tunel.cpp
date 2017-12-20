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
   int decimales = 2;   
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
   FormateadorDoubles (){
   }

   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha)
   {
      SetDelimitadores(delimitador_izda, delimitador_dcha);
   }

   FormateadorDoubles(string delimitador_izda,
                      string delimitador_dcha,
                      int num_decimales_a_mantener)
      :FormateadorDoubles(delimitador_izda, delimitador_dcha)
   {
      SetNumeroDecimales(num_decimales_a_mantener);
   }
   
   void SetSeparadorPunto(){
      separador = SeparadorDecimal::PUNTO;
   }
   void SetSeparadorComa(){
      separador = SeparadorDecimal::COMA;
   }


   void SetNumeroDecimales(int num_decimales_a_mantener){
      if (num_decimales_a_mantener >= 0)
         decimales = num_decimales_a_mantener;
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

   bool EsCorrecto (int hora, int minuto, int segundo){
      return  (0 <= hora    && hora < HORAS_EN_DIA  &&
               0 <= minuto  && minuto < MINUTOS_POR_HORA &&
               0 <= segundo && segundo < SEGUNDOS_POR_MINUTO);
   }

   void AniadeQuitaSegundos(int segundos_a_modificar){
      int segundos_nuevos;

      segundos_nuevos =
         SegundosTotalesEnterosTranscurridos() + segundos_a_modificar;

      SetSegundosTotalesTranscurridos(segundos_nuevos);
   }
public:
   Instante(){
   }

   Instante(int hora_instante, int minuto_instante, int segundo_instante){
      SetHoraMinutoSegundo(hora_instante,  minuto_instante,  segundo_instante);
   }

   Instante(int segundos_transcurridos){
      SetSegundosTotalesTranscurridos(segundos_transcurridos);
   }

   int Hora(){
      return hora;
   }

   int Minuto(){
      return minuto;
   }

   int Segundo(){
      return segundo;
   }

   void SetHoraMinutoSegundo(int hora_instante,
                             int minuto_instante,
                             int segundo_instante){
      if (EsCorrecto(hora_instante, minuto_instante, segundo_instante)){
         hora = hora_instante;
         minuto = minuto_instante;
         segundo = segundo_instante;
      }
   }

   void SetSegundosTotalesTranscurridos(int segundos_totales){
      int minutos_enteros;
      const int SEGUNDOS_EN_1_DIA = SEGUNDOS_POR_MINUTO
                                    * MINUTOS_POR_HORA
                                    * HORAS_EN_DIA;

      if (segundos_totales < SEGUNDOS_EN_1_DIA){
         segundo = segundos_totales % SEGUNDOS_POR_MINUTO;
         minutos_enteros  = segundos_totales / SEGUNDOS_POR_MINUTO;
         minuto  = minutos_enteros % MINUTOS_POR_HORA;
         hora    = minutos_enteros / MINUTOS_POR_HORA;
      }
   }

   void SumaleSegundos(int segundos_a_aniadir){
      if (segundos_a_aniadir > 0)
         AniadeQuitaSegundos(segundos_a_aniadir);
   }

   void RestaleSegundos(int segundos_a_quitar){
      if (segundos_a_quitar > 0)
         AniadeQuitaSegundos( - segundos_a_quitar);
   }

   bool EsNulo(){
      return !EsCorrecto(hora, minuto, segundo);
   }

   int SegundosTotalesEnterosTranscurridos(){
      return SEGUNDOS_POR_MINUTO * (hora * MINUTOS_POR_HORA + minuto)
             + segundo;
   }

   int MinutosTotalesEnterosTranscurridos(){
      return trunc(MinutosTotalesDecimalTranscurridos());
   }

   double MinutosTotalesDecimalTranscurridos(){
      return 1.0 * SegundosTotalesEnterosTranscurridos() / SEGUNDOS_POR_MINUTO;
   }

   double HorasTotalesDecimalTranscurridas(){
      return 1.0 * MinutosTotalesDecimalTranscurridos() / MINUTOS_POR_HORA;
   }

   string ToString(){
      return to_string(hora) + "h, " +
             to_string(minuto) + "\', " +
             to_string(segundo) + "\'\'";
   }

   void Sumale(Instante otro_instante){
      SumaleSegundos(otro_instante.SegundosTotalesEnterosTranscurridos());
   }
   
   void Restale(Instante otro_instante){
      RestaleSegundos(otro_instante.SegundosTotalesEnterosTranscurridos());
   }

   Instante DiferenciaCon(Instante otro_instante){
      int segundos_iniciales, segundos_finales, segundos_diferencia;

      segundos_iniciales = SegundosTotalesEnterosTranscurridos();
      segundos_finales   = otro_instante.SegundosTotalesEnterosTranscurridos();
      segundos_diferencia = abs(segundos_finales - segundos_iniciales);

      Instante diferencia_con;

      diferencia_con.SetSegundosTotalesTranscurridos(segundos_diferencia);

      return diferencia_con;
   }

   bool EsMenorQue (Instante otro_instante){
      bool es_menor;

      if (hora < otro_instante.hora)
         es_menor = true;
      else if (otro_instante.hora > hora)
         es_menor = false;
      else if (minuto < otro_instante.minuto)
         es_menor = true;
      else if (minuto > otro_instante.minuto)
         es_menor = false;
      else if (segundo < otro_instante.segundo)
         es_menor = true;
      else
         es_menor = false;

      return es_menor;
   }
};

class VehiculoTunel{
private:
   string   matricula;
   Instante entrada;
   Instante salida;

   bool EsCorrectaMatricula(string matricula_vehiculo){
      return matricula_vehiculo.size() <= 8;
   }

public:
   VehiculoTunel(){
   }

   VehiculoTunel(string matricula_vehiculo,
                Instante entrada_vehiculo,
                Instante salida_vehiculo){
      SetMatricula(matricula_vehiculo);
      SetInstanteEntrada(entrada_vehiculo);
      SetInstanteSalida(salida_vehiculo);
   }

   string Matricula(){
      return matricula;
   }

   Instante InstanteEntrada(){
      return entrada;
   }

   Instante InstanteSalida(){
      return salida;
   }

   void SetMatricula(string matricula_vehiculo){
      if (EsCorrectaMatricula(matricula_vehiculo))
         matricula = matricula_vehiculo;
   }

   void SetInstanteEntrada(Instante entrada_vehiculo){
      entrada = entrada_vehiculo;
   }

   void SetInstanteSalida(Instante salida_vehiculo){
      salida = salida_vehiculo;
   }
};

class Tunel{
private:
	double distancia_km;

   static const int MAX_NUM_VEHICULOS = 100;
   VehiculoTunel vehiculos[MAX_NUM_VEHICULOS];

   int total_entradas = 0;

   bool EsCorrectoIndice(int indice){
      return 0 <= indice && indice < total_entradas;
   }
public:
	Tunel(double distancia_km_tunel){
      distancia_km = distancia_km_tunel;
   }

   int TotalEntradas(){
      return total_entradas;
   }
	
   int Indice(string matricula){
      int indice;
      bool no_encontrado = true;

      for (int i = 0 ; i < total_entradas && no_encontrado ; i++){
         if(vehiculos[i].Matricula() == matricula){
            indice = i;
            no_encontrado = false;
         }
         else{
            indice = -1;
         }
      }

      return indice;
   }
   
   VehiculoTunel Vehiculo(int indice){
      return vehiculos[indice];
   }

   void Entra (string matricula, Instante instante_entrada){
      VehiculoTunel vehiculo;
      
      vehiculo.SetMatricula(matricula);
      vehiculo.SetInstanteEntrada(instante_entrada);

      vehiculos[total_entradas] = vehiculo;	
      total_entradas++;	
	}
	
	void Sale (string matricula, Instante instante_salida){
      int indice;

      indice = Indice(matricula);
      cout << "\nIndice: " << indice;
      vehiculos[indice].SetInstanteSalida(instante_salida);
      cout << "\npito2: " << distancia_km;
	}

   bool HaSalido(int indice){
      Instante instante_salida;
      instante_salida = vehiculos[indice].InstanteSalida();

      return !instante_salida.EsNulo();
   }
	
	double Velocidad (int indice){
      Instante instante_entrada, instante_salida, diferencia;
      double velocidad;

      instante_entrada = vehiculos[indice].InstanteEntrada();
      instante_salida = vehiculos[indice].InstanteSalida();
      diferencia = instante_entrada.DiferenciaCon(instante_salida);
      cout << "Min: " << diferencia.Minuto();
      cout << "Sec: " << diferencia.Segundo();

      velocidad = distancia_km / diferencia.HorasTotalesDecimalTranscurridas();
      cout << "\nHoras: " << diferencia.HorasTotalesDecimalTranscurridas();

      return velocidad;
   }
};


int main(){
   const char FIN_ENTRADA_FICHERO = '#';
   const char ENTRADA = 'E';
   const char SALIDA  = 'S';
   double long_tunel;
   char tipo_entrada_salida;

   string matricula;
   int hora, min, seg;
   
   FormateadorDoubles formateador_velocidad("", " km/h");
   formateador_velocidad.SetNumeroDecimales(1);

   cout << "Introduzca la longitud del tunel: ";
   cin >> long_tunel;

   Tunel tunel(long_tunel);

   cin >> tipo_entrada_salida;

   while (tipo_entrada_salida != FIN_ENTRADA_FICHERO){
      cin >> matricula;
      cin >> hora >> min >> seg;
      
      Instante instante(hora, min, seg);

      if (tipo_entrada_salida == ENTRADA)
         tunel.Entra(matricula, instante);
      else if (tipo_entrada_salida == SALIDA)
         tunel.Sale(matricula, instante);

      cin >> tipo_entrada_salida;
   }

   string cadena= "\n";

   for (int i = 0 ; i < tunel.TotalEntradas() ; i++){
      cadena = cadena +
               "\n\nMatrícula:\t" + tunel.Vehiculo(i).Matricula() +
               "\nVelocidad:\t";

      string texto_salida;

      if (! tunel.HaSalido(i))
         texto_salida = "No ha salido";
      else
         texto_salida = formateador_velocidad.GetCadena(tunel.Velocidad(i));

      cadena = cadena + texto_salida + "\n";
   }

   cout << cadena;
}