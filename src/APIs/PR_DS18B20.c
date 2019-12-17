/**********************************************************************/
/*    PRIMITIVAS PARA EL MANEJO DEL SENSOR DE TEMPERATURA DS18B20  */
/**********************************************************************/

/************* INCLUDES *************/
#include "PR_DS18B20.h"
/************************************/

/************ V.GLOBALES ************/
uint8_t flag_handler_low=0;
uint8_t Flag_global_esperar=0;
uint32_t temp=0;
/************************************/



//Inicializa un pin de entrada , y el otro de salida en colector abierto
//Param:  void
//Return: void
void InicializacionDS18B20(void){

	//PIN DE ENTRADA

	SetPINSEL(PUERTO_SENSOR, PIN_SENSOR_ENTRADA, 0);  //GPIO
	SetDIR(PUERTO_SENSOR, PIN_SENSOR_ENTRADA, GPIO_INPUT);
	SetPINMODE(PUERTO_SENSOR, PIN_SENSOR_ENTRADA, 2);  //lo pongo sin pull-up, ni pull-down

	//PIN DE SALIDA

	SetPINSEL(PUERTO_SENSOR, PIN_SENSOR_SALIDA, 0);  //GPIO
	SetDIR(PUERTO_SENSOR, PIN_SENSOR_SALIDA, GPIO_OUTPUT);
	SetPINMODE_OD(PUERTO_SENSOR, PIN_SENSOR_SALIDA, 1);
	SetPIN(PUERTO_SENSOR, PIN_SENSOR_SALIDA, 1);  //pongo la linea en 1

}

void RecibirTemperatura(void){

	static uint8_t estado= RESET;
	uint32_t aux;
	static uint8_t flag_vuelta=0;
	static uint8_t SkipResp=0;
	static uint8_t flag1=0;


	switch(estado){

		case RESET :

			if(Reset()==1){

				estado = ROM;
				Esperar(150);

			}


			break;


		case ROM :

			if(Flag_global_esperar==0){

			SkipResp= Comando(SKIPROM);     //manda el comando skipROM (CCh) para dirigirse a todos los esclavos.

			if(SkipResp==1 && flag_vuelta==0){  //Si mandó el comando y es la primera vuelta

				estado = FUNCION;
				flag_vuelta=1;
				SkipResp=0;
			}

			if(SkipResp==1 && flag_vuelta==1){  //Si mandó el comando y es la segunda vuelta

				estado = READSCRATCH;
				flag_vuelta=0;
				SkipResp=0;
			}

			}

			break;

		case FUNCION:

			if(Comando(CONVERT)==1){   //manda el comando ConverT (44h) para que el esclavo inicie la conversion

				estado = ESPERANDO;

			}

			break;

		case ESPERANDO:


			if(flag1==0){

				Esperar(750000);
				flag1=1;
			}

			if(Flag_global_esperar==0){

				estado= RESET;
				flag1=0;



			}

			break;

		case READSCRATCH:

			if(Comando(READSCRATCH)==1){

				estado = RECEPCION;

			}

			break;

		case RECEPCION:

			aux=Conversor();

			if(aux != 1000){


				temp=aux;
				estado = RESET;

			}

			break;

	}


}






uint8_t Reset (void){

	static uint8_t estado3=0;

	switch (estado3){

	case 0:

		if(PonerLow(550)){

			estado3=1;
		}

		break;

	case 1:

		if(Leer(70)==0){

			estado3=0;

			return 1;

		}


		break;

	}

return 0;   //retorna 0 si esta en el proceso del reset.

}




