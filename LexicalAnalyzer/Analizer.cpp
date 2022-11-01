#include "Analizer.h"

Analizer::Analizer(string text) {
	this->text = text;
}

string Analizer::NextWord() {
	int pos = position;
	string buf;
	while (text[pos] != '\n' && text[pos] != ' ') {
		buf += text[pos];
		pos++;
	}
	position = pos + 1;
	return buf;
}

int Analizer::DKA() {
	int state, size;
	buffer = NextWord();
	if (isdigit(buffer[0])) state = 1;
	else if (isalpha(buffer[0])) state = 2;
	else state = 3;

	size = buffer.size();

	switch (state)
	{
	case 1:
		for (int i = 0; i < size; i++) {
			if (!isdigit(buffer[i])) {
				return 3;
			}
		}
		return 1;
	case 2:
		for (int i = 0; i < size; i++) {
			if (!isalpha(buffer[i])) {
				return 3;
			}
		}
		return 2;
	}
}

Token Analizer::GetToken() {
	int state;
	Token token;

	state = DKA();

	switch (state) {
	case 1:
		token.text = buffer;
		token.name = "IntNum";
		return token;
		break;
	case 2:
		if (find(keyWord.begin(), keyWord.end(), buffer) != keyWord.end()) {
			token.text = buffer;
			token.name = buffer;
			return token;
		}
		else {
			token.text = buffer;
			token.name = "id";
			return token;
		}
		break;
	case 3:
		if (find(operators.begin(), operators.end(), buffer) != operators.end()) {
			token.text = buffer;
			token.name = "operator";
			return token;
		}
		else if (find(delimiters.begin(), delimiters.end(), buffer) != delimiters.end()) {
			token.text = buffer;
			token.name = "delimiter";
			return token;
		}
		else {
			token.TokenError(position - 1);
			token.text = buffer;
			token.name = "error";
			return token;
		}
		break;
	}

}

bool Analizer::is_empty() {
	if (position < text.size()) {
		return true;
	}
	else {
		return false;
	}
}
