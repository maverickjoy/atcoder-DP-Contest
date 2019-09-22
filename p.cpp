#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;

vector <int> adj[100005];
ll int dp[100005][2];

ll int dfs(int node, int pn, int colour)
{
  if(dp[node][colour] != -1)
    return dp[node][colour];

  dp[node][colour] = 1;

  for(int i=0;i<adj[node].size();i++)
    if(adj[node][i] != pn)
    {
      if(colour)
      {
        dp[node][colour] = (dp[node][colour] * dfs(adj[node][i], node, 1-colour)) % mod;
      }
      else
      {
        ll int res = (dfs(adj[node][i], node, colour) + dfs(adj[node][i], node, 1-colour)) % mod;
        dp[node][colour] = (dp[node][colour] * res) % mod;
      }
    }

  return dp[node][colour] % mod;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);
  int n, x, y;
  cin>>n;

  for(int i=0;i<n-1;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  cout<<(dfs(1, -1, 0) + dfs(1, -1, 1)) % mod <<endl;

  return 0;
}
