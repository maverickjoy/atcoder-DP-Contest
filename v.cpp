#include<bits/stdc++.h>
using namespace std;

#define ll long long
// const int mod = 1e9 + 7;
ll int INF = 1e17;



int mod;
vector<int> adj[100005];
ll int dp1[100005];
ll int dp2[100005];
vector<ll int> pre[100005];
vector<ll int> suf[100005];

void dfs1(int node, int pn)
{
  dp1[node] = 1;
  for(int i=0;i<adj[node].size();i++)
    if(adj[node][i] != pn)
    {
      dfs1(adj[node][i], node);
      dp1[node] = (dp1[node] * (1 + dp1[adj[node][i]])) % mod;
    }
  ll int prev=1, front=1;

  pre[node].resize(adj[node].size());
  suf[node].resize(adj[node].size());

  for(int i=0;i<adj[node].size();i++)
  {
    if(adj[node][i] != pn)
    {
      pre[node][i] = (prev * (1+dp1[adj[node][i]])) % mod;
      prev = pre[node][i];
    }
    pre[node][i] = prev;
  }

  for(int i=adj[node].size()-1;i>=0;i--)
  {
    if(adj[node][i] != pn)
    {
      suf[node][i] = (front * (1+dp1[adj[node][i]])) % mod;
      front = suf[node][i];
    }
    suf[node][i] = front;

  }
  return;
}


void dfs2(int node, int pn, int up)
{
  dp2[node] = (1 + up) % mod;

  for(int i=0;i<adj[node].size();i++)
    if(adj[node][i] != pn)
    {
      ll int mul = dp2[node];
      if(i != 0)
        mul = (mul * pre[node][i-1]) % mod;
      if(i != adj[node].size()-1)
        mul = (mul * suf[node][i+1]) % mod;

      dfs2(adj[node][i], node, mul);
    }
  return;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x, y;
  cin>>n>>mod;

  for(int i=0;i<n-1;i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs1(1, -1);
  dfs2(1, -1, 0);

  for(int i=1;i<=n;i++)
    cout<<(dp2[i] * dp1[i]) % mod<<endl;

  return 0;
}
