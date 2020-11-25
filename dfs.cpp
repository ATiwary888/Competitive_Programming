#include<iostream>
#include<vector>

using namespace std;

void bfs(vector< vector<int> > &graph,int x,vector<int>&visited){
	vector<int> que;
	que.push_back(x);
	visited[x]=1;
	
	while(que.size()!=0){
		vector<int>::iterator itr;
		itr = que.begin();
		x = *itr;
		cout<<x<<" ";
		que.erase(itr);
		
		for(int i = 0;i<graph[x].size();i++){
			if(visited[graph[x][i]]==0){
				visited[graph[x][i]]=1;
				que.push_back(graph[x][i]);
			}
		}
	}
}

void dfs(vector< vector<int> > &graph,int x,vector<int>&visited){
//	cout<<"MY Graph"<<endl;
	visited[x]=1;
	cout<<x<<" ";
	
	for(int i = 0;i<graph[x].size();i++){
		if(visited[graph[x][i]]==0){
			dfs(graph,graph[x][i],visited);
		}
	}
	
}

int main(){
	int n;
	
	cout<<"Enter Total Nodes"<<endl;
	cin>>n;
	
	vector< vector<int> > graph(n+1);// for one based indexing.
	
	for(int i = 0;i<=n;i++){
		graph[i]=vector<int>(0);
	}
	
	cout<<"Enter Edges."<<endl;
	int a;a = 5;
	while(a!=0){
		int s,v;
		cin>>s>>v;
		graph[s].push_back(v);
		graph[v].push_back(s);// undirected...........
		
		cout<<"Enter any number not zero to continue: ";
		cin>>a;
		
	}
	
	
	cout<<"Enter source"<<endl;
	int x;
	cin>>x;
	vector<int> visited;
	for(int i = 0;i<n+1;i++)
	visited.push_back(0);
	
	dfs(graph,x,visited);
	
	for(int i = 0;i<n+1;i++)
	visited[i]=0;
	cout<<endl;
	bfs(graph,x,visited);
	
	return 0;
}


