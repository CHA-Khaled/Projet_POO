#include "uniformmesh.h"

UniformMesh::UniformMesh(double t_ini, double t_final, double dt, double x_min, double x_max, double dx)
    : t_ini_(t_ini), t_final_(t_final), dt_(dt), x_min_(x_min), x_max_(x_max), dx_(dx) {
    x_size_ = static_cast<int>((x_max_ - x_min_) / dx_);
}

double UniformMesh::t_ini() const { return t_ini_; }
double UniformMesh::t_final() const { return t_final_; }
double UniformMesh::dt() const { return dt_; }
double UniformMesh::x_min() const { return x_min_; }
double UniformMesh::x_max() const { return x_max_; }
double UniformMesh::dx() const { return dx_; }
int UniformMesh::x_size() const { return x_size_; }
double UniformMesh::x_i(int i) const { return x_min_ + i * dx_; }

