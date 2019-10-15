#pragma once

#include <vector>
#include <memory>

class Neuron;
class Matrix;

class Layer {
  public:
    Layer(const unsigned int& size);

    unsigned int getSize() {return size;}

    void setValue(const unsigned int index, double value);
    double getValue(const unsigned int index);

    Layer(const Layer&) = delete;
    Layer& operator=(const Layer&) = delete;
    
    std::vector<std::shared_ptr<Neuron>> neurons;

    std::shared_ptr<Matrix> matrixifyValues();
    std::shared_ptr<Matrix> matrixifyActivatedValues();
    std::shared_ptr<Matrix> matrixifyDerivedValues();

  private:
    unsigned int size;

};

