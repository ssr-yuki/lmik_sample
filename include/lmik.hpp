#include <cmath>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

class lmik {

private:    
    // const members
    const Matrix2d W_N_bar = Matrix2d::Identity(2, 2) * 0.001;  // bias of dumping factor 
    const Matrix2d W_E = Matrix2d::Identity(2, 2);              // weigth of error
    const double threshold = 0.000001;

    // caliculation functions
    void cal_e(Vector2d&, const Vector2d&, const Vector2d&);
    void cal_J(Matrix2d&, const Vector2d&);
    void cal_g(Vector2d&, const Matrix2d&, const Vector2d&);
    void cal_W_N(Matrix2d&, const Vector2d&);
    void cal_H(Matrix2d&, const Matrix2d&, const Matrix2d&);
    
public:
    lmik();
    ~lmik();
    void solve(Vector2d&, const Vector2d&);

};
