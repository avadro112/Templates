#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define all(v) v.begin(),v.end()
const int MAX_N = 1e5 +5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
//debugs 
#define deb(x) cout<<#x<<" : "<<endl;
#define debu(...) 3000
//loops 
#define fo(i,n) for(int i=0;i<n;i++)
#define kfor(i,k,n) for(int i=k;i<n;i++)
//alternate debug 
#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__,__VAR_ARGS__)
#else
#define debug(...) 3000
#endif

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }
//making read write fucntions to for n number of elements
template<typename...T>void write(T&&...args){((cout<<args<<" "),...);} //multiple type output  using rvalue refernce 
template<typename...T>void read(T&...args){((cin>>args),...);} //multi type input

//**************************************dfs***********************************//
//better comment out if not iin use
//int n, m, vis[MAX_N];
//vector<int> adj[MAX_N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}
//***********************************bfs***********************************//
//better comment out if not iin use
//int n, m;
vector<int> dist;

void bfs(int s) {
    dist.assign(n + 1, -1);
    queue<int> q;
    dist[s] = 0; q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
//*****************LCS*********************************//
int lcs(char *x,char *y,int m,int n){             //only aplied on char[] needed to modify for string 
	if(m==0|n==0)
		return 0;
	if(x[m-1]==y[n-1])								//imagined as 2D matrix with diagonal elements with addiotion of previous values
		return 1+ lcs(x,y,m-1,n-1);
	else 
		return max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));    		//most close approcaht ot 0-1 knapsack 
}
//Making subset sum problem checking only if exist 

bool is_subsetsum(int set[],int n,int sum){
	if(sum==0)
		return true;			//probblem is NP complete so not possible polynomial time compelx.
	if(n==0)					//generally dont ask to optimised
		return false;
	if(set[n-1]>sum)
		return is_subsetsum(set,n-1,sum);
	else
		return is_subsetsum(set,n-1,sum) || is_subsetsum(set,n-1,sum-set[n-1]);
}


//number of path for mXn matrix 
int number_of_path(int m,int n){
	if(n==1 || m==1)
		return 1;
	return number_of_path(m-1,n) + number_of_path(m,n-1); 

//if diagonal movement is allowed then "
	//return number_of_path(m-1,n) + number_of_path(m,n-1) + number_of_path(m-1,n-1);
}
//optimization of above problem using memoization DP
int optimised_numberofpath(int m,int n,int dp[4][4])  ///dirver code require dp[][] of 4
{
	if(n==1||m==1)
		return dp[m][n] =1;
	if(dp[m][n]==0)
		dp[m][n] = optimised_numberofpath(m-1,n,dp) + optimised_numberofpath(m,n-1,dp);  //memoization to skip trivial steps 
	return dp[m][n];
}
//KNAPASCK 0-1 
//using recursion

//
//int max(int a,int b){return (a>b) ? a:b;}
//max() utility incase iostream
int knapsack(int w,int wt[],int val[],int n){  	 				//bruteforce using recursion of2 ^ n

	if(n==0||w==0)
		return 0;
	if(wt[n-1]>w){
		return knapsack(w,wt,val,n-1);
	}
	else
		return max(val[n-1] + knapsack(w-wt[n-1],wt,val,n-1),
			knapsack(w,wt,val,n-1));
}

using namespace std;

int main (void){

}