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
	puts("!!MI RAM HQ\n"); /* prints !!!Hello World!!! */

	logger = crearLogger();
	config = crearConfig();
	setearValoresConfig();

	log_info(logger,"IP-mi-ram-hq: %s",ip_mi_ram_hq);
	log_info(logger,"PUERTO-mi-ram-hq: %s",puerto_mi_ram_hq);

	//socketServidor = iniciar_servidor(ip_mi_ram_hq, puerto_mi_ram_hq);

	log_info(logger,"Listo recibir conexiones !!!!");
	/*
	while(1){
		printf("Entra al while\n");
		//int socketXd = esperar_cliente(socketServidor);

	}
	*/
	//printf("Sale del While\n");

	log_destroy(logger);
	config_destroy(config);

	return 0;
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

int iniciar_servidor(char* ip, char* puerto){
	int socket_servidor;

	struct addrinfo hints, *servinfo, *p;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(ip, puerto, &hints, &servinfo);

	for (p=servinfo; p != NULL; p = p->ai_next)
	{
		if ((socket_servidor = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
	        continue;

	    if (bind(socket_servidor, p->ai_addr, p->ai_addrlen) == -1) {
	    	close(socket_servidor);
	        continue;
	    }
	    break;
	}

	listen(socket_servidor, SOMAXCONN);

	freeaddrinfo(servinfo);

	log_trace(logger, "Listo para escuchar!!!");

	return socket_servidor;
}
/*
int esperar_cliente(int socket_servidor){
	printf("Ingreso a la funcio esperar_cliente");
	struct sockaddr_in dir_cliente;
	int tam_direccion = sizeof(struct sockaddr_in);
	int socket_cliente = accept(socket_servidor, (void*) &dir_cliente, &tam_direccion);
	log_info(logger, "Se conecto un proceso");
	return socket_cliente;
}

*/

