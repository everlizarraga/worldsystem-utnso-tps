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
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include <sys/socket.h>
#include <arpa/inet.h> // Agregado de Video

//Variables
t_log *logger;
t_config *config;
char* ip_mi_ram_hq;
char* puerto_mi_ram_hq;

int socket_servidor;
int socket_cliente;


//Funcioens
t_log* crearLogger();
t_config* crearConfig();
void setearValoresConfig();



#endif /* MI_RAM_HQ_H_ */
