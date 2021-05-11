/*
 * RainDetector.h
 *
 *      Author: reedt
 */

#ifndef SRC_RAINDETECTOR_H_
#define SRC_RAINDETECTOR_H_

#include "main.h"
#include <cstdint>

class RainDetector
{
private:
	ADC_HandleTypeDef * rainADC = nullptr;

public:
	RainDetector(ADC_HandleTypeDef * adc);
	virtual ~RainDetector();
	RainDetector(const RainDetector &other) = default;
	RainDetector(RainDetector &&other) = default;
	RainDetector& operator=(const RainDetector &other) = default;
	RainDetector& operator=(RainDetector &&other) = default;

	uint8_t getLevel();
};

#endif /* SRC_RAINDETECTOR_H_ */
