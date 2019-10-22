#include <vector>
#include <memory>

class Matrix {
  public:
    Matrix(const unsigned int& numRows, const unsigned int& numCols, bool isRandom = false);

    std::shared_ptr<Matrix> transpose();

    void setValue(unsigned int r, unsigned int c, double val);
    double getValue(unsigned int r, unsigned int c);
    double getNumRows() {return numRows;}
    double getNumCols() {return numCols;}
    
    void print();
  private:
    unsigned int numRows;
    unsigned int numCols;

    std::vector<std::vector<double>> values;


};
