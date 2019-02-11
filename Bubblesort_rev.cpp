#include <iostream>
#include <vector>


using namespace std;

typedef long long ll;

vector<ll> getAnswer(ll n, vector<ll> A, vector<ll> DS){
	vector<ll> sum, id;
	vector<ll> ans;
	ll cnt = 0;

	for (ll i = 0; i < n; ++i)
	{
		id.push_back(i+1);
		sum.push_back(A[i]+DS[i]);
	}

	for (ll i = 0; i < n; ++i)
	{
		for(ll j = n-1; j>i; --j){
			if (sum[j]>sum[j-1] ||(sum[j]==sum[j-1] && A[j] > A[j-1]))
			{
				swap(sum[j], sum[j-1]);
				swap(id[j], id[j-1]);
				swap(A[j], A[j-1]);
				swap(DS[j], DS[j-1]);
				++cnt;
			}
		}
	}

	for (ll i = 0; i < n; ++i)
	{
		ans.push_back(id[i]);
		ans.push_back(sum[i]);
		ans.push_back(A[i]);
		ans.push_back(DS[i]);
	}

	ans.push_back(cnt);
	return ans;
}

int main(){
	ll N;
	cin >> N;
	vector<ll> A, DS;
	for (ll i = 0; i < N; ++i)
	{
		ll temp1, temp2;
		cin >> temp1 >> temp2;
		A.push_back(temp1);
		DS.push_back(temp2);
	}


	vector<ll> ans = getAnswer(N,A,DS);

	ll cnt = 0;
	for (ll i = 0; i < N; ++i, cnt+=4)
	{
		cout << ans[cnt] << " " 
			 << ans[cnt+1] << " "
			 << ans[cnt+2] << " "
			 << ans[cnt+3] << endl;
	}
	cout << ans[cnt] << endl;
}