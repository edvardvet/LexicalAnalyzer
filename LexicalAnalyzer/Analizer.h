#pragma once
#include <iostream>
#include "Token.h"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
class Analizer
{
public:
	string text;
	string buffer;
	int position;
	vector<string> keyWord{ "do", "while", "return", "int" };
	vector<string> delimiters{ "(", ")", "{", "}", ";", ","};
	vector<string> operators{ "==", "!=", "<", ">", "<=", ">=", "+", "-", "="};

	Analizer(string text);

	string NextWord();

	int DKA();

	Token GetToken();

	bool is_empty();
};


