// Author: Trevor Elder
// Date: 10/22/16

#include <vector>
#include <iostream>

using namespace std;

// The insertSort function
// Purpose: Sort ints using quicksort
// Parameters: int* toSort - pointer to an int array
// Returns: none, directly manipulates the array
void insertSort(vector<int>& toSort)
{
	int temp = 0;
	int pos = 0;

	// Go through elements, skip first element(one element is always sorted)
	for (int i = 1; i < toSort.size(); i++)
	{
		// Set Starting position
		pos = i;
		temp = toSort[pos];

		// Go through array, shifting elements right until element is less than temp or end of the sorted elements is reached
		while (pos > 0 && temp > toSort[pos - 1])
		{
			toSort[pos] = toSort[pos - 1];
			pos -= 1;

			for (int i = 0; i < toSort.size(); i++)
			{
				cout << toSort[i];
			}
			cin.get();
		}

		// Insert the element being sorted
		toSort[pos] = temp;
	}
}


int main()
{
	vector<int> toSort = { 0, 1, 2, 3, 4, 5 };

	for (int i = 0; i < toSort.size(); i++)
	{
		cout << toSort[i];
	}
	cin.get();

	insertSort(toSort);

	for (int i = 0; i < toSort.size(); i++)
	{
		cout << toSort[i];
	}
	cin.get();
}