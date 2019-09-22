#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;

ll int arr[3005];
ll int dp[3005][3005][2];

ll int kil(int l, int r, int player)
{
  if(l == r)
  {
    if(player)
      return arr[l];
    return -arr[l];
  }

  if(dp[l][r][player] != -1)
    return dp[l][r][player];

  if(player)
  {
    dp[l][r][player] = -1e15;
    dp[l][r][player] = max(dp[l][r][player], kil(l+1, r, 1-player) + arr[l]);
    dp[l][r][player] = max(dp[l][r][player], kil(l, r-1, 1-player) + arr[r]);
  }
  else
  {
    dp[l][r][player] = 1e15;
    dp[l][r][player] = min(dp[l][r][player], kil(l+1, r, 1-player) - arr[l]);
    dp[l][r][player] = min(dp[l][r][player], kil(l, r-1, 1-player) - arr[r]);
  }

  return dp[l][r][player];
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  int n, k, res;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];

  cout<<kil(0, n-1, 1)<<endl;

  return 0;
}
