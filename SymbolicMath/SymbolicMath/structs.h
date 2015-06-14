#pragma once
#include <string>
using namespace std;

struct baseStruct { };
struct unaryOperatorStruct : baseStruct
{
	unaryOperatorStruct(baseStruct *_next, string _op)
	{
		next = _next;
		op = _op;
	}
	baseStruct *next;
	string op;
};
struct binaryOperatorStruct : baseStruct
{
	binaryOperatorStruct(baseStruct *_left, baseStruct *_right, string _op)
	{
		left = _left;
		right = _right;
		op = _op;
	}
	baseStruct *left;
	baseStruct *right;
	string op;
};
struct intStruct : baseStruct
{
	intStruct(int unsigned _val)
	{
		val = _val;
	}
	int unsigned val;
};
struct specialNumberStruct : baseStruct
{
	string val;
};
struct variableStruct : baseStruct
{
	variableStruct(string _varName, bool _unit, bool _ruleVar)
	{
		varName = _varName;
		unit = _unit;
		ruleVar = _ruleVar;
	}
	string varName;
	bool unit;
	bool ruleVar;
};

enum class exprType {Number, SpecialNumber, UnaryOperation, BinaryOperation, Variable, Unit, Pattern};

struct expr
{
	expr(exprType _type, expr* _left, expr* _right, string _name, long unsigned _value)
	{
		type = _type;
		left = _left;
		right = _right;
		name = _name;
		value = _value;
	}
	exprType type;
	expr *left;
	expr *right;
	string name;
	long unsigned value;

	bool operator==(expr &rhs) const 
	{
		bool sub = true;
		if ((rhs.left == nullptr) == (left == nullptr) && (rhs.right == nullptr) == (right == nullptr))
		{
			if (rhs.left != nullptr)
				sub = sub && (*rhs.left) == *left;
			if (rhs.right != nullptr)
				sub = sub && (*rhs.right) == *right;
		}
		if (!sub) return false;
		return (rhs.type == type && rhs.value == value && rhs.name == name);
	}

	static expr* number(long unsigned val)
	{
		return new expr(exprType::Number, nullptr, nullptr, "", val);
	}

	static expr* variable(string name)
	{
		return new expr(exprType::Variable, nullptr, nullptr, name, 0);
	}

	static expr* specialNumber(string name)
	{
		return new expr(exprType::SpecialNumber, nullptr, nullptr, name, 0);
	}

	static expr* unit(string name)
	{
		return new expr(exprType::Unit, nullptr, nullptr, name, 0);
	}

	static expr* pattern(string name)
	{
		return new expr(exprType::Pattern, nullptr, nullptr, name, 0);
	}

	static expr* unaryOperation(string name, expr* operand)
	{
		return new expr(exprType::UnaryOperation, operand, nullptr, name, 0);
	}

	static expr* binaryOperation(string name, expr* left, expr* right)
	{
		return new expr(exprType::BinaryOperation, left, right, name, 0);
	}
};