uint8_t * RecibirDatos(){

static uint8_t buffer1[16];
static uint8_t i=0,flagh=0,dato=2;
static uint8_t  false[]={100};


if(Flag_global_esperar==0){   //aca va a pasar algo raro, cuando se llame a Leer(10) va a dejar de pasar por este if, pero cuando devuelva el valor
							  // la funcion leer, va a entrar y va a recibir el dato

	if(flagh==0){

		SetPIN(PUERTO_SENSOR, PIN_SENSOR_SALIDA, 0);
		flagh=1;
		//LedsRGB(AZUL,ON);     este chequear
		SetPIN(PUERTO_SENSOR, PIN_SENSOR_SALIDA, 1);


	}

	if(flagh==1){

		dato= Leer(10);

		if(dato != 2){

			buffer1[i]=dato;
			i++;
			flagh=0;
			Esperar(60);     //no permite que entre a la funcion durante 50 micro asi termina el read slot (verificar bien los tiempos)

			if(i==15){

				i=0;
				return buffer1;    //devuelve el buffer que se que es de 2 bytes;
			}
		}


	}



}

return false;    //retorna -1 si esta laburando, 0 o 1 segun lo que haya leido


}



uint32_t Conversor(){

static uint32_t temperatura;

uint8_t * buffer= RecibirDatos();


if(buffer[0] != 100){


	temperatura = buffer[10]*64 + buffer[9]*32 + buffer[8]*16 + buffer[7]*8 + buffer[6]*4 + buffer[5]*2 + buffer[4];


	return temperatura;

}



return 1000;


}




uint8_t Comando( uint8_t comando){

static uint8_t i=0;

static uint8_t comand[8];

if(Flag_global_esperar==0){

	if(comando==SKIPROM){
		comand[0]=0;
		comand[1]=0;
		comand[2]=1;
		comand[3]=1;
		comand[4]=0;
		comand[5]=0;
		comand[6]=1;
		comand[7]=1;
	}
	if(comando==CONVERT){
		comand[0]=0;
		comand[1]=0;
		comand[2]=1;
		comand[3]=0;
		comand[4]=0;
		comand[5]=0;
		comand[6]=1;
		comand[7]=0;
	}
	if(comando==READSCRATCH){
		comand[0]=0;
		comand[1]=1;
		comand[2]=1;
		comand[3]=1;
		comand[4]=1;
		comand[5]=1;
		comand[6]=0;
		comand[7]=1;
	}

	if(comand[i]==0){
		if(PonerLow(60)){
			i++;
		}

	}

	if(comand[i]==1){

		if(PonerLow(10)){
			Esperar(52);   //espera 52 micro porque son 50 del resto del write slot (10 fueron en low), y 2 micro para el time between slots.
			i++;
		}


	}


}

if(i==8){

	i=0;
	return 1;
}

return 0;
}


uint8_t Leer(uint32_t time){

	static uint8_t flaggg=0;

	if(flaggg==0){
		Esperar(time);   			//Arranca un timer y no hace nada
		flaggg=1;
	}
	if(Flag_global_esperar==0){		//cuando termina el timer se levanta este flag y lee el estado.

		flaggg=0;
		return GetPIN(PUERTO_SENSOR, PIN_SENSOR_ENTRADA);

	}

return 2;   //un numero que no es ni 0 ni 1

}



void Esperar(uint32_t timee){

	TimerStartUs(1, Handler_Esperar , timee);
	Flag_global_esperar=1;


}

void Handler_Esperar(void){

	Flag_global_esperar=0;


}



uint8_t PonerLow(uint32_t timee){     //time (en useg) es cuanto tiempo quiero que este en low

	static uint8_t flagg=0;

	if(flagg==0){
		SetPIN(PUERTO_SENSOR, PIN_SENSOR_SALIDA, 0);  //pongo salida en 0 y dentro de "time" (useg) la suelto
		TimerStartUs(1, Handler_Low , timee);
		flagg=1;
	}
	if(flag_handler_low==1){    //este flag originalmente esta en 0, entra cuando termina el timer
		flagg=0;
		flag_handler_low=0;
		return 1;
	}


	return 0;

}

void Handler_Low(void){

	SetPIN(PUERTO_SENSOR, PIN_SENSOR_SALIDA, 1);  //pongo salida en 1 porque termino el timer
	flag_handler_low=1;


}


