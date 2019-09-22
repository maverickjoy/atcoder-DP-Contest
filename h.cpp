#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;

ll int dp[1005][1005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof dp);

  int n, m;
  cin>>n>>m;
  char c;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
      cin>>c;
      dp[i][j] = (c == '.') ? 0 : -1;
    }

  dp[0][0] += 1;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(dp[i][j] > 0)
      {
        if(dp[i][j+1] != -1)
          dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
        if(dp[i+1][j] != -1)
          dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
      }

  cout<<dp[n-1][m-1]<<endl;

  return 0;
}
