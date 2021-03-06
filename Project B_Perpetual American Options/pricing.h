// Calculating PerpetualCall price and PerpetualPut price.

#ifndef PRICING_H
#define PRICING_H

#include <cmath>
#include <iostream>
#include "PAmericanOption.hpp"

using namespace std;

//Overloaded PerpetualCall() to pass asset value S and OptionData Struct.
double PerpetualCall(double S, PAmericanOption::OptionData* OD)
{
    double K = OD->K_s;
	double r = OD->r_s;
	double sig = OD->sig_s;
	double b = OD->b_s;

	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	

	if (1.0 == y1)
		return S;

	double fac2 = ((y1 - 1.0)*S) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);

	return c;

    
}


//Overloaded PerpetualPut() to pass asset value S and OptionData Struct.
double PerpetualPut(double S,  PAmericanOption::OptionData* OD)
{  
	double K = OD->K_s;
	double r = OD->r_s;
	double sig = OD->sig_s;
	double b = OD->b_s;


	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return S;

	double fac2 = ((y2 - 1.0)*S) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);

	return p;
} 


double PerpetualCall(double K, double S, double sig, double r, double b)
{ 
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - b/sig2 + sqrt(fac + 2.0*r/sig2);
	

	if (1.0 == y1)
		return S;

	double fac2 = ((y1 - 1.0)*S) / (y1 * K);
	double c = K * pow(fac2, y1) / (y1 - 1.0);

	return c;
}

double PerpetualPut(double K, double S, double sig, double r, double b)
{
	double sig2 = sig*sig;
	double fac = b/sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - b/sig2 - sqrt(fac + 2.0*r/sig2);
	
	if (0.0 == y2)
		return S;

	double fac2 = ((y2 - 1.0)*S) / (y2 * K);
	double p = K * pow(fac2, y2) / (1.0 - y2);

	return p;
}


#endif

