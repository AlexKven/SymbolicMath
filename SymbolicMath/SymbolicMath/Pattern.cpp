#include "stdafx.h"
#include "Pattern.h"
#include "structs.h"
#include <tuple>
using namespace std;


Pattern::Pattern()
{
}

Pattern::Pattern(tuple<expr*, expr*> _rule)
{
	rule = _rule;
}


Pattern::~Pattern()
{
}

bool Pattern::match(expr* expression, expr* pattern, patMap *mapping)
{
	switch (pattern->type)
	{
	case exprType::UnaryOperation:
		if (expression->type == exprType::UnaryOperation && expression->name == pattern->name)
			return match(expression->left, pattern->left, mapping);
		return false;
	case exprType::BinaryOperation:
		if (expression->type == exprType::BinaryOperation && expression->name == pattern->name)
			return match(expression->left, pattern->left, mapping) && match(expression->right, pattern->right, mapping);
		return false;
	case exprType::Number:
		return expression->type == exprType::Number && expression->value == pattern->value;
	case exprType::SpecialNumber:
		return expression->type == exprType::SpecialNumber && expression->name == pattern->name;
	case exprType::Unit:
		return expression->type == exprType::Unit && expression->name == pattern->name;
	case exprType::Variable:
		return expression->type == exprType::Variable && expression->name == pattern->name;
	case exprType::Pattern:
		if (mapping->find(pattern->name) == mapping->end())
		{
			mapping->insert(patMap::value_type(pattern->name, expression));
			return true;
		}
		else
		{
			return *mapping->at(pattern->name) == *expression;
		}
	}
}