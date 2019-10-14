#include <memory>
#include <iostream>
#include <cassert>

#include "matrix.h"

namespace utils {
  static std::shared_ptr<Matrix> multiplyMatrix(const std::shared_ptr<Matrix> m1, const std::shared_ptr<Matrix> m2) {
    if (m1->getNumCols() != m2->getNumRows()) {
      std::cerr << "cantr multiply matrices!\n";
      assert(false);
    }

    std::shared_ptr<Matrix> n = std::make_shared<Matrix>(m1->getNumRows(), m2->getNumCols(), false);
    for (unsigned int i = 0; i < m1->getNumRows(); ++i) {
      for (unsigned int j = 0; j < m2->getNumCols(); ++j) {
        for (unsigned int k = 0; k < m2->getNumRows(); ++k) {
          double p = m1->getValue(i, k) * m2->getValue(k, j);
          //std::cout<<"from: " << m1->getValue(i,k) <<" and " << m2->getValue(k,j) << " multiplied: "<<p<<"\n";
          double newVal = n->getValue(i, j) + p;
          n->setValue(i, j , newVal);
        }
      }
    }
  return n;
}

  static std::vector<double> matrixToVector(std::shared_ptr<Matrix> in) {
    std::vector<double> result;
    for (unsigned int i = 0 ; i < in->getNumRows(); ++ i) { 
      for (unsigned int j = 0 ; j < in->getNumCols(); ++j) {
        result.push_back(in->getValue(i, j));

      }
    }
    return result;
  }

} // utils
