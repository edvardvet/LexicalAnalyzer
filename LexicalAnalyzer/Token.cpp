#include "Token.h"

ostream& operator<<(ostream& out, const Token token) {
	out << "Token {Name: " << token.name << ", Text: " << token.text << "}" << endl;
	return out;
}

void Token::TokenError(int pos) {
	cout << "Недопустимая лексама на позиции " << pos << endl;
}

Token::Token() {

}

Token::Token(string name, string text) {
	this->name = name;
	this->text = text;
}

bool Token::operator == (const Token& other) {
	if (this->text == other.text && this->name == other.name) return true;
	else return false;
}

void Token::operator = (const Token& other) {
	this->text = other.text;
	this->name = other.name;
}