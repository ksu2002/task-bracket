#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	const char leftBracket = '[', rightBracket = ']';
	const int size = 256;
	int indexOpenBracket = size, indexCloseBracket = 0, i, strLength, sumLeftBracket = 0, sumLeftBracket0 = 0, indexOpenBracketFound = 0;
		string str;
	string subStr;
	cin >> str;
	cin >> subStr;
strLength = str.length();
for (i = 0; i < strLength; i++) {
		if (str[i] == leftBracket && indexOpenBracketFound != 1)
		{
			indexOpenBracket = i;
			indexOpenBracketFound = 1;
		}
	}
	for (i = indexOpenBracket; i < strLength && sumLeftBracket0 != 1; i++)
	{
		if (str[i] == leftBracket) sumLeftBracket++;
		if (str[i] == rightBracket) sumLeftBracket--;
		if (sumLeftBracket == 0)
		{
			indexCloseBracket = i;
			sumLeftBracket0 = 1;
		}
	}
	if (sumLeftBracket0 == 1)
	{
		const int sizeStr1 = indexOpenBracket - 1, sizeStr2 = strLength - indexCloseBracket + 1;
		string stringBeforeOpenBracket;
		string stringUfterCloseBracket;
		for (i = 0; i < indexOpenBracket; i++)
			stringBeforeOpenBracket += str[i];
		for (i = indexCloseBracket + 1; i < strLength; i++)
			stringUfterCloseBracket += str[i];
		string resultstring = stringBeforeOpenBracket + subStr + stringUfterCloseBracket;
			cout << resultstring;
	}
	else cout << str;
	return 0;
}
