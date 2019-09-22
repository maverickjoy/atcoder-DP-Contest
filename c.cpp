#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;

ll int dp[100005][3];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;

  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<3;j++)
    {
      cin>>x;
      for(int k=0;k<3;k++)
        if(j != k)
          dp[i][j] = max(dp[i][j], dp[i-1][k] + x);
    }
  }

  cout<<max(dp[n][0], max(dp[n][1], dp[n][2]))<<endl;

  return 0;
}
