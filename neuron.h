#pragma once

#include <iostream>

class Neuron {
  public:
    Neuron(const double& initVal);

    void setVal(const double& val);
    
    // Fast Sigmoid Fun
    // f(x) = x / ( 1 + |x| )
    void activate();

    // Derivative for FFS 
    // f'(x) = f(x) * (1 - f(x))
    void derive();

    double getVal() {return val;}
    double getActivatedVal() {return activatedVal;}
    double getDerivedVal() {return derivedVal;}   


    Neuron(const Neuron&) = delete;
    Neuron& operator=(const Neuron&) = delete;
  private:
    // could be bigger than 1
    double val;

    // 0.0 - 1.0
    double activatedVal = 0.0;

    // 
    double derivedVal;
};




