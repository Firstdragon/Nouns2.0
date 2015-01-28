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
	getline(cin, noun);
	noun = nauns.plurality(noun);
	cout << noun << endl;
	noun = nauns.singularity(noun);
	cout << noun << endl;
	noun = nauns.singularity(noun);
	cout << noun << endl;
	noun = nauns.plurality(noun);
	cout << noun << endl;
	noun = nauns.plurality(noun);
	cout << noun << endl;
	noun = nauns.singularity(noun);
	cout << noun << endl;
	system("pause");
	return 0;
}