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
	int numToCheckIfPrime = 1;
	long long numToFindGPFOf = 600851475143;
	vector<int> factorList;
	vector<int> primeList = {FIRSTPRIME};



	// Find prime numbers and check if they are a factor, no factor possible if numToCheckIfPrime > sqrt(numTofindGPFOf)
	while (numToCheckIfPrime < sqrt(numToFindGPFOf))
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
				std::cout << factorList[factorList.size() - 1] << "\n";
			}
		}
	}

	// Add the last prime factor to factorList
	// Converts long long to int, shouldn't matter, algorithm would take forever to get values too big for int
	factorList.push_back(numToFindGPFOf);


	// Output the greatest prime factor and pause the console output
	sort(factorList.begin(), factorList.end());
	std::cout << factorList[factorList.size() - 1];
	std::cout << "\nPress any key to continue...";
	std::cin.get();
}