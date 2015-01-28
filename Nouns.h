#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "rus8.h"

using namespace std;

class nouns
{
private:
	string noun;
	string str1;
	string str2;
	int i;

	bool irregulars(bool issing);

	void in_singular();

	void in_plural();

public:

	nouns(const string& word);
		
	bool is_singular();

	bool is_plural();
	
	string singular();

	string plural();

	~nouns();
	
};