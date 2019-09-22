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

  int n;
  cin>>n;


  for(int i=1;i<=n;i++)
    cin>>hgt[i];

  dp[0] = 1e15;

  for(int i=2;i<=n;i++)
    dp[i] = min(dp[i-2] + abs(hgt[i-2] - hgt[i]), dp[i-1] + abs(hgt[i-1] - hgt[i]));

  cout<<dp[n]<<endl;

  return 0;
}
