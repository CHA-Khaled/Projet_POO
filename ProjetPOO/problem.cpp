#include "problem.h"
#include<iostream>
#include <vector>
#include <functional>
Problem::Problem(const Equation& equation, IMesh* mesh)
    : equation(equation), u_n(*mesh, "u_n"), u_np1(*mesh, "u_np1"), u_ref(*mesh, "u_ref"), mesh(mesh) {if (!mesh) {
        throw std::invalid_argument("Mesh pointer cannot be null.");
    }}

void Problem::solve() {
if(mesh){
    equation.compute_initial_condition(u_n, *mesh);
    u_n.exportToFile(0);
    //u_ref.exportToFile(0);
	timer_time_loop.start();
    for (int i = 1; i <= mesh->t_final() / mesh->dt(); ++i) {
        equation.compute(u_n, u_np1, *mesh);
        equation.compute_exact_solution(u_ref, *mesh, i * mesh->dt());
        u_n.exportToFile(i);
        
        //u_ref.exportToFile(i);
        
        u_np1.print(i);
    }
    equation.compute_exact_solution(u_ref, *mesh, mesh->t_final());
    u_n.exportToFile(20);
    u_ref.exportToFile(20);
    } else {
    	std::cerr << "Error: Mesh is null in Problem::solve\n";
    }
    timer_total.stop();
    timer_total.print("Total");
}


void Problem::solve_par() {
    if (!mesh) {
        std::cerr << "Error: Mesh pointer is null in Problem::solve_parallel\n";
        return;
    }

    equation.compute_initial_condition(u_n, *mesh);
    u_n.exportToFile(0);
    timer_time_loop.start();

    std::thread computeThread([&]() {
        for (int i = 1; i <= mesh->t_final() / mesh->dt(); ++i) {
            equation.compute(u_n, u_np1, *mesh);
            u_n.exportToFile(i);
            u_np1.print(i);
        }
    });

    std::thread exactSolutionThread([&]() {
        for (int i = 1; i <= mesh->t_final() / mesh->dt(); ++i) {
            equation.compute_exact_solution(u_ref, *mesh, i * mesh->dt());
        }
    });

    computeThread.join();
    exactSolutionThread.join();

    equation.compute_exact_solution(u_ref, *mesh, mesh->t_final());
    u_n.exportToFile(20);
    u_ref.exportToFile(20);

    timer_total.stop();
    timer_total.print("Total");
}

