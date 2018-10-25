#include <iostream>
#include "lmik.hpp"

using namespace std;

int main() {    
    Vector2d q, X, ans;
    q << M_PI_2, 0;
    
    cout << "Enter the target position (x, y)" << endl;
    cin >> X(0) >> X(1);

    lmik solver;
    solver.solve(q, X);
    cout << "q(0): " << q(0) << endl;
    cout << "q(1): " << q(1) << endl;
    
    return 0;
}
