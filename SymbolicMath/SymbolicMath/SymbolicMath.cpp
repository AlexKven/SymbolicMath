// SymbolicMath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BigUint.h"
#include "structs.h"
#include "Expression.h"
#include "Pattern.h"
using namespace std;

long unsigned randLong();

int _tmain(int argc, _TCHAR* argv[])
{
	//long unsigned left = 5000;
	//	long unsigned right = 5000;
	//cout << "left = " << left << "." << endl
	//	<< "right = " << right << "." << endl << endl;
	//BigUint bLeft(left);
	//BigUint bRight(right);
	//bLeft.printDigits(cout);
	//BigUint sum = bLeft + bRight;
	//sum.printDigits(cout);
	expr *expr1 = expr::binaryOperation("+", expr::number(0), expr::binaryOperation("*", expr::number(2), expr::specialNumber("pi")));
	expr *plusZero = expr::binaryOperation("+", expr::number(0), expr::pattern("x"));
	Pattern ptn;
	patMap match; 
	bool tru = ptn.match(expr1, plusZero, &match);
	if (tru)
		expr1 = match.at("x");
	cin.get();
	return 0;
}

long unsigned randLong()
{
	long rnd = rand();
	rnd += 1073741824;
	long unsigned low = (long unsigned)rnd;
	rnd = rand();
	rnd += 1073741824;
	long unsigned high = (long unsigned)rnd;
	high <<= 32;
	return low + high;
}