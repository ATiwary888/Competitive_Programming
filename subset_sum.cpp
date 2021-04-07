#include<iostream>
#include<vector>
using namespace std;

bool equalPartition(int n, vector<int> &arr)
    {
        // code here
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2==1){
            return 0;
        }else{
        bool dp[n+1][(sum/2)+1];
        for(int i = 0;i<=n;i++){
            dp[i][0]=true;
            
        }
        for(int j = 1;j<=sum/2;j++){
            dp[0][j]=false;
        }
        int need = sum/2;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=sum/2;j++){
                if(arr[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }else{
                    // if(arr[i-1]==j){
                    int k = dp[i-1][j]|dp[i-1][j-arr[i-1]];
                    dp[i][j]=k;
                        
                    }
                }
                
            }
      
    return dp[n][need];
        }}

int main(){
    int n;cin>>n;
    vector<int>arr;
    for(int i = 0;i<n;i++){
        int a;cin>>a;arr.push_back(a);
    }

    bool chek = equalPartition(n,arr);
    cout<<chek<<endl;


    return 0;
}