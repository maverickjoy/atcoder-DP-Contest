#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;


int n;
int dp[25][1<<22];
int mat[25][25];


ll int kil(int idx, int mask)
{
  if(idx == n)
  {
    if( __builtin_popcount(mask) == n)
      return 1;
    return 0;
  }

  if(dp[idx][mask] != -1)
    return dp[idx][mask];

  dp[idx][mask] = 0;
  for(int j=0;j<n;j++)
  {
    if(mat[idx][j] &&  (mask & (1<<j)) == 0)
      dp[idx][mask] = (dp[idx][mask] + kil(idx+1, mask | (1<<j))) % mod;
  }

  return dp[idx][mask];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>mat[i][j];

  cout<<kil(0, 0)<<endl;

  return 0;
}
