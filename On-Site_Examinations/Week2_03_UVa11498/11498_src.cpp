/*
3 The first line of a test case contains one integer K indicating the number of queries that will be made
2 1 The second line of a test case contains two integers N and M representing the coordinates of the division point
10 10
-10 1
0 33
4
-1000 -1000
-1000 -1000
0 0
-2000 -10000
-999 -1001
0
*/

#include <iostream>

using namespace std;

int main()
{
	int K;
	while (cin >> K)
	{
		if (K == 0)
			break;

		int N, M;
		cin >> N >> M;

		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			if (X > N && Y > M)
				cout << "NE" << endl;
			else if (X < N && Y > M)
				cout << "NO" << endl;
			else if (X < N && Y < M)
				cout << "SO" << endl;
			else if (X > N && Y < M)
				cout << "SE" << endl;
			else
				cout << "divisa" << endl;
		}
	}
}