#include "equation.h"
#include <cmath>

Equation::Equation(double a) : a(a) {}

void Equation::compute(Variable& u_n, Variable& u_np1, IMesh& mesh) {
    for (int i = 1; i < mesh.x_size(); ++i) {
    	double vitesse_adv = a * mesh.dx() /mesh.dt(); //le a est le CFL
        u_np1[i] = u_n[i] - a * (u_n[i] - u_n[i - 1]);
    }

    
    for (int i = 0; i < u_np1.x_size(); ++i) {
        u_n[i] = u_np1[i];
    }
}

void Equation::compute_initial_condition(Variable& u_n, IMesh& mesh) {
    double mu = (mesh.x_max() - mesh.x_min()) / 2.0;
    double sigma = 10.0 * mesh.dx();

    for (int i = 0; i < mesh.x_size(); ++i) {
        double x = mesh.x_i(i);
        u_n[i] = exp(-pow(x - mu, 2) / (2 * pow(sigma, 2))) / (sigma * sqrt(2 * M_PI));
    }
}

void Equation::compute_exact_solution(Variable& u_ref, IMesh& mesh, double current_time) {
    
    double sigma = 10.0 * mesh.dx();
    double a = this->a;
    for (int i = 0; i < mesh.x_size(); ++i) {
        double x = mesh.x_i(i);
        u_ref[i] = exp(-pow(x - a * current_time, 2) / (2 * pow(sigma, 2))) / (sigma * sqrt(2 * M_PI));
    }
}

