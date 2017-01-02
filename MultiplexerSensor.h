//
// Created by alvaro on 8/08/15.
//
#include "Sensor.h"
#include "Multiplexer.h"
#include <vector>

#ifndef MULTIPLEXER_SENSOR_H
#define MULTIPLEXER_SENSOR_H

class MultiplexerSensor: public Sensor {
public:
  MultiplexerSensor(int dataPin, int nLines, int linePins[]);
  bool setSensor(unsigned int address, Sensor *s);
  const char* getName();
  float* getValues(unsigned int quantities, unsigned int * readValues);
  const char* getType();
  static Sensor* fromConfig(void *);
  void setAddress(unsigned int address);

private:
  std::vector<Sensor*> sensors_;
  MultiplexerSensor *sensor_;
  Multiplexer *multiplexer_;
  unsigned int address_;
};


#endif //MULTIPLEXER_SENSOR_H
