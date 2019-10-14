#include "neuralNetwork.h"

#include <iostream>

#include "layer.h"
#include "neuron.h"
#include "utils.cpp"

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

void NeuralNetwork::feedForward() {
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
}

void NeuralNetwork::setNeuronValue(unsigned int layerIndex, unsigned int neuronValue, double value) {
  layers.at(layerIndex)->setValue(neuronValue, value);
}
