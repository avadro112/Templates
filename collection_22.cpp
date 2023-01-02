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


using namespace std;

int main (void){

}