#include "diff.h"

using namespace std;


double diff(double(*funk)(double), double x,double e){
	double dx=1.;
	while(abs((funk(x+dx)-funk(x))/dx-(funk(x+dx/2)-funk(x))/(dx/2))>e){
		dx/=2.;
	}
	dx/=2;
	return (funk(x+dx)-funk(x))/(dx);
};

