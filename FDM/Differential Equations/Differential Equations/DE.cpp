#include<iostream>

using namespace std;

class Domain 
{
public:
	Domain(Curvebase&, Curvebase&, Curvebase&, Curvebase&):m(0),n(0),x(nullptr),y(nullptr) {}
	void generate_grid(int m_, int n_);
	int xsize() { return m; }
	int ysize() { return n; }
	Point operator()(int i, int j);
	bool grid_valid() { return m != 0; }

private:
	Curvebase* sides[4];
	int m, n;
	double* x, * y;

};

class Matrix
{
	int m, n;
	double* A;

public:
	Matrix(int m_ = 0, int n_ = 0) : m(m_), n(n_), A(nullptr)
	{
		if (m * n > 0) {
			A = new double[m * n];
			fill(A, A + m * n, 0.0);
		}
	}
};

class GFkt
{
	Matrix u;
	shared_ptr<Domain> grid;

public:
	GFkt(shared_ptr<Domain> grid_): u(grid_->xsize()+1,grid_->ysize()+1), grid(grid_) {}
	GFkt(const GFkt& U): u(U.u),grid(U.grid){}

};

GFkt GFkt::D0x() const {
	GFkt tmp(grid);
	if (grid->grid_valid()) {
		// generate derivative in tmp
		// according to one of the possibilities above
	}
	return tmp;
}
