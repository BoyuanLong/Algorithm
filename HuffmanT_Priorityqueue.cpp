#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > pq;

ll getAnswer(int n, std::vector<ll> w){
	for (int i = 0; i < n; ++i)
	{
		pq.push(w[i]);
	}

	ll ans = 0;

	while(pq.size() > 1){
		ll temp = 0;
		for (int j = 0; j < 2; ++j)
		{
			temp += pq.top();
			pq.pop();
		}

		ans += temp;
		pq.push(temp);
	}
	return ans;

}


int main(){
	int N;
	cin >> N;
	ll val;
	vector<ll> vals;

	for (int i = 0; i < N; ++i)
	{
		cin >> val;
		vals.push_back(val);
	}

	cout << getAnswer(N, vals) << endl;
}