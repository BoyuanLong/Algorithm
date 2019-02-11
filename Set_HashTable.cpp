#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int Mod = 1000003;
std::vector<ll> table[Mod];

int hashMod(ll x){
	return x % Mod;
}

bool check(int op, ll val){
	int x = hashMod(val);

	std::vector<ll>::iterator ptr = table[x].end();

	for (vector<ll>::iterator it = table[x].begin(); it != table[x].end(); ++it)
	{
		if(*it == val){
			ptr = it;
			break;
		}
	}

	if (op == 1)
	{
		if (ptr == table[x].end())
		{
			table[x].push_back(val);
			return true;
		}
	}
	if (op == 2)
	{
		if (ptr != table[x].end())
		{
			table[x].erase(ptr);
			return true;
		}
	}
	return false;
}

int main(){
	int N, op;
	ll val;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> op >> val;
		cout << (check(op, val) ? "Succeeded" : "Failed") << endl;
	}

}