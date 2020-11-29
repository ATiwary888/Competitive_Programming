#include<bits/stdc++.h>
#define ll long long
using namespace std;
// program to calculate power using binary exponention.
// find pow(a,b)
// time complexity Ologb base 2;
void findbin(ll b,vector<ll> &arr){
	while(b>0){
		arr.push_back(b%2);
		b/=2;
		}	
	}

int main(){
	ll a,b;
	cout<<"Enter two numbers :"<<endl;
	cin>>a>>b;
	vector<ll> arr;
	findbin(b,arr);
	cout<<"lsb>>>>>-binary->>>>>>msb"<<endl;
	for(int i = 0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
	ll my = 1;
	ll ans = 1;
	for(int i = 0;i<arr.size();i++){
		if(i==0){
			my=my*a;
		}else{
		my*=my;
		}
		if(arr[i]==1){
			ans *=my;
		}	
	}
	
	cout<<"Here is required result  a^b : "<<ans;
	
		return 0;
}
