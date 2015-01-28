#pragma once
#include <string>
#include <iostream>
#include "rus8.h"

using namespace std;

class nouns
{
private:
	string noun;
	string str1;
	string str2;
	int n;
	int pl;
	int i;
public:

	string singularity(string noun)
	{
		ifstream in("irregular.txt");
		if (!in)
		{
			cout << "Файл с существительными-исключениями не может быть открыт" << endl;
			return 0;
		}
		else
		{
			for (n = 0;; n++)
			{
				in >> str1 >> str2;
				if (noun == str1)
				{
					cout << "Это слово первоначально в единственном числе" << endl;
					in.close();
					return str1;
				}
				else if (noun == str2)
				{
					cout << "Это слово было во множественном числе, класс перевел его в единственное" << endl;
					in.close();
					return str1;
				}
				if (in.eof()) break;
			}
			in.close();
		}


		i = noun.length();
		if (noun.substr(i - 2, 2) == "es" || noun.substr(i - 2, 2) == "ks")
			pl = 2;
		else pl = 1;
		{
			string ending = noun.substr(i - 1);
			string ending2 = noun.substr(i - 2, 2);

			if (pl == 1)
			{
				cout << "Это слово первоначально в единственном числе" << endl;
				return noun;
			}
			else if (pl == 2)
			{
				if (ending2 == "ys")
				{
					noun.erase(i - 1, 1);
				}
				else if (i > 3)
				{
					{
						string ending3 = noun.substr(i - 3, 3);
						if (ending3 == "ies")
						{
							noun.erase(i - 3, 3);
							noun.append("y");
						}
						else if (ending3 == "ves")
						{
							noun.erase(i - 3, 3);
							noun.append("f");
						}
						else if ((ending3 == "oes") || (ending3 == "xes") || (ending3 == "ses"))
						{
							noun.erase(i - 2, 2);
						}
						else if (i <= 4) noun.erase(i - 1, 1);
						else if (i >= 4)
						{
							string ending4 = noun.substr(i - 4, 4);
							if ((ending3 == "oes") || (ending4 == "ches") || (ending4 == "shes") || (ending3 == "xes") || (ending3 == "ses"))
							{
								noun.erase(i - 2, 2);
							}
							else noun.erase(i - 1, 1);
						}
					}
				}
				cout << "Это слово было во множественном числе, класс перевел его в единственное" << endl;
				return noun;
			}
		}
	}

	string plurality(string noun)
	{
		ifstream in("irregular.txt");
		if (!in)
		{
			cout << "Файл с существительными-исключениями не может быть открыт" << endl;
			return 0;
		}
		else
		{
			for (n = 0;; n++)
			{
				in >> str1 >> str2;
				if (noun == str1)
				{
					cout << "Это слово было в единственном числе, класс перевел его во множественное" << endl;
					in.close();
					return str2;
				}
				else if (noun == str2)
				{
					cout << "Это слово первоначально было во множественном числе" << endl;
					in.close();
					return str2;
				}
				if (in.eof()) break;
			}
			in.close();
		}


		i = noun.length();
		if (noun.substr(i - 2, 2) == "es" || noun.substr(i - 2, 2) == "ks")
			pl = 2;
		else pl = 1;
		{
			string ending = noun.substr(i - 1);
			string ending2 = noun.substr(i - 2, 2);

			if (pl == 1)
			{
				if (ending == "z" || ending == "s" || ending == "x" || ending == "o" || (ending2 == "ch") || (ending2 == "sh"))
				{
					noun.append("es");
				}
				else if (ending2 == "ay" || ending2 == "ey" || ending2 == "oy" || ending2 == "uy")
				{
					noun.append("s");
				}
				else if (ending == "y")
				{
					noun.erase(i - 1, 1);
					noun.append("ies");
				}
				else if (i > 3)
				{
					string ending3 = noun.substr(i - 3, 3);
					if ((ending2 == "fe" || ending == "f") && ((ending2 != "ff") || (ending3 != "ffe")))
					{
						if (ending2 == "fe")
						{
							noun.erase(i - 2, 2);
							noun.append("ves");
						}
						else
						{
							noun.erase(i - 1, 1);
							noun.append("ves");
						}
					}
					else noun.append("s");
				}
				else if ((ending2 == "fe" || ending == "f") && ((ending2 != "ff")))
				{
					if (ending2 == "fe")
					{
						noun.erase(i - 2, 2);
						noun.append("ves");
					}
					else
					{
						noun.erase(i - 1, 1);
						noun.append("ves");
					}
				}
				else noun.append("s");
				cout << "Это слово было в единственном числе, класс перевел его во множественное" << endl;
				return noun;
			}
			else if (pl == 2)
			{
				cout << "Это слово первоначально было во множественном числе" << endl;
				return noun;
			}
		}
	}
};