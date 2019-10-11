#pragma once

#include <vector>
#include "layer.h"

class Matrix;
class Layer;

class NeuralNetwork {
  public:
    NeuralNetwork(std::vector<unsigned int>& topology);
    void injectInput(const std::vector<double>& input);
    void print();
  private:
    std::vector<unsigned int> topology;
    std::vector<Layer*> layers;
    std::vector<Matrix*> weightMatrices;
};
