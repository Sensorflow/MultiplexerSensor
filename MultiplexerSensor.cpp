//
// Created by alvaro on 8/08/15.
//

#include "MultiplexerSensor.h"
#include "Multiplexer.h"

#include <Arduino.h>
MultiplexerSensor::MultiplexerSensor(int dataPin, int nLines, int linePins[]){
  multiplexer_ = new Multiplexer(dataPin, nLines, linePins);
  sensors_.reserve(nLines);
}

void MultiplexerSensor::setAddress(unsigned int address){
  multiplexer_->setAddress(address);
  address_ = address;
}

const char * MultiplexerSensor::getName(){
  return sensors_[address_]->getName();
}

bool MultiplexerSensor::setSensor(unsigned int address, Sensor *s){
  //unsigned int maxLines = multiplexer_->getNLines();
  //if(address <= maxLines){
      sensors_[address] = s;
      return true;
  //}

  return false;
}

const char * MultiplexerSensor::getType(){
    return sensors_[address_]->getType();
}


float * MultiplexerSensor::getValues(unsigned int quantities, unsigned int * readValues){
  return sensors_[address_]->getValues(quantities, readValues);
}

Sensor * MultiplexerSensor::fromConfig(void *data){

  MultiplexerSensor *s = new MultiplexerSensor(1,1,1);
  return (Sensor *)s;

}
