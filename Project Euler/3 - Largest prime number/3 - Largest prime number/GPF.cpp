// Author: Trevor Elder
// Date: 11/1/16
// Purpose: To find the greatest prime factor of a number
// Slow and horrible, will optimize later

#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	bool factorNotFound = 1;
	bool notCompletelyFactored = 1;
	const int FIRSTPRIME = 2;
	long long numToCheckIfPrime = 1;
	long long numToFindGPFOf = 600851475143;
	vector<long long> factorList;
	vector<long long> primeList = {FIRSTPRIME};

	while (notCompletelyFactored)
	{
		// Check to see if numToFindGPFof is factored
		for (int i = 0; i < primeList.size(); i++)
		{
			if (numToFindGPFOf == primeList[i])
			{
				factorList.push_back(numToFindGPFOf);
				notCompletelyFactored = 0;
			}
		}

		// Find prime numbers and check if they are a factor
		while (factorNotFound)
		{
			// Increment by two to avoid testing mutiples of two
			numToCheckIfPrime += 2;
			bool prime = 1;

			for (int i = 0; i < primeList.size(); i++)
			{
				if ((numToCheckIfPrime % primeList[i]) == 0)
					prime = 0;
			}

			if (prime == 1)
			{
				primeList.push_back(numToCheckIfPrime);
				//cout << numToCheckIfPrime << "\n";
				prime = 0;

				// Check if the prime is a factor
				if ((numToFindGPFOf % numToCheckIfPrime) == 0)
				{
					factorList.push_back(numToFindGPFOf / numToCheckIfPrime);
					factorNotFound = 0;
					cout << factorList[factorList.size() - 1] << "\n";
					factorNotFound = 1;
				}
			}
		}
	}

	sort(factorList.begin(), factorList.end());
	cout << factorList[factorList.size() - 1];
}