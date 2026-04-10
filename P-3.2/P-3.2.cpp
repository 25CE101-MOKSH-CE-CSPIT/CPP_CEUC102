#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void input(int *a, int n);
int iterativeSum(int *a, int n);
int recursiveSum(int *a, int n);

int main()
{
	int n;
	cout << "Enter no. of Elements : ";
	if (!(cin >> n) || n < 0) {
		cerr << "Invalid number of elements\n";
		return 1;
	}

	int *a = new int[n];
	input(a, n);

	auto s1 = high_resolution_clock::now();
	cout << "Iterative Sum : " << iterativeSum(a, n) << endl;
	auto s2 = high_resolution_clock::now();

	auto s3 = high_resolution_clock::now();
	cout << "Recursive Sum : " << recursiveSum(a, n) << endl;
	auto s4 = high_resolution_clock::now();

	cout << "Time taken by Iterative Sum : " << duration_cast<microseconds>(s2 - s1).count() << " microseconds" << endl;
	cout << "Time taken by Recursive Sum : " << duration_cast<microseconds>(s4 - s3).count() << " microseconds" << endl;

	delete[] a;
	cout<<"\n......Exiting......\n";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
	return 0;
}

void input(int *a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = 50 + i;
}

int iterativeSum(int *a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];
	return sum;
}

int recursiveSum(int *a, int n)
{
	if (n <= 0)
		return 0;
	return a[n - 1] + recursiveSum(a, n - 1);
}
