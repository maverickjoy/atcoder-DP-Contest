#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;


int k;
string s;
ll int dp[10005][105][2];


ll int kil(int idx, int rem, int small)
{
  if(idx == s.length())
  {
    if(rem == 0)
      return 1;
    return 0;
  }
  if(dp[idx][rem][small] != -1)
    return dp[idx][rem][small];

  dp[idx][rem][small] = 0;

  for(int i=0;i<10;i++)
  {
    if(s[idx] - '0' < i && !small)
      break;
    if(s[idx] - '0' == i && !small)
      dp[idx][rem][small] = (dp[idx][rem][small] + kil(idx + 1, (rem + i) % k, 0)) % mod;
    else
      dp[idx][rem][small] = (dp[idx][rem][small] + kil(idx + 1, (rem + i) % k, 1)) % mod;
  }
  return dp[idx][rem][small] % mod;
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);
  cin>>s;
  cin>>k;
  int res = kil(0, 0, 0) - 1;
  if(res == -1)
    res = mod - 1;
  cout<<res<<endl;

  return 0;
}
