#ifndef PROBLEM_H
#define PROBLEM_H

#include "equation.h"
#include "imesh.h"
#include "timer.h"
#include <thread>
class Problem {
public:
    Problem(const Equation& equation, IMesh* mesh);
    void solve();
    void solve_par();

private:
    Equation equation;
    Variable u_n;
    Variable u_np1;
    Variable u_ref;
    IMesh* mesh;
    Timer timer_total;
    Timer timer_time_loop;
};

#endif

