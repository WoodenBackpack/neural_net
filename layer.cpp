#include "layer.h"

#include "matrix.h"
#include "neuron.h"

Layer::Layer(const unsigned int& size) : size(size) {
  for (unsigned int i = 0; i < size; ++i) {
    std::shared_ptr<Neuron> n = std::make_shared<Neuron>(0.0);
    neurons.push_back(n);
  }
}

void Layer::setValue(const unsigned int index, double value) {
  if (index <= neurons.size()) {
    neurons.at(index)->setValue(value);
  }
}

std::shared_ptr<Matrix> Layer::matrixifyValues() {
  std::shared_ptr<Matrix> m = std::make_shared<Matrix>(1, neurons.size(), false);
  const unsigned int firstCol = 0;
  for (unsigned int i = 0 ; i < neurons.size() ; ++i) {
    m->setValue(firstCol, i, neurons.at(i)->getValue());
  }
  return m;
}

std::shared_ptr<Matrix> Layer::matrixifyActivatedValues() {
  std::shared_ptr<Matrix> m = std::make_shared<Matrix>(1, neurons.size(), false);
  const unsigned int firstCol = 0;
  for (unsigned int i = 0 ; i < neurons.size() ; ++i) {
    m->setValue(firstCol, i, neurons.at(i)->getActivatedValue());
  }
  return m;
}

std::shared_ptr<Matrix> Layer::matrixifyDerivedValues() {
  std::shared_ptr<Matrix> m = std::make_unique<Matrix>(1, neurons.size(), false);
  const unsigned int firstCol = 0;
  for (unsigned int i = 0 ; i < neurons.size() ; ++i) {
    m->setValue(firstCol, i, neurons.at(i)->getDerivedValue());
  }
  return m;
}
