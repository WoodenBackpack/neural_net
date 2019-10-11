#include "neuron.h"

#include <math.h>

Neuron::Neuron(const double& initVal): val(initVal) {
  activate();
  derive();
}

void Neuron::setVal(const double& newVal) {
  val = newVal;
}

void Neuron::activate() {
  activatedVal = val / (1 + fabs(val));
}

void Neuron::derive() {
  derivedVal = activatedVal * (1 - activatedVal);
}
