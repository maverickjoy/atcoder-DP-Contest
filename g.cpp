#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;

vector <int> adj[100005];
int dp[100005];

int dfs(int node)
{
  if(dp[node] != -1)
    return dp[node];

  dp[node] = 0;

  for(int i=0;i<adj[node].size();i++)
      dp[node] = max(dp[node], dfs(adj[node][i]) + 1);

  return dp[node];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  int n, m, x, y;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
  }

  y = 0;
  for(int i=1;i<=n;i++)
    y = max(y, dfs(i));

  cout<<y<<endl;
  return 0;
}
