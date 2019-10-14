#include <iostream>
#include <memory>
#include <vector>

#include "neuralNetwork.h"
#include "utils.cpp"

int main(int argc, char** argv) {
  std::vector<unsigned int> top{2,3,3,2,2};
  NeuralNetwork nn(top);
  std::vector<double> in{0,1};
  nn.injectInput(in);
  nn.print();
  std::cout<<"===================\n";
  nn.feedForward();
  nn.print();

  return 0;
}
