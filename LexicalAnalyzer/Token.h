#include<iostream>
#include<fstream>
using namespace std;
#pragma once
class Token
{
public:
	string name;
	string text;

	Token();

	Token(string name, string text);

	void TokenError(int pos);

	bool operator == (const Token& other);

	void operator = (const Token& other);
	
	friend ostream& operator<<(ostream& out, const Token token);
};

