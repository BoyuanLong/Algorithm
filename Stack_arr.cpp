#include<iostream>
#include<string>

using namespace std;

int n = 0;

void push(string* arr, string item){
	arr[n] = item;
	++n;
}

string pop(string* arr){
	return arr[--n];
}

string peek(string*arr, int i){
	return arr[i-1];
}

int main(){
	const int lala = 10001;
	int cnt;
	cin >> cnt;
	string arr[lala];
	for (int k = 0; k < cnt; ++k)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			string tmp;
			cin >> tmp;
			push(arr, tmp);
		}
		else if (cmd == 2)
		{
			cout << pop(arr) << endl;
		}
		else if (cmd == 3)
		{
			int tmp;
			cin >> tmp;
			cout << peek(arr,tmp) << endl;
		}
	}
}
