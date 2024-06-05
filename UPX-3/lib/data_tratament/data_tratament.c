#include "data_tratament.h"




void data_processing(data_calcule_t *calcule, char **p_data, uint8_t *tam)
{

	*tam = snprintf(NULL, 0, "{\"V\": %.2f, \"A\": %.2f, \"PVA\": %.2f}\n",
					calcule->vRms, calcule->iRms, calcule->pVA) + 1;


	*p_data = (char *)malloc(*tam * sizeof(char));


	if (*p_data == NULL) {
		return;
	}

	snprintf(*p_data, *tam, "{\"V\": %.2f, \"A\": %.2f, \"PVA\": %.2f}\n",
			calcule->vRms, calcule->iRms, calcule->pVA);
}
