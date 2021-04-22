#include<bits/stdc++.h>
using namespace std;

int find_multiplication_cost(vector<int>arr,int st,int end){
    if(st==end){return 0;}
     int k;
    int min = INT_MAX;
    int count;
 
    // starting from index =1 ,i.e. st, recursively calculating all 
    // possible cost combination.
    for (k = st; k < end; k++)
    {
        count = find_multiplication_cost(arr, st, k)
                + find_multiplication_cost(arr, k + 1, end)
                + arr[st - 1] * arr[k] * arr[end];
 
        if (count < min)
            min = count;
    }
 
    // Return minimum count
    return min;
}

int main(){
    int t;
    cout<<"Enter a number (no of times you want to calculate:)"<<endl;
    cin>>t;
    while(t--){
        cout<<"Enter no of matrix +1 :"<<endl;
        int n;cin>>n;
        cout<<"Enter matrix order of n(means n-1 matrices) numbers"<<endl;

        vector<int>arr;
        for(int i = 0;i<n;i++){
            int a;cin>>a; arr.push_back(a);
        }
        int st = 1;       
        int cost = find_multiplication_cost(arr,st,n-1);

        cout<<cost<<endl;


    }

    return 0;
}