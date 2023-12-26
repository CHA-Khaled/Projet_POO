#ifndef VARIABLE_H
#define VARIABLE_H

#include <vector>
#include <string>

class IMesh;

class Variable {
public:
    Variable(const IMesh& mesh, const std::string& name);
    double operator[](int i) const;
    double& operator[](int i);
    int x_size() const;
    void print(int iteration) const;
    void exportToFile(int iteration) const;

private:
    const IMesh& mesh;
    std::vector<double> values;
    std::string name;
};

#endif

