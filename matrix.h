#include <vector>
#include <memory>

class Matrix {
  public:
    Matrix(const unsigned int& numRows, const unsigned int& numCols, bool isRandom);

    std::shared_ptr<Matrix> transpose();

    void setVal(unsigned int r, unsigned int c, double val);
    double getVal(unsigned int r, unsigned int c);
    
    void print();
  private:
    unsigned int numRows;
    unsigned int numCols;

    std::vector<std::vector<double>> values;


};
