#include <iostream>
#include <vector>
using namespace std;


const int N = 300005;

int Father[N], Rank[N];

int find(int x){
    if(x == Father[x]){
		return x;
	}
	return find(Father[x]);
}

void swap(vector<int> &x, int i, int j){
	int temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}

string getAnswer(int n, int m, vector<int> &A, vector<int> &B, vector<int> &E){
	for (int i = 0; i <= n; ++i)
	{
		Father[i] = i;
		Rank[i] = 0;
	}

	int k = 0;
	for (int i = 0; i < m; ++i)
	{
		if(E[i] == 1){
			swap(E,k, i);
			swap(A,k, i);
			swap(B,k, i);
			++k;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int fA = find(A[i]);
		int fB = find(B[i]);

		if(E[i] == 0){
			if (fA == fB)
			{
				return "No";
			}
		}
		else{
			if (fA != fB)
			{
				Father[fA] = fB;
			}
		}
	}
	return "Yes";
}

int main(){
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int n, m;
		cin >> n >> m;

		vector<int> A, B, E;

		for (int i = 0; i < m; ++i)
		{
			int a, b, e;
			cin >> a >> b >> e;
			A.push_back(a);
			B.push_back(b);
			E.push_back(e);
		}
		cout << getAnswer(n,m,A,B,E) << endl;
	}
	return 0;

}

