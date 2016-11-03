// Author: Trevor Elder
// Date: 11/1/16
// Purpose: To find the greatest prime factor of a number

#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	const int FIRSTPRIME = 2;
	bool newFactorNotFound = 1;
	int numToCheckIfPrime = 1;
	long long numToFindGPFOf = 25;
	vector<int> factorList;
	vector<int> primeList = {FIRSTPRIME};



	while (numToCheckIfPrime < sqrt(numToFindGPFOf))
	{
		newFactorNotFound = 1;
		// Check if previous primes are factors
		for (int i = 0; i < primeList.size(); i++)
		{
			if (numToFindGPFOf % primeList[i] == 0)
			{
				factorList.push_back(primeList[i]);
				numToFindGPFOf /= primeList[i];
				newFactorNotFound = 0;
			}
		}

		// Find prime numbers and check if they are a factor, no factor possible if numToCheckIfPrime > sqrt(numTofindGPFOf)
		while (newFactorNotFound)
		{
			// Increment by two to avoid testing mutiples of two
			numToCheckIfPrime += 2;
			bool prime = 1;

			for (int i = 0; i < primeList.size(); i++)
			{
				if ((numToCheckIfPrime % primeList[i]) == 0)
					prime = 0;
			}

			if (prime)
			{
				primeList.push_back(numToCheckIfPrime);
				prime = 0;

				// Check if the prime is a factor
				if ((numToFindGPFOf % numToCheckIfPrime) == 0)
				{
					factorList.push_back(numToCheckIfPrime);
					numToFindGPFOf /= numToCheckIfPrime;
					newFactorNotFound = 0;
				}
			}
		}
	}

	// Add the last prime factor to factorList
	// Converts long long to int, shouldn't matter, algorithm would take forever to get values too big for int
	// This adds 1 to the factor list if all the factors are found in the first loop, so if statement
	if (numToFindGPFOf != 1)
	{
		factorList.push_back(numToFindGPFOf);
	}

	// Outputs the factors and greatest prime factor and pause the console output
	std::sort(factorList.begin(), factorList.end());
	cout << "List of factors: ";
	for (int i = 0; i < factorList.size(); i++)
	{
		cout << factorList[i] << " ";
	}
	cout << "\nGreatest factor: " << factorList[factorList.size() - 1];
	std::cout << "\nPress any key to continue...";
	std::cin.get();
}