#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N - i; j++)
			cout << " ";
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << "*";
		cout << endl;
	}
	for (int i = N / 2; i <= N; i++)
	{
		for (int j = 1; j <= N - i; j++)
			cout << " ";
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << "*";
		cout << endl;
	}
	for (int i = N / 2; i <= N; i++)
	{
		for (int j = 1; j <= N - i; j++)
			cout << " ";
		for (int j = 1; j <= 2 * i - 1; j++)
			cout << "*";
		cout << endl;
	}
	//int spaces = N/2 , stars  = N&1 ? N : N-1;
	for (int i = 1; i <= N / 2; i++)
	{
		for (int j = 1; j <= N / 2; j++)
			cout << " ";
		for (int j = 1; j <= N - 1; j++)
			cout << "*";
		if (N & 1)
			cout << "*";
		cout << endl;
	}
	return 0;
}