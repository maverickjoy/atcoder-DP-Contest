#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;


double arr[3005];
double dp[3005][3005];
int n;

double kil(int idx, int heads)
{
  if(idx == n)
  {
    if(heads > n - heads)
      return 1;
    return 0;
  }

  if(dp[idx][heads] != -1)
    return dp[idx][heads];

  dp[idx][heads] = 0;
  dp[idx][heads] += arr[idx] * kil(idx+1, heads+1);
  dp[idx][heads] += (1-arr[idx]) * kil(idx+1, heads);

  return dp[idx][heads];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];

  for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
        dp[i][j] = -1;

  cout<<setprecision(10);
  cout<<kil(0, 0)<<endl;

  return 0;
}
