//#include "Ataque.h"
//
//Ataque::Ataque(){}
//
//
//float Ataque::atacar(GameObject &atacado, Arma &arma, float nivel){
//	StatsJuego stats;
//	Defensa defensa;
//	float danio = Ecuacion::danio(stats.fuerza, arma.getDanioMin(), arma.getDanioMax());
//	float danioFinal = defensa.getDanioConDefensa(atacado, danio);
//	//std::cout << "danio" << danio << "DF " << danioFinal << '\n';
//
//	atacado.estado.restarVida(danioFinal);
//	float experiencia = Ecuacion::experiencia(danio, atacado.estado.getNivel(), nivel);
//	if (!atacado.estado.sigueVivo()) {
//		atacado.estado.setearAMuerto();
//		experiencia += Ecuacion::experienciaAdicional(atacado.estado.getConstitucion(),
//					   atacado.estado.getFClaseVida(), atacado.estado.getFRazaVida(),
//					   atacado.estado.getNivel(), nivel);
//	}
//	return experiencia;
//}
//Ataque::~Ataque(){}