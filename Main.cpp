#include <iostream>
#include <fstream>
#include <string>
#include "Nouns.h"
#include "rus8.h"
using namespace std;

int main()
{
	nouns nauns;
	rus();
	string noun;
	noun = nauns.obrabotka();
	cout << noun << endl;
	system("pause");
	return 0;
}