#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;


int n;
int arr[105];
int dp[100005][2];

int kil(int k, int player)
{
  if(k <= 0)
  {
    // which ever players turn he looses
    return 1 - player;
  }

  if(dp[k][player] != -1)
    return dp[k][player];

  int res = 1-player;
  for(int i=0;i<n;i++)
  {
    if(arr[i] <= k)
    {
      res = kil(k-arr[i], 1-player);
      if(res == player)
        break;
    }
  }
  dp[k][player] = res;
  return dp[k][player];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);

  int k, res;
  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>arr[i];

  res = kil(k, 1);

  cout<<((res == 1) ? "First" : "Second")<<endl;

  return 0;
}
