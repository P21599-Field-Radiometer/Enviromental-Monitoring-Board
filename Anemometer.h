/*
 * Anemometer.h
 *
 *      Author: reedt
 */

#ifndef SRC_ANEMOMETER_H_
#define SRC_ANEMOMETER_H_

#include <cstdint>
#include "main.h"



class Anemometer {
private:
	uint64_t startCount = 0;
	uint64_t startTick = 0;

	ADC_HandleTypeDef * directionADC = nullptr;




public:
	Anemometer(ADC_HandleTypeDef * adc);
	virtual ~Anemometer();
	Anemometer(const Anemometer &other) = default;
	Anemometer(Anemometer &&other) = default;
	Anemometer& operator=(const Anemometer &other) = default;
	Anemometer& operator=(Anemometer &&other) = default;

	uint8_t getSpeed();

	uint8_t getDirection();


};

#endif /* SRC_ANEMOMETER_H_ */
