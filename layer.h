
#pragma once

#include <vector>

class Neuron;
class Matrix;

class Layer {
  public:
    Layer(const unsigned int& size);

    unsigned int getSize() {return size;}

    void setVal(const unsigned int index, double value);

    Layer(const Layer&) = delete;
    Layer& operator=(const Layer&) = delete;
    
    std::vector<Neuron*> neurons;

    Matrix* matrixifyValues();
    Matrix* matrixifyActivatedValues();
    Matrix* matrixifyDerivedValues();

  private:
    unsigned int size;

};

