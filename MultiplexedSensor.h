//
// Created by alvaro on 8/08/15.
//
#include "Sensor.h"
#include "MultiplexerSensor.h"

#ifndef MULTIPLEXED_SENSOR_H
#define MULTIPLEXED_SENSOR_H

class MultiplexedSensor: public Sensor {
public:
  MultiplexedSensor(unsigned int address, MultiplexerSensor *multiplexer);
  const char* getName();
  float* getValues(unsigned int quantities, unsigned int * readValues);
  const char* getType();
  static Sensor* fromConfig(void *);

private:
  void select();
  MultiplexerSensor *multiplexer_;
  unsigned int address_;
};


#endif //MULTIPLEXED_SENSOR_H
