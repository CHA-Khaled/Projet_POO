#ifndef UNIFORMMESH_H
#define UNIFORMMESH_H

#include "imesh.h"

class UniformMesh : public IMesh {
public:
    UniformMesh(double t_ini, double t_final, double dt, double x_min, double x_max, double dx);

    double t_ini() const override;
    double t_final() const override;
    double dt() const override;
    double x_min() const override;
    double x_max() const override;
    double dx() const override;
    int x_size() const override;
    double x_i(int i) const override;

private:
    double t_ini_;
    double t_final_;
    double dt_;
    double x_min_;
    double x_max_;
    double dx_;
    int x_size_;
};

#endif

