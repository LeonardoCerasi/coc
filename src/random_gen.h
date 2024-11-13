#pragma once

class random_gen
{
private:
	unsigned int a, c, m, s;
	unsigned int r;

public:
	// builders
	random_gen(unsigned int);

	// set
	void set_a(unsigned int);
	void set_c(unsigned int);
	void set_m(unsigned int);

	// random distributions
	double random();
	double unif(double, double);
	double exp(double);
	double gauss_bm(double, double);
	double gauss_ar(double, double);
};
