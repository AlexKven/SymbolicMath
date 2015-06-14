#pragma once
#include <string>
#include "structs.h"
using namespace std;

class Expression
{
public:
	Expression();
	~Expression();
	Expression(Expression &copy);
private:
	
	baseStruct *root;
};
