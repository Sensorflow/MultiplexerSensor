//
// Created by alvaro on 8/08/15.
//

#include "MultiplexedSensor.h"
#include "MultiplexerSensor.h"

MultiplexedSensor::MultiplexedSensor(unsigned int address, MultiplexerSensor *multiplexer){
  multiplexer_ = multiplexer;
  address_ = address;
}

void MultiplexedSensor::select(){
  multiplexer_->setAddress(address_);
}
const char * MultiplexedSensor::getName(){
  select();
  return multiplexer_->getName();
}

const char * MultiplexedSensor::getType(){
  select();
  return multiplexer_->getType();
}

float * MultiplexedSensor::getValues(unsigned int quantities, unsigned int * readValues){
  select();
  return multiplexer_->getValues(quantities, readValues);
}

Sensor * MultiplexedSensor::fromConfig(void *data){
  int a;
  MultiplexerSensor *s = new MultiplexerSensor(1,1,&a);
  return (Sensor *)s;

}
