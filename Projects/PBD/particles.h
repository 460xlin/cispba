#ifndef PARTICLES_H
#define PARTICLES_H


#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>


using namespace Eigen;
constexpr int dim = 3;


template <class T>
class Particles
{
public:
	void createFromObj(const char*);
	Particles();
	void assignMass();
	void assignInitialVelocity();
	void updatePosition();
	void updateVelocity();

private:
	std::vector< Matrix<T, dim, 1> > positions;	
	std::vector< Matrix<T, dim, 1> > velocites;
	std::vector<T> inverseMass;
};


#endif