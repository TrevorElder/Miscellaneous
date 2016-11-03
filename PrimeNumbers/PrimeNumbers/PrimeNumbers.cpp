// Author: Trevor Elder
// Date: 11/1/16
// Purpose: to continually find prime numbers

#include <vector>
#include <iostream>

using namespace std;

int main()
{
	const int FIRSTPRIME = 2;
	int numToCheck = 1;
	vector<int> primeList = {FIRSTPRIME};

	while (true)
	{
		// Increment by 2 to avoid checking even numbers
		numToCheck += 2;
		bool prime = 1;

		for (int i = 0; i < primeList.size(); i++)
		{
			if ((numToCheck % primeList[i]) == 0)
				prime = 0;
		}

		if (prime == 1)
		{
			primeList.push_back(numToCheck);
			cout << numToCheck << "\n";
		}
	}
}