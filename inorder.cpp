#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

void inorder(vector<ll> &nodes,vector<ll>  &left,vector<ll> &right,ll root_ind){
	if(root_ind==-1)return;

	inorder(nodes,left,right,left[root_ind]);
//	result.push_back(nodes[root_ind]);
	cout<<nodes[root_ind]<<" ";
	inorder(nodes,left,right,right[root_ind]);
	return ;
}

	
void preorder(vector<ll>&nodes,vector<ll>&left,vector<ll>&right,ll root_ind){
	if(root_ind==-1)return;
	
	cout<<nodes[root_ind]<<" ";
	preorder(nodes,left,right,left[root_ind]);
	preorder(nodes,left,right,right[root_ind]);
	
	return ;
}

void postorder(vector<ll>& nodes,vector<ll>&left,vector<ll>right,int root_ind){
	if(root_ind==-1)return;
	
	postorder(nodes,left,right,left[root_ind]);
	postorder(nodes,left,right,right[root_ind]);
	cout<<nodes[root_ind]<<" ";
	
	return ;
}



int main(){
//	ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
	ll n;cin>>n;
	vector<ll> nodes(n);vector <ll> left(n);vector<ll> right(n);
	
	for(int i = 0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		nodes[i]=a;
		left[i]=b;
		right[i]=c;
//		nodes.push_back(a);left.push_back(b);right.push_back(c);
	}
	
	vector<ll>result;     // to store inorder result
	inorder(nodes,left,right,0);
	cout<<endl;
	preorder(nodes,left,right,0);
	cout<<endl;
	postorder(nodes,left,right,0);
	
	
	return 0;
	}

