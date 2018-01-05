//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Coordenadas geográficas

#include <iostream>
#include <cmath>
using namespace std;

class CoordenadasGPS{
private:
	double longitud, latitud, altura;
	
	double Grados_A_Radianes (double grados){
		const double PI = (6.0 * asin (0.5));
		
		return grados * PI/180;
	}
	
/*	bool EsGradosCorrectos (double gr_lat, double gr_lon, double m_alt){
		Comparar con los rangos correctos
		
		return latit = MINIMO_LATITUD && latit <= MAXIMO_LATITUD && 
							 longit >= MINIMO_LONGITUD && longit <= MAXIMO_LONGITUD &&
							 alt >= MINIMO_ALTURA && alt <= MAXIMO_ALTURA;
	}
	
	double RadEn1Gr (){
		return PI / 180.0;
	}
	
	double ToRadianes (double gr){
		return gr * RadEn1Gr ();
	}
	
	double ToGrados (double rad){
		return rad / RadEn1Gr ();
	}
*/	
public:
/* CoordenadasGPS (double gr_lat, double gr_lon, double m_alt){
		SetCoordenadas (gr_lat, gr_lon, m_alt);
	}
*/
	CoordenadasGPS (){
		longitud = NAN;
		latitud = NAN;
		altura = NAN;
	}
/* void SetCoordenadas (double gr_lat, double gr_lon, double m_alt){
		if (EsGradosCorrectos(gr_lat, gr_lon, m_alt))
			Asignar datos miembro llamando a ToRadianes
	}
*/
	void SetCoordenadas (double latit, double longit, double alt){
		const int MINIMO_LATITUD = -90, MAXIMO_LATITUD = 90;
		const int MINIMO_LONGITUD = -180, MAXIMO_LONGITUD = 180;
		const int MINIMO_ALTURA = -423, MAXIMO_ALTURA = 8848;
		
		if (latit >= MINIMO_LATITUD && latit <= MAXIMO_LATITUD)
			longitud = Grados_A_Radianes (latit);
		if (longit >= MINIMO_LONGITUD && longit <= MAXIMO_LONGITUD)
			latitud = Grados_A_Radianes (longit);
		if (alt >= MINIMO_ALTURA && alt <= MAXIMO_ALTURA)
			altura = alt;
	}
	
	double GetLatitud (){
		return latitud;
	}
	
	double GetLongitud (){
		return longitud;
	}
	
	double GetAltura (){
		return altura;
	}
};

int main (){
	double latitud1, longitud1, altura1, latitud2, longitud2, altura2;
	CoordenadasGPS coordenada1, coordenada2;
	
	cout << "Introduzca la latitud, longitud y altura en el punto 1: ";
	cin >> latitud1 >> longitud1 >> altura1;
	cout << "Introduzca la latitud, longitud y altura en el punto 2: ";
	cin >> latitud2 >> longitud2 >> altura2;
	
	coordenada1.SetCoordenadas (latitud1, longitud1, altura1);
	coordenada2.SetCoordenadas (latitud2, longitud2, altura2);
	
	cout << "\nLatitud: " << coordenada1.GetLatitud ();
	cout << "\nLongitud: " << coordenada1.GetLongitud ();
	cout << "\nAltura: " << coordenada1.GetAltura ();
	cout << "\nLatitud: " << coordenada2.GetLatitud ();
	cout << "\nLongitud: " << coordenada2.GetLongitud ();
	cout << "\nAltura: " << coordenada2.GetAltura ();
}
