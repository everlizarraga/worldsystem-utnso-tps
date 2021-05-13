/*
 * mi-ram-hq.h
 *
 *  Created on: 12 may. 2021
 *      Author: utnso
 */

#ifndef MI_RAM_HQ_H_
#define MI_RAM_HQ_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#include <commons/log.h>
#include <commons/string.h>
#include <commons/config.h>
#include <commons/string.h>
#include <readline/readline.h>
#include <string.h>


//#include <arpa/inet.h> // Agregado de Video

//Variables
t_log *logger;
t_config *config;
char* ip_mi_ram_hq;
char* puerto_mi_ram_hq;

int socketServidor;
int socketCliente;


//Funcioens
t_log* crearLogger();
t_config* crearConfig();
void setearValoresConfig();
int iniciar_servidor(char *, char *);
int esperar_cliente(int);



#endif /* MI_RAM_HQ_H_ */
