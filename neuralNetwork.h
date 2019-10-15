#pragma once

#include <vector>
#include <memory>

#include "layer.h"

class Matrix;
class Layer;

class NeuralNetwork {
  public:
    NeuralNetwork(std::vector<unsigned int>& topology);
    void injectInput(const std::vector<double>& input);
    std::shared_ptr<Matrix> getNeuronMatrix(const unsigned int index) {return layers.at(index)->matrixifyValues();}
   
    std::shared_ptr<Matrix> getActivatedNeuronMatrix(const unsigned int index) {return layers.at(index)->matrixifyActivatedValues();}

    std::shared_ptr<Matrix> getDerivedNeuronMatrix(const unsigned int index) {return layers.at(index)->matrixifyDerivedValues();}

    std::shared_ptr<Matrix> getWeightMatrix(const unsigned int index) {return weightMatrices.at(index);}

    void feedForward(std::vector<double> expected);

    void setNeuronValue(unsigned int layerIndex, unsigned int neuronValue, double value);

    void print();

  private:
    std::vector<unsigned int> topology;
    std::vector<std::shared_ptr<Layer>> layers;
    std::vector<std::shared_ptr<Matrix>> weightMatrices;
    std::vector<double> errors;
    double error{0};
    
    double calculateError(std::vector<double> expected);
};
