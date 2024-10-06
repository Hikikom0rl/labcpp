#include "diff.h"

using namespace std;


double diffsqrEq(double a, double b, double c,double e, double x){
	double dx=e/10.0;
	return ((a*(x+dx)*(x+dx)+b*(x+dx)+c)-(a*x*x+b*x+c))/dx;
};

