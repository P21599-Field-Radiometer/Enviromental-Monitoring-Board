/*
 * Anemometer.cpp
 *
 *      Author: Reed Terdal
 */

#include "Anemometer.h"

extern uint64_t irqCount;
extern uint64_t ticks;

Anemometer::Anemometer(ADC_HandleTypeDef *adc)
{
	this->directionADC = adc;
	this->startCount = irqCount;
	this->startTick = ticks;
	HAL_ADC_Start(this->directionADC);
}

Anemometer::~Anemometer()
{
	HAL_ADC_Stop(this->directionADC);
}

uint8_t Anemometer::getSpeed()
{
	uint64_t elapsedTicks = ticks - this->startTick;
	uint64_t totalIRQ = irqCount - this->startCount;

	this->startTick = ticks;
	this->startCount = irqCount;
	return totalIRQ * (2.25 / (elapsedTicks / 1000.0));
}

uint8_t Anemometer::getDirection()
{
	HAL_ADC_Start(this->directionADC);
	return HAL_ADC_GetValue(this->directionADC);
}
