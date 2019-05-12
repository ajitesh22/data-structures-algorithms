#include<bits/stdc++.h>
using namespace std;
#define max(a,b) a>=b?a:b
const int N=100000;


//DP on trees type 1:simple maximum sum path to the leaf from root



int dp[N],a[N];

vector<vector<int>>adj(N);


void addEdge(int u,int v){

    adj[u].push_back(v);

    adj[v].push_back(u);

}



int dfs(int u,int parent){

    
    dp[u]=a[u];

    	int maxi=0;

    	for(auto child:adj[u]){

        	if(child==parent)continue;
	
        dfs(child,u);
	
        maxi=max(maxi,dp[child]);

    	}

    dp[u]+=maxi;

}



int main(){

    int n,u,v;cin>>n;

     for(int i=0;i<n-1;i++){

        cin>>u>>v;

        addEdge(u,v);

    }


    for(int i=1;i<=n;i++)
	cin>>a[i];

    
dfs(1,0);

    cout<<dp[1];

}
