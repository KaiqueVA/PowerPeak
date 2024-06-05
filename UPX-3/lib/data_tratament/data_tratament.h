#ifndef DATA_TRATAMENT_H
#define DATA_TRATAMENT_H

#include "sensores.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "stm32f4xx_hal.h"


void data_processing(data_calcule_t *calcule, char **p_data, uint8_t *tam);


#endif
