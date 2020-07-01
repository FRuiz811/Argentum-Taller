#ifndef STATSJUEGO_H
#define STATSJUEGO_H

#include <map>
class StatsJuego{
private: 
	//Razas
	//Humano 
	float constitucionHumano;
	float inteligenciaHumano;
	float agilidadHumano;
	float fRazaRecuperacionHumano ; //6
	float fRazaVidaHumano;
	float fRazaManaHumano;
	//Elfos 
	float constitucionElfos;
	float inteligenciaElfos;
	float agilidadElfos;
	float fRazaRecuperacionElfos;
	float fRazaVidaElfos;
	float fRazaManaElfos;
	//Enanos
	float constitucionEnanos;
	float inteligenciaEnanos;
	float agilidadEnanos;
	float fRazaRecuperacionEnanos;
	float fRazaVidaEnanos;
	float fRazaManaEnanos;
	//Gnomos
	float constitucionGnomos;
	float inteligenciaGnomos;
	float agilidadGnomos;
	float fRazaRecuperacionGnomos;
	float fRazaVidaGnomos;
	float fRazaManaGnomos;

	//Clses
	//Mago 
	float constitucionMago;
	float inteligenciaMago;
	float agilidadMago;
	float fClaseRecuperacionMago; //4
	float fClaseVidaMago;
	float fClaseManaMago;
	float fClaseMeditacionMago;
	//Clerigo 
	float constitucionClerigo;
	float inteligenciaClerigo;
	float agilidadClerigo;
	float fClaseRecuperacionClerigo;
	float fClaseVidaClerigo;
	float fClaseManaClerigo;
	float fClaseMeditacionClerigo;
	//Paladin 
	float constitucionPaladin;
	float inteligenciaPaladin;
	float agilidadPaladin;
	float fClaseRecuperacionPaladin;
	float fClaseVidaPaladin;
	float fClaseManaPaladin;
	float fClaseMeditacionPaladin;
	//Guerrero 
	float constitucionGuerrero;
	float inteligenciaGuerrero;
	float agilidadGuerrero;
	float fClaseRecuperacionGuerrero;
	float fClaseVidaGuerrero;
	float fClaseManaGuerrero;
	float fClaseMeditacionGuerrero; 

public: 
	float experiencia;
	float fuerza;

	//Oro
	float oroRandMin;
	float oroRandMax;
	float oroMaxMult;
	float oroMaxPot;

	//Inventario
	int limiteInventario;

	//Experiencia
	float ptoExperienciaMult;
	float ptoExperienciaPot;
	int experienciaMaxSuma;
	int experienciaMaxMax;
	float experienciaRandMin;
	float experienciaRandMax;

	//Esquivar
	float esquivarRandMin;
	float esquivarRandMax;
	float esquivarLimite;

	//Nivel
	float nivelNewbie;
	float nivelDiferenciaMax;

	//Items
	float espadaDanioMin;
	float espadaDanioMax;
	float hachaDanioMin;
	float hachaDanioMax;
	float martilloDanioMin;
	float martilloDanioMax;
	float varaDanioMin;
	float varaDanioMax;
	float varaConsumision;
	float flautaConsumision;
	float bNudosoDanioMin;
	float bNudosoDanioMax;
	float bNudosoConsumision;
	float bEngarzadoDanioMin;
	float bEngarzadoDanioMax;
	float bEngarzadoConsumision;
	float aSimpleDanioMin;
	float aSimpleDanioMax;
	float aCompuestoDanioMin;
	float aCompuestoDanioMax;
	float aCueroDefensaMin;
	float aCueroDefensaMax;
	float aPlacaDefensaMin;
	float aPlacaDefensaMax;
	float tunicaDefensaMin;
	float tunicaDefensaMax;
	float capuchaDefensaMin;
	float capuchaDefensaMax;
	float cascoDefensaMin; 
	float cascoDefensaMax;
	float eTortugaDefensaMin;
	float eTortugaDefensaMax;
	float eHierroDefensaMin;
	float eHierroDefensaMax;
	float sombreroDefensaMin;
	float sombreroDefensaMax;

	//Criaturas o NPCServer
	float probabilidadNada;
	float probabilidadOro;
	float probabilidadVidaOMana;
	float probabilidadOtroObjeto;
	float vidaCriatura;
	float fuerzaCriatura;
	float datosCriatura;

	//Razas
	std::map<int, float> constitucionRaza;
	std::map<int, float> inteligenciaRaza;
	std::map<int, float> agilidadRaza;
	std::map<int, float> fRazaRecuperacion;
	std::map<int, float> fRazaVida;
	std::map<int, float> fRazaMana;	

	//Clases
	std::map<int, float> constitucionClase;
	std::map<int, float> inteligenciaClase;
	std::map<int, float> agilidadClase;
	std::map<int, float> fClaseRecuperacion;
	std::map<int, float> fClaseVida;
	std::map<int, float> fClaseMana;
	std::map<int, float> fClaseMeditacion;

	
	StatsJuego();

	~StatsJuego();
};

#endif
