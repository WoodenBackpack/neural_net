#include "neuralNetwork.h"

#include <iostream>

#include "layer.h"
#include "matrix.h"

NeuralNetwork::NeuralNetwork(std::vector<unsigned int>& targetTopology) {
  topology.insert(topology.end(), std::make_move_iterator(targetTopology.begin()), std::make_move_iterator(targetTopology.end()));
  for (auto& it : topology) {
    Layer* l = new Layer(it);
    layers.push_back(l);
  }
  for (unsigned int i = 0 ; i < layers.size() - 1 ; ++i) {
    Matrix* m = new Matrix(topology.at(i), topology.at(i + 1), true);
    weightMatrices.push_back(m);
  }
}

void NeuralNetwork::injectInput(const std::vector<double>& input) {
  Layer* inputLayer = layers.at(0);
  for (unsigned int i = 0 ; i < input.size() ; ++i) {
    inputLayer->setVal(i, input.at(i));
  }
}

void NeuralNetwork::print() {
  for (Layer* layer : layers) {
    std::cout<<"layer:\n";
    for (auto&& neuron : layer->neurons) {
      std::cout<<neuron->getVal()<< "\t";
    }
    std::cout<<"\n";
  }
}
