#include <iostream>
#include <list>
#include<math.h>
#include<vector>
#include"Analizer.h"
#include"HashTable.h"
#include"Token.h"
#include<fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string all_txt;
	string buffer;
	while (!fin.eof()) {
		fin >> buffer;
		all_txt += buffer + "\n";
	}
	Analizer A(all_txt);
	HashTable<string> B;
	while (A.is_empty()) {
		Token token;
		token = A.GetToken();
		B.Add(token.text, token.name);
	}
	B.PrintInFile();
	/*vector<string> arr {"aSbS", "aS", "c"};
	string str = "aacbc";
	vector<string> arr2{ "aSbS", "aS", "c" };
	vector<string> arr3;
	string ansv = "";
	bool flag3 = true;
	while (str != "") {
		int cnnn = 0;
		for (string ss : arr2) {
			if (ss == "")  cnnn++;

		}
		bool flag = false;
		bool flag2 = false;
		int size = arr2.size();
		if (cnnn == size) {
			flag3 = false;
			break;
		}
		for (int i = 0; i < size; i++) {
			if (arr2[i][0] == 'S') {
				flag2 = true;
				continue;
			}
			;
			if (arr2[i][0] != str[0]) arr2[i] = "";
			else {
				flag = true;
				arr2[i].erase(0, 1);
			}
		}
		if (flag) {
			ansv += str[0];
			str.erase(0, 1);
		}
		if (flag2) {
			arr3.clear();
			int size1 = arr2.size();
			int size2 = arr.size();
			int cnt = 0;
			for (int i = 0; i < size1; i++) {
				if (arr2[i] != ""){
					arr3.push_back(arr2[i]);
				}
				if (arr2[i][0] == 'S') cnt++;
			}
			size1 = arr3.size();
			arr2.resize(size2 * cnt + size1 - cnt);
			int cnt2 = 0;
			for (int i = 0; i < arr3.size(); i++) {
				if (arr3[i][0] != 'S') arr2[i] = arr3[i];
				else {
					string strs = arr3[i];
					strs.erase(0, 1);
					for (int j = 0; j < arr.size(); j++) {
						arr2[cnt2 * size2 + j] = arr[j] + strs;
					}
					cnt2++;
				}
			}
		}
	}
	if (flag3) {
		cout << ansv;
	}
	else cout << "Строка не читается!";*/
}