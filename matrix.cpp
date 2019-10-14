#include "matrix.h"

#include <random>
#include <iostream>

Matrix::Matrix(const unsigned int& numRows, const unsigned int& numCols, bool isRandom): numRows(numRows), numCols(numCols) {
  for (unsigned int r = 0 ; r < numRows; ++r) {
    std::vector<double> column;
    for (unsigned int c = 0 ; c < numCols; ++c) {
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_real_distribution<> dist(0, 1);
      double val = isRandom ? dist(gen) : 0.0;
      column.push_back(val);
    }
    values.push_back(column);
  }
}

void Matrix::setValue(unsigned int r, unsigned int c, double val) {
  values.at(r).at(c) = val;
}


double Matrix::getValue(unsigned int r, unsigned int c) {
   return values.at(r).at(c);
}


void Matrix::print() {
  std::cout<<"=======================\n";
  for (unsigned int i = 0; i < numRows; ++i) {
    for (unsigned int j = 0 ; j < numCols; ++j) {
      std::cout<<values.at(i).at(j)<<"\t";
    }
    std::cout<<"\n";
  }
  std::cout<<"=======================\n";
}

std::shared_ptr<Matrix> Matrix::transpose() {
  std::shared_ptr<Matrix> m = std::make_shared<Matrix>(numCols, numRows, false);
  for (unsigned int i = 0; i < numRows; ++i) {
    for (unsigned int j = 0 ; j < numCols; ++j) {
      const double val = getValue(i, j);
      m->setValue(j, i, val);
    }
    std::cout<<"\n";
  }
  return m;
}

