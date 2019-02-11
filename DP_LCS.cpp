#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//Find LCS (Longest continuous Subsequence) using dynamic programming
//draw a 2*2 matrix storing all the LCS from the beginning of the two words,
//and return the last element in the matrix
//Complexity: O(m*n)
//Space: O(m*n)

int main(){
    string a = "BruceLong";
    string b = "Boyuan";
    
    int m = (int)a.size()+1;
    int n = (int)b.size()+1;
    int** mat = new int*[m];
    for (int i = 0; i < a.size()+1; ++i)
    {
        mat[i] = new int[n];
    }
    
    for(int i = 0; i < m; ++i){
        mat[i][0] = 0;
    }
    for(int i = 0; i < n; ++i){
        mat[0][i] = 0;
    }
    
    for (int i = 1; i < m; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            if (a[i-1] == b[j-1])
            {
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else{
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    cout << mat[a.size()][b.size()] << endl;
    
    for (int i = 0; i < m; ++i)
    {
        delete[] mat[i];
    }
    delete[] mat;
    return 0;
}
