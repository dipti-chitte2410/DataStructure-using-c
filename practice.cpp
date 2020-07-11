#include <iostream>
#include <string.h>

bool search(string str, string pattern)
{
	int n = str.length();
	int m = pattern.length();

	for (int i = 0; i <= n - m; i++)
	{
		int j;
		for (j = 0; j < m; j++)
		{
			if (str[i + j] != pattern[j])
				break;
		}
		if (j == m)
			return true;
	}
	return false;
}

int main()
{
	string str = "prodevelopertutrial";
	string pattern = "rial";

	if (search(str, pattern))
	{
		cout << "The substring is present";
	}
	else
	{
		cout << "The substring is NOT present";
	}

	return 0;
}