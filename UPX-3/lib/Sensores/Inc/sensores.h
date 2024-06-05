#ifndef SENSORES_H
#define SENSORES_H

#include "math.h"
#include <stdint.h>



typedef struct
{
	double iRms;
	double vRms;
	double pVA;
}data_calcule_t;


void calcIrms(data_calcule_t *calcule, unsigned int samples, double iCal, uint16_t data[512]);

void calcVrms(data_calcule_t *calcule, unsigned int samples, uint16_t data[512]);


#endif
