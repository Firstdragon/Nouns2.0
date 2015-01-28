#include "Nouns.h"
#include "rus8.h"
using namespace std;

int main()
{
	nouns nauns("man");
	rus();
	cout << nauns.is_singular() << endl;
	cout << nauns.singular() << endl;
	cout << nauns.is_plural() << endl;
	cout << nauns.plural() << endl;
	system("pause");
	return 0;
}