#include <bits/stdc++.h>
#include<chrono>
#include<unistd.h>
using namespace std::chrono;
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
    auto start = system_clock::now();
    sleep(1);
    cout<<"robin, 20051828"<<endl;
	int arr[] = { 12, 11, 13, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);
    auto end = system_clock::now();
    cout << "\nTIME TAKEN : " <<duration_cast <nanoseconds> (end - start).count() / pow(10, 9) - 1<< endl;

	return 0;
}