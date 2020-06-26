#include "StatsJuego.h"

StatsJuego::StatsJuego(){
	experiencia = 10;
	fuerza = 2;

	//Oro
	oroRandMin = 0;
	oroRandMax = 0.2;
	oroMaxMult = 100;
	oroMaxPot = 1.1;

	//Inventario
	limiteInventario = 10;

	//Experiencia
	ptoExperienciaMult = 1000;
	ptoExperienciaPot = 1.8;
	experienciaMaxSuma = 10;
	experienciaMaxMax = 0;
	experienciaRandMin = 0;
	experienciaRandMax = 0.1;

	//Esquivar
	esquivarRandMin = 0;
	esquivarRandMax = 1;
	esquivarLimite = 0.001;

	//Nivel
	nivelNewbie = 12;
	nivelDiferenciaMax = 10;

	//Items
	espadaDanioMin = 2;
	espadaDanioMax = 5;
	hachaDanioMin = 4;
	hachaDanioMax = 5;
	martilloDanioMin = 1;
	martilloDanioMax = 9;
	varaDanioMin = 2;
	varaDanioMax = 4;
	varaConsumision = 5;
	flautaConsumision = 100;
	bNudosoDanioMin = 4;
	bNudosoDanioMax = 8;
	bNudosoConsumision = 15;
	bEngarzadoDanioMin = 8;
	bEngarzadoDanioMax = 20;
	bEngarzadoConsumision = 30;
	aSimpleDanioMin = 1;
	aSimpleDanioMax = 4;
	aCompuestoDanioMin = 4;
	aCompuestoDanioMax = 16;
	aCueroDefensaMin = 2;
	aCueroDefensaMax = 6;
	aPlacaDefensaMin = 15;
	aPlacaDefensaMax = 30;
	tunicaDefensaMin = 6;
	tunicaDefensaMax = 10;
	capuchaDefensaMin = 1;
	capuchaDefensaMax = 4;
	cascoDefensaMin = 4; 
	cascoDefensaMax = 8;
	eTortugaDefensaMin = 1;
	eTortugaDefensaMax = 2;
	eHierroDefensaMin = 1;
	eHierroDefensaMax = 4;
	sombreroDefensaMin = 4;
	sombreroDefensaMax = 12;

	//Criaturas o NPCServer
	probabilidadNada = 0.8;
	probabilidadOro = 0.08;
	probabilidadVidaOMana = 0.1;
	probabilidadOtroObjeto = 0.1;
	datosCriatura = 0;
	vidaCriatura = 3;
	fuerzaCriatura = 3;

	//Razas
	//Humano 
	constitucionHumano = 1;
	inteligenciaHumano = 1;
	agilidadHumano = 1;
	fRazaRecuperacionHumano = 2; //6
	fRazaVidaHumano = 2;
	fRazaManaHumano = 2;
	//Elfos 
	constitucionElfos = 0.4;
	inteligenciaElfos = 1.3;
	agilidadElfos = 1.3;
	fRazaRecuperacionElfos = 2.4;
	fRazaVidaElfos = 1.2;
	fRazaManaElfos = 2.4;
	//Enanos
	constitucionEnanos = 1.3;
	inteligenciaEnanos = 1.3;
	agilidadEnanos = 0.4;
	fRazaRecuperacionEnanos = 1.5;
	fRazaVidaEnanos = 3;
	fRazaManaEnanos = 1.5;
	//Gnomos
	constitucionGnomos = 1.45;
	inteligenciaGnomos = 1.45;
	agilidadGnomos = 0.1;
	fRazaRecuperacionGnomos = 1.6;
	fRazaVidaGnomos = 3;
	fRazaManaGnomos = 1.4;

	this->constitucionRaza[0] =constitucionHumano ;
	this->inteligenciaRaza[0] =inteligenciaHumano ;
	this->agilidadRaza[0] = agilidadHumano;	
	this->constitucionRaza[1] =constitucionElfos ;
	this->inteligenciaRaza[1] =inteligenciaElfos ;
	this->agilidadRaza[1] = agilidadElfos;	
	this->constitucionRaza[2] =constitucionEnanos ;
	this->inteligenciaRaza[2] =inteligenciaEnanos ;
	this->agilidadRaza[2] = agilidadEnanos;	
	this->constitucionRaza[3] =constitucionGnomos ;
	this->inteligenciaRaza[3] =inteligenciaGnomos ;
	this->agilidadRaza[3] = agilidadGnomos;	

	this->fRazaRecuperacion[0] = fRazaRecuperacionHumano;
	this->fRazaVida[0] = fRazaVidaHumano;
	this->fRazaMana[0] = fRazaManaHumano;	
	this->fRazaRecuperacion[1] = fRazaRecuperacionElfos;
	this->fRazaVida[1] = fRazaVidaElfos;
	this->fRazaMana[1] = fRazaManaElfos;	
	this->fRazaRecuperacion[2] = fRazaRecuperacionEnanos;
	this->fRazaVida[2] = fRazaVidaEnanos;
	this->fRazaMana[2] = fRazaManaEnanos;	
	this->fRazaRecuperacion[3] = fRazaRecuperacionGnomos;
	this->fRazaVida[3] = fRazaVidaGnomos;
	this->fRazaMana[3] = fRazaManaGnomos;	

	//Clses
	//Mago 
	constitucionMago = 0.8;
	inteligenciaMago = 1.8;
	agilidadMago = 0.4;
	fClaseRecuperacionMago = 0.5; //4
	fClaseVidaMago = 1.5;
	fClaseManaMago = 1.5;
	fClaseMeditacionMago = 0.5; 
	//Clerigo 
	constitucionClerigo = 0.5;
	inteligenciaClerigo = 1.0;
	agilidadClerigo = 1.5;
	fClaseRecuperacionClerigo = 1;
	fClaseVidaClerigo = 1;
	fClaseManaClerigo = 1;
	fClaseMeditacionClerigo = 1; 
	//Paladin 
	constitucionPaladin = 1.25;
	inteligenciaPaladin = 0.5;
	agilidadPaladin = 1.25;
	fClaseRecuperacionPaladin = 0.6;
	fClaseVidaPaladin = 1.4;
	fClaseManaPaladin = 0.8;
	fClaseMeditacionPaladin = 1.2; 
	//Guerrero 
	constitucionGuerrero = 1.4;
	inteligenciaGuerrero = 0.2;
	agilidadGuerrero = 1.4;
	fClaseRecuperacionGuerrero = 2;
	fClaseVidaGuerrero = 2;
	fClaseManaGuerrero = 0;
	fClaseMeditacionGuerrero = 0; 

	this->constitucionClase[0] = constitucionMago;
	this->inteligenciaClase[0] = inteligenciaMago;	
	this->agilidadClase[0] = agilidadMago;
	this->constitucionClase[1] = constitucionClerigo;
	this->inteligenciaClase[1] = inteligenciaClerigo;	
	this->agilidadClase[1] = agilidadClerigo;
	this->constitucionClase[2] = constitucionPaladin;
	this->inteligenciaClase[2] = inteligenciaPaladin;	
	this->agilidadClase[2] = agilidadPaladin;
	this->constitucionClase[3] = constitucionGuerrero;
	this->inteligenciaClase[3] = inteligenciaGuerrero;	
	this->agilidadClase[3] = agilidadGuerrero;

	this->fClaseRecuperacion[0] = fClaseRecuperacionMago;
	this->fClaseVida[0] = fClaseVidaMago;
	this->fClaseMana[0] = fClaseManaMago;	
	this->fClaseMeditacion[0] = fClaseMeditacionMago;
	this->fClaseRecuperacion[1] = fClaseRecuperacionClerigo;
	this->fClaseVida[1] = fClaseVidaClerigo;
	this->fClaseMana[1] = fClaseManaClerigo;	
	this->fClaseMeditacion[1] = fClaseMeditacionClerigo;
	this->fClaseRecuperacion[2] = fClaseRecuperacionPaladin;
	this->fClaseVida[2] = fClaseVidaPaladin;
	this->fClaseMana[2] = fClaseManaPaladin;	
	this->fClaseMeditacion[2] = fClaseMeditacionPaladin;
	this->fClaseRecuperacion[3] = fClaseRecuperacionGuerrero;
	this->fClaseVida[3] = fClaseVidaGuerrero;
	this->fClaseMana[3] = fClaseManaGuerrero;	
	this->fClaseMeditacion[3] = fClaseMeditacionGuerrero;

}


StatsJuego::~StatsJuego(){}
