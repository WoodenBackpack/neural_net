#include "layer.h"

#include "matrix.h"
#include "neuron.h"

Layer::Layer(const unsigned int& size) : size(size) {
  for (unsigned int i = 0; i < size; ++i) {
    Neuron* n = new Neuron(0.0);
    neurons.push_back(n);
  }
}

void Layer::setVal(const unsigned int index, double value) {
  if (index <= neurons.size()) {
    neurons.at(index)->setVal(value);
  }
}

Matrix* Layer::matrixifyValues() {
  Matrix* m = new Matrix(1, neurons.size(), false);
  const unsigned int firstCol = 0;
  for (unsigned int i = 0 ; i < neurons.size() ; ++i) {
    m->setVal(i, firstCol, neurons.at(i)->getVal());
  }
  return m;
}

Matrix* Layer::matrixifyActivatedValues() {
  Matrix* m = new Matrix(1, neurons.size(), false);
  const unsigned int firstCol = 0;
  for (unsigned int i = 0 ; i < neurons.size() ; ++i) {
    m->setVal(i, firstCol, neurons.at(i)->getActivatedVal());
  }
  return m;
}

Matrix* Layer::matrixifyDerivedValues() {
  Matrix* m = new Matrix(1, neurons.size(), false);
  const unsigned int firstCol = 0;
  for (unsigned int i = 0 ; i < neurons.size() ; ++i) {
    m->setVal(i, firstCol, neurons.at(i)->getDerivedVal());
  }
  return m;
}
