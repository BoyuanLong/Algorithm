#include <iostream>
#include <vector>

using namespace std;

const int N = 500005;

int F[N];

void init(int n){
    for (int i = 1; i <= n; ++i)
    {
        F[i] = i;
    }
}

int find(int x){
    if (x != F[x])
    {
        F[x] = find(F[x]);
    }
    return F[x];
}

bool merge(int x, int y){
    int Fx = find(x);
    int Fy = find(y);
    if (Fx != Fy)
    {
        F[Fx] = Fy;
        return true;
    }
    return false;
}

vector<int> getAnswer(int n, int m, vector<int> U, vector<int> V){
    vector<int> temp;
    init(n);
    
    for (int i = m-1; i >= 0; --i)
    {
        if(merge(U[i], V[i])){
            temp.push_back(i+1);
        }
    }
    
    vector<int> ans;
    int tmp = static_cast<int>(temp.size());
    for (int i = 0; i < tmp; ++i)
    {
        ans.push_back(temp[tmp-1-i]);
    }
    return ans;
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<int> U, V;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        U.push_back(u);
        V.push_back(v);
    }
    vector<int> ans = getAnswer(n, m, U, V);
    cout << static_cast<int>(ans.size()) << endl;
    for (int i = 0; i < static_cast<int>(ans.size()); ++i)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
