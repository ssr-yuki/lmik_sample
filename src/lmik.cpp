#include "lmik.hpp"

const double l1 = 0.1;
const double l2 = 0.1;

lmik::lmik() {}

lmik::~lmik() {}

void lmik::solve(Vector2d& q_ref, const Vector2d& X_ref) {
    Matrix2d W_N, J, H;
    Vector2d q, q_new, delta_q, e, g; 
    q = q_ref;
    
    do {
        cal_e(e, q, X_ref);
        cal_J(J, q);
        cal_g(g, J, e);
        cal_W_N(W_N, e);
        cal_H(H, J, W_N);
        delta_q = H.inverse() * g;
        q += delta_q;
    } while(abs(delta_q(0)) > threshold && abs(delta_q(1)) > threshold);

    q_ref = q;
    return;
}

void lmik::cal_e(Vector2d &e, const Vector2d &q, const Vector2d &X) {
    e(0) = X(0) - (l1 * cos(q(0)) + l2 * cos(q(0) + q(1)));
    e(1) = X(1) - (l1 * sin(q(0)) + l2 * sin(q(0) + q(1)));
    return;
}

void lmik::cal_J(Matrix2d &J, const Vector2d &q) {
    J(0, 0) = - l1 * sin(q(0)) - l2 * sin(q(0) + q(1));
    J(0, 1) =                  - l2 * sin(q(0) + q(1));
    J(1, 0) =   l1 * cos(q(0)) + l2 * cos(q(0) + q(1));
    J(1, 1) =                    l2 * cos(q(0) + q(1));    
    return;
}

void lmik::cal_g(Vector2d &g, const Matrix2d &J, const Vector2d &e) {
    g = J.transpose() * W_E * e;
    return;
}

void lmik::cal_W_N(Matrix2d &W_N, const Vector2d &e) {
    W_N = Matrix2d::Identity(2, 2) * e.squaredNorm();
    W_N += W_N_bar;
    return;
}

void lmik::cal_H(Matrix2d &H, const Matrix2d &J, const Matrix2d &W_N){
    H = J.transpose() * W_E * J + W_N;
    return;
}
