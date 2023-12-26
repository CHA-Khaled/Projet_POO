#ifndef EQUATION_H
#define EQUATION_H

#include "variable.h"
#include "imesh.h"

class Equation {
public:
    Equation(double a);
    void compute(Variable& u_n, Variable& u_np1, IMesh& mesh);
    void compute_initial_condition(Variable& u_n, IMesh& mesh);
    void compute_exact_solution(Variable& u_ref, IMesh& mesh, double current_time);

private:
    double a;
};

#endif

