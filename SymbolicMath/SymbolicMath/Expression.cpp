#include "stdafx.h"
#include "Expression.h"


Expression::Expression()
{
	root = new intStruct(0);
}


Expression::~Expression()
{
}

Expression::Expression(Expression &copy)
{
	root = copy.root;
}