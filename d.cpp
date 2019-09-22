#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

ll int dp[105][100005];
int wgt[105];
int val[105];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, w;
  cin>>n>>w;

  for(int i=1;i<=n;i++)
    cin>>wgt[i]>>val[i];

  for(int i=1;i<=n;i++)
  {
    dp[i][wgt[i]] = val[i];
    for(int j=1;j<=w;j++)
    {
      dp[i][j] = max(dp[i][j], dp[i-1][j]);
      if(j - wgt[i] > 0)
        dp[i][j] = max(dp[i][j], dp[i-1][j-wgt[i]] + val[i]);
      dp[i][j] = max(dp[i][j], dp[i][j-1]);
    }
  }

  cout<<dp[n][w]<<endl;

  return 0;
}
