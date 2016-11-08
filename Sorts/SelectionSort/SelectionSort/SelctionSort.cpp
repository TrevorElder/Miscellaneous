// Author: Trevor Elder
// Date: 11/07/16
// Purpose: To sort ints using selection sort

#include <iostream>;
#include <vector>;

using namespace std;


void selectionSort(vector<int>& toSort)
{
	// Go through the vector
	for (int i = 0; i < toSort.size(); i++)
	{
		int min = toSort[i];
		int pos = i;

		// Find the min value in the unsorted part of the vector
		for (int n = i; n < toSort.size(); n++)
		{
			if (toSort[n] < min)
			{
				min = toSort[n];
				pos = n;
			}
		}

		cout << "Min value(of this loop): " << min << "\n";
	
		// Switch the first element of the unsorted part and the element w/ the min value
		toSort[pos] = toSort[i];
		toSort[i] = min;
	}
}


int main()
{
	vector<int> toSort = { 5, 4, 3, 2, 1, 6 };

	for (int i = 0; i < toSort.size(); i++)
	{
		cout << toSort[i];
	}
	cin.get();

	selectionSort(toSort);

	for (int i = 0; i < toSort.size(); i++)
	{
		cout << toSort[i];
	}
	cin.get();
}