#ifndef IMESH_H
#define IMESH_H

class IMesh {
public:
    virtual ~IMesh() {}
    virtual double t_ini() const = 0;
    virtual double t_final() const = 0;
    virtual double dt() const = 0;
    virtual double x_min() const = 0;
    virtual double x_max() const = 0;
    virtual double dx() const = 0;
    virtual int x_size() const = 0;
    virtual double x_i(int i) const = 0;
};

#endif
