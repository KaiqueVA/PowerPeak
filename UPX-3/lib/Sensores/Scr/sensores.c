#include "sensores.h"

#define ADC_BITS 12
#define ADC_COUNTS (1<<ADC_BITS)
#define SUPPLY_VOLTAGE 3300
#define CAL 111.6
#define OFFSET 2.52


void calcIrms(data_calcule_t *calcule, unsigned int samples, double iCal, uint16_t data[512])
{
	uint16_t n, sampleI;
	double offsetI = ADC_COUNTS >> 1;
	double filteredI = 0, sumI = 0, sqI, iRatio;

	for(n = 0; n < samples; n++)
	{
		sampleI = data[n];
		offsetI = (offsetI + (sampleI-offsetI) / ADC_COUNTS);

		filteredI = sampleI - offsetI;

		sqI = filteredI * filteredI;

		sumI += sqI;
	}

	iRatio = iCal * ((SUPPLY_VOLTAGE / 1000.0) / (ADC_COUNTS));
	calcule->iRms = (iRatio * sqrt(sumI / samples));

	sumI = 0;
}

void calcVrms(data_calcule_t *calcule, unsigned int samples, uint16_t data[512])
{
	float voltageData[512];
	float integral = 0;
	int i;

	for(i=0; i<samples; i++)
	{
	 voltageData[i] = (((data[i]) * (3.3/4095.0)) - OFFSET) * CAL;
	 integral += (voltageData[i] * voltageData[i]);
	}

	integral = integral / samples;
	calcule->vRms = sqrt(integral);
}
