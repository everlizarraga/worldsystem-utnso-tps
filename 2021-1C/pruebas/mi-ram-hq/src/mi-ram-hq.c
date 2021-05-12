/*
 ============================================================================
 Name        : mi-ram-hq.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "mi-ram-hq.h"

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	logger = crearLogger();
	config = crearConfig();
	setearValoresConfig();

	log_info(logger,"IP-mi-ram-hq: %s",ip_mi_ram_hq);
	log_info(logger,"PUERTO-mi-ram-hq: %s",puerto_mi_ram_hq);




	return EXIT_SUCCESS;
}

t_log* crearLogger(){
	return log_create("mi-ram-hq.log","Mi-RAM-HQ",1,LOG_LEVEL_INFO);
}

t_config* crearConfig(){
	return config_create("mi-ram-hq.config");
}

void setearValoresConfig(){
	ip_mi_ram_hq = config_get_string_value(config,"IP_MI_RAM_HQ");
	puerto_mi_ram_hq = config_get_string_value(config,"PUERTO_MI_RAM_HQ");
}

