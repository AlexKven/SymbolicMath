#pragma once
#include "structs.h"
#include <tuple>
using namespace std;

class Rule
{
public:
	Rule();
	~Rule();
private:
	tuple<baseStruct*, baseStruct*> *knownEqualities;
};