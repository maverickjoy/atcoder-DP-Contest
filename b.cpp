#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

int hgt[100005];
ll int dp[100005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin>>n>>k;

  for(int i=1;i<=n;i++)
    cin>>hgt[i];

  dp[0] = 1e17;

  for(int i=2;i<=n;i++)
  {
    dp[i] = 1e17;
    for(int j=1;j<=k;j++)
      if(i-j >= 0)
        dp[i] = min(dp[i], dp[i-j] + abs(hgt[i-j] - hgt[i]));
  }

  cout<<dp[n]<<endl;

  return 0;
}
