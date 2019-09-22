#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;


int n;
int arr[105];
ll int dp[105][100005];
ll int psum[105][100005];

int kil(int idx, int kleft)
{
  if(idx == n)
  {
    if(kleft == 0)
      return 1;
    return 0;
  }
  if(dp[idx][kleft] != -1)
    return dp[idx][kleft];

  dp[idx][kleft] = 0;
  for(int i=0;i<=min(arr[idx], kleft);i++)
    dp[idx][kleft] += kil(idx+1, kleft-i);

  return dp[idx][kleft];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, res;
  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>arr[i];

   // iterative
   memset(dp, 0, sizeof dp);
   dp[n][0] = 1;

   for(int kleft = 0; kleft <= k; kleft ++)
     psum[n][kleft] = ((kleft > 0) ? psum[n][kleft - 1] : 0) + dp[n][kleft];

   for(int idx = n-1; idx>=0; idx--)
   {
     for(int kleft = 0; kleft <= k; kleft ++)
     {
       // for(int i=0;i<=min(arr[idx], kleft);i++)
       //   dp[idx][kleft] += dp[idx+1][kleft-i];
       //   // sum  dp[kleft] + dp[kleft-1] + dp[kleft-2] .... dp[kleft-min(arr[idx], kleft)]
       //   // dp[k] .... dp[0]
       int y = min(arr[idx], kleft);
       dp[idx][kleft] = (psum[idx+1][kleft] + mod - ((kleft - y) > 0 ? psum[idx+1][kleft - y -1] : 0)) % mod;
       psum[idx][kleft] = (((kleft > 0) ? psum[idx][kleft - 1] : 0) + dp[idx][kleft]) % mod;
     }
   }

   // recursive
   // memset(dp, -1, sizeof dp);
   // cout<<kil(0, k)<<endl;

   cout<<dp[0][k]<<endl;

   return 0;
}
