#include "variable.h"
#include "imesh.h"
#include <iostream>
#include <fstream>

Variable::Variable(const IMesh& mesh, const std::string& name)
    : mesh(mesh), values(mesh.x_size()), name(name) {}

double Variable::operator[](int i) const {
    return values[i];
}

double& Variable::operator[](int i) {
    return values[i];
}

int Variable::x_size() const {
    return mesh.x_size();
}

void Variable::print(int iteration) const {
    std::cout << "--- Variable " << name << " at iteration: " << iteration << " ---\n";
    for (int i = 0; i < x_size(); ++i) {
        std::cout << "u[" << i << "] = " << values[i] << "\n";
    }
}

void Variable::exportToFile(int iteration) const {
    std::string filename = "Variable_" + name + "_" + std::to_string(iteration) + ".data";
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < x_size(); ++i) {
            outFile << values[i] << "\n";
        }
        outFile.close();
        std::cout << "Exported " << name << " to file: " << filename << "\n";
    } else {
        std::cerr << "Error: Unable to open file for export.\n";
    }
}

