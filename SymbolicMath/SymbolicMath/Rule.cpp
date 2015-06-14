#include "stdafx.h"
#include "Rule.h"


Rule::Rule()
{
	knownEqualities = new tuple<baseStruct*, baseStruct*>[1];
	knownEqualities[0] = tuple<baseStruct*, baseStruct*>(new binaryOperatorStruct(new variableStruct("X", false, true), new unaryOperatorStruct(new variableStruct("Y", false, true), "-"), "+"), new binaryOperatorStruct(new variableStruct("X", false, true), new variableStruct("Y", false, true), "-"));
}


Rule::~Rule()
{
}