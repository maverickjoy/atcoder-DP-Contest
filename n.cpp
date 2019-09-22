#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;

int arr[405];
ll int dp[405][405];
ll int psum[405];

ll int kil(int s, int l)
{
  if(s == l)
  {
    return 0;
  }

  if(dp[s][l] != -1)
    return dp[s][l];

  dp[s][l] = 1e15;
  for(int i=s;i<l;i++)
  {
    dp[s][l] = min(dp[s][l], kil(s, i) + kil(i+1, l));
  }
  dp[s][l] += psum[l] - psum[s-1];

  return dp[s][l];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    psum[i] = psum[i-1] + arr[i];
  }
  cout<<kil(1, n)<<endl;

  return 0;
}
