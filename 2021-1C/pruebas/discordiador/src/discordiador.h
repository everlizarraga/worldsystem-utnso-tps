/*
 * discordiador.h
 *
 *  Created on: 12 may. 2021
 *      Author: utnso
 */

#ifndef DISCORDIADOR_H_
#define DISCORDIADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>
#include <commons/string.h>
#include <commons/config.h>
#include <readline/readline.h>

#include <sys/socket.h>
#include <arpa/inet.h> // Agregado de Video

//Variables:
t_log *logger;
t_config *config;
char* ip_doscordiador;
char* puerto_discordiador;


//Funciones:

t_log* crearLogger();
t_config* crearConfig();
void setearValoresConfig();



#endif /* DISCORDIADOR_H_ */
