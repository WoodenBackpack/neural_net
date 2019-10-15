#include "neuralNetwork.h"

#include <iostream>
#include <exception>

#include "layer.h"
#include "neuron.h"
#include "utils.cpp"

class WrongExpectedError : public std::exception {
public:
  virtual const char* what() const throw() {
    return "Wrong size of expected can't calulcate error!\n";
  }
};


NeuralNetwork::NeuralNetwork(std::vector<unsigned int>& targetTopology) {
  topology.insert(topology.end(), std::make_move_iterator(targetTopology.begin()), std::make_move_iterator(targetTopology.end()));
  for (auto& it : topology) {
    std::shared_ptr<Layer> l = std::make_shared<Layer>(it);
    layers.push_back(l);
  }
  for (unsigned int i = 0 ; i < layers.size() - 1 ; ++i) {
    std::shared_ptr<Matrix> m = std::make_shared<Matrix>(topology.at(i), topology.at(i + 1), true);
    weightMatrices.push_back(m);
  }
}

void NeuralNetwork::injectInput(const std::vector<double>& input) {
  std::shared_ptr<Layer> inputLayer = layers.at(0);
  for (unsigned int i = 0 ; i < input.size() ; ++i) {
    inputLayer->setValue(i, input.at(i));
  }
}

void NeuralNetwork::print() {
  for (std::shared_ptr<Layer> layer : layers) {
    for (auto&& neuron : layer->neurons) {
      std::cout<<neuron->getValue()<< "\t";
    }
    std::cout<<"\n";
  }
}

void NeuralNetwork::feedForward(std::vector<double> expected) {
  for (unsigned int i = 0 ; i < layers.size() - 1; ++ i) {
    std::shared_ptr<Matrix> currentLayer;
    if (i == 0) {
      currentLayer = getNeuronMatrix(i);
    } else {
      currentLayer = getActivatedNeuronMatrix(i);
    }
    std::shared_ptr<Matrix> weightMatrix = getWeightMatrix(i);
    std::shared_ptr<Matrix> multipliedLayer = utils::multiplyMatrix(currentLayer, weightMatrix);
    for (unsigned int j = 0 ; j < multipliedLayer->getNumCols(); ++j) {
      const double multipliedValue = 
         multipliedLayer->getValue(0, j);
      setNeuronValue(i + 1, j, multipliedValue);
    }
  }
  try {
    calculateError(expected);
  } catch (WrongExpectedError e) {
    std::cout<<e.what()<<"\n";
  }
}


double NeuralNetwork::calculateError(std::vector<double> expected) {
  if (expected.size() != layers.at(layers.size() - 1)->getSize()) {
    throw WrongExpectedError();
  }
  std::shared_ptr<Layer> lastLayer = layers.at(layers.size() - 1);
  for (unsigned int i = 0 ; i < lastLayer->getSize(); ++i) {
    double localError = expected.at(i) - lastLayer->getValue(i);
    error -= localError;
    errors.push_back(localError);
  }
  for (auto&& it : errors) {
    std::cout<<it<<" ";
  }
  std::cout<<"\nglobal error : " << error << "\n";

}
void NeuralNetwork::setNeuronValue(unsigned int layerIndex, unsigned int neuronValue, double value) {
  layers.at(layerIndex)->setValue(neuronValue, value);
}
