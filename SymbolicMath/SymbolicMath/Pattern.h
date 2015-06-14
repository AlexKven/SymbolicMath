#pragma once
#include "structs.h"
#include <vector>
#include <map>
#include <tuple>
using namespace std;

typedef map<string, expr*> patMap;

class Pattern
{
public:
	Pattern();
	Pattern(tuple<expr*, expr*> _rule);
	~Pattern();

	bool match(expr* expression, expr* pattern, patMap *mapping);
private:
	tuple<expr*, expr*> rule;
};