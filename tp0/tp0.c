/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();
	log_info(logger,"Soy un log !!!!!!");

	//Loggear "soy un log"

	config = leer_config();
	valor = config_get_string_value(config,"CLAVE");
	log_info(logger,valor);

	//asignar valor de config a la variable valor

	//Loggear valor de config

	leer_consola(logger);




	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	//crear conexion
	ip = config_get_string_value(config,"IP");
	puerto = config_get_string_value(config,"PUERTO");
	conexion = crear_conexion(ip,puerto);

	//enviar CLAVE al servirdor

	//enviar_mensaje(valor,conexion);

	paquete(conexion);

	terminar_programa(conexion, logger, config);

}

t_log* iniciar_logger(void)
{
	return log_create("tp0.log","LogTP0",1,LOG_LEVEL_INFO);
}

t_config* leer_config(void)
{
	return config_create("tp0.config");
}

void leer_consola(t_log* logger)
{
	void soloLoggear(char *leido){
		log_info(logger,leido);
	}
	printf("========== Solo LOG ==============\n");
	_leer_consola_haciendo((void*)soloLoggear);
}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido;
	t_paquete* paquete = crear_paquete();

	void llenarPaquete(char* valor){
		agregar_a_paquete(paquete,valor,strlen(valor)+1);
	}
	printf("\n========== Llenando paquete ===========\n");
	_leer_consola_haciendo((void*) llenarPaquete);
	enviar_paquete(paquete,conexion);
	eliminar_paquete(paquete);
}

void _leer_consola_haciendo(void(*hacerAlgo)(char*)){
	char *valorIngresado = readline("> ");
	while(strcmp(valorIngresado,"") != 0){
		hacerAlgo(valorIngresado);
		free(valorIngresado);
		valorIngresado = readline("> ");
	}
	free(valorIngresado);
}



void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	log_destroy(logger);
	config_destroy(config);
	liberar_conexion(conexion);
}
