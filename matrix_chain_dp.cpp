#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int find_cost_memoised(int* p, int i, int j)
// {
//     // memset(dp, -1, sizeof dp);
//     // dp[][] is decleard globally, yet to be decleared....
//     if (i == j)
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     dp[i][j] = INT_MAX;
//     for (int k = i; k < j; k++)
//     {
//         dp[i][j] = min(
//             dp[i][j], matrixChainMemoised(p, i, k)
//                      + matrixChainMemoised(p, k + 1, j)
//                        + p[i - 1] * p[k] * p[j]);
//     }
//     return dp[i][j];
// }
// int MatrixChainOrder(int* p, int n)
// {
//     int i = 1, j = n - 1;
//     return matrixChainMemoised(p, i, j);
// }

int find_cost(vector<int>p, int n)
{
 
    /* For simplicity of the program, one
    extra row and one extra column are
    allocated in m[][]. 0th row and 0th
    column of m[][] are not used */
    int m[n][n];
 
    int i, j, k, L, q;
 
    /* m[i, j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */
 
    // cost is zero when multiplying
    // one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    return m[1][n - 1];
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;   // means n-1 matrices...
        vector<int>arr;
        for(int i = 0;i<n;i++){
            int a;cin>>a;arr.push_back(a);
        }

        int cost = find_cost(arr,n);
        cout<<cost<<endl;
    }
    return 0;
}