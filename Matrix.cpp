#include<iostream.h>
#include<limits.h>
int MatrixChainMultiplication(int m[], int i, int j)
{

	if (j <= i + 1)
		return 0;

	int min = INT_MAX;
	for (int k = i + 1; k <= j - 1; k++)
	{

		int cost = MatrixChainMultiplication(m, i, k);

		cost = cost + MatrixChainMultiplication(m, k, j);


		cost =	cost + (m[i] * m[k] * m[j]);

		if (cost < min)
			min = cost;
	}

	return min;
}


int main()
{

	int m[] = { 10, 30, 5, 60 };
	int n = sizeof(m) / sizeof(m[0]);

	cout << "Minimum cost is : ";
    cout<< MatrixChainMultiplication(m, 0, n - 1);

	return 0;
}
