#include <iostream>
#include <memory>
#include <vector>

#include "neuralNetwork.h"

int main(int argc, char** argv) {
  
  std::vector<unsigned int> k {4,3,4};
  NeuralNetwork nn(k);
  
  std::vector<double> inputLayer {1,0,1,1};
  nn.injectInput(inputLayer);
  nn.print();

  return 0;
}
