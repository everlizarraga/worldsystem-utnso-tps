/*
 ============================================================================
 Name        : discordiador.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "discordiador.h"

int main(void) {
	puts("!!!Discordiador:"); /* prints !!!Hello World!!! */

	logger = crearLogger();
	config = crearConfig();
	setearValoresConfig();

	log_info(logger,"Discordiador: Logger Iniciado y creado");
	log_info(logger,"IP: %s",ip_doscordiador);
	log_info(logger,"PUERTO: %s",puerto_discordiador);


	log_destroy(logger);
	config_destroy(config);

	return EXIT_SUCCESS;
}

t_log *crearLogger(){
	return log_create("discordiador.log","Discordiador",1,LOG_LEVEL_INFO);
}

t_config *crearConfig(){
	return config_create("discordiador.config");
}

void setearValoresConfig(){
	ip_doscordiador = config_get_string_value(config,"IP_DISCORDIADOR");
	puerto_discordiador = config_get_string_value(config,"PUERTO_DISCORDIADOR");
}



