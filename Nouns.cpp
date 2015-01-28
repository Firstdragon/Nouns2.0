#include "Nouns.h"

bool nouns::irregulars(bool issing)
{
	ifstream in("irregular.txt");
	if (!in)
	{
		return 0;
	}
	else
	{
		do
		{
			in >> str1 >> str2;
			if (noun == str1 || noun == str2)
			{
				if (issing)
				{
					in.close();
					noun = str1;
					return 1;
				}
				else
				{
					in.close();
					noun = str2;
					return 1;
				}
			}
		} while (!in.eof());
		in.close();
		return 0;
	}
}

void nouns::in_singular()
{
	i = noun.length();
	string ending = noun.substr(i - 1);
	string ending2 = noun.substr(i - 2, 2);
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
}

void nouns::in_plural()
{
	i = noun.length();
	string ending = noun.substr(i - 1);
	string ending2 = noun.substr(i - 2, 2);


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
}

nouns::nouns(const string& word)
{
	noun = word;
	i = 0;
	str1 = "";
	str2 = "";
}

bool nouns::is_singular()
{
	i = noun.length();
	if (noun.substr(i - 2, 2) == "es" || noun.substr(i - 2, 2) == "ks")
		return false;
	else return true;
}

bool nouns::is_plural()
{
	return !is_singular();
}

string nouns::singular()
{
	if (irregulars(true))
		return noun;

	if (is_plural())
		in_singular();
	return noun;
}

string nouns::plural()
{
	if (irregulars(false))
		return noun;

	if (is_singular())
		in_plural();
	return noun;
}

nouns::~nouns()
{
	noun = "";
	i = 0;
	str1 = "";
	str2 = "";
}

