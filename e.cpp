#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;


ll int INF = 1e17;
ll int dp[105][100005];
int wgt[105];
int val[105];

ll int kil(int idx, int value)
{
  if(value < 0)
    return INF;

  if(idx == 0)
  {
    if(value == 0)
      return 0;
    return INF;
  }

  if(dp[idx][value] != -1)
    return dp[idx][value];

  dp[idx][value] = INF;

  dp[idx][value] = min(dp[idx][value], kil(idx-1, value));
  dp[idx][value] = min(dp[idx][value], kil(idx-1, value - val[idx]) + wgt[idx]);

  return dp[idx][value];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  int n, w;
  cin>>n>>w;
  for(int i=1;i<=n;i++)
    cin>>wgt[i]>>val[i];

  ll int res, ans=0;
  for(int i=100000;i>=0;i--)
  {
    res = kil(n, i);
    if(res <= w)
    {
      ans = i;
      break;
    }
  }

  cout<<ans<<endl;

  return 0;
}
