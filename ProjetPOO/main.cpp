#include "problem.h"
#include "uniformmesh.h"

int main(int argc, char** argv) {
    double t_ini = 0.0;
    double t_final = 2.0;
    double dt = 0.1;
    double x_min = 0.0;
    double x_max = 10.0;
    double dx = 0.1;
    double a = 0.5;

    UniformMesh mesh(t_ini, t_final, dt, x_min, x_max, dx);
    Equation equation(a);
    Problem problem(equation, &mesh);
    
    std::cout<<"séquentiel solve\n"<<std::endl;
    problem.solve();
    std::cout<<"\n\n\n\n\n\n\n\n"<<std::endl;
    
    std::cout<<"parallèl solve\n"<<std::endl;
    problem.solve_par();

    return 0;
}

