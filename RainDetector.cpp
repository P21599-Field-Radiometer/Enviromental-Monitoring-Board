/*
 * RainDetector.cpp
 *
 *      Author: reedt
 */

#include "RainDetector.h"

RainDetector::RainDetector(ADC_HandleTypeDef * adc)
{
	this->rainADC = adc;
	HAL_ADC_Start(this->rainADC);
}

RainDetector::~RainDetector()
{
	// TODO Auto-generated destructor stub
}

uint8_t RainDetector::getLevel()
{
	HAL_ADC_Start(this->rainADC);
	return HAL_ADC_GetValue(this->rainADC);
}
