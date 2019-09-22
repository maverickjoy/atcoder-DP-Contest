#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;

int dp[3005][3005];
string s1, s2;

int kil(int idx1, int idx2)
{
  if(idx1 == s1.length() || idx2 == s2.length())
    return 0;

  if(dp[idx1][idx2] != -1)
    return dp[idx1][idx2];

  if(s1[idx1] == s2[idx2])
    dp[idx1][idx2] = max(dp[idx1][idx2], kil(idx1+1, idx2+1) + 1);
  else
  {
    dp[idx1][idx2] = max(dp[idx1][idx2], kil(idx1, idx2+1));
    dp[idx1][idx2] = max(dp[idx1][idx2], kil(idx1+1, idx2));
  }
  return dp[idx1][idx2];
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string res="";

  memset(dp, -1, sizeof dp);
  cin>>s1>>s2;

  // recursive
  // kil(0, 0);

  // iterative
  memset(dp, 0, sizeof dp);

  for(int idx1 = s1.length()-1; idx1>=0; idx1--)
    for(int idx2 = s2.length()-1; idx2>=0; idx2--)
    {
      if(s1[idx1] == s2[idx2])
        dp[idx1][idx2] = max(dp[idx1][idx2], dp[idx1+1][idx2+1] + 1);
      else
      {
        dp[idx1][idx2] = max(dp[idx1][idx2], dp[idx1][idx2+1]);
        dp[idx1][idx2] = max(dp[idx1][idx2], dp[idx1+1][idx2]);
      }
    }



  int idx1=0, idx2=0;

  while(idx1 != s1.length() && idx2 != s2.length())
  {
    if(s1[idx1] == s2[idx2])
    {
      res += s1[idx1];
      idx1 += 1;
      idx2 += 1;
    }
    else
    {
      if(dp[idx1][idx2] == dp[idx1+1][idx2] && dp[idx1][idx2] != -1)
        idx1 += 1;
      else
        idx2 += 1;
    }
  }

  cout<<res<<endl;
  return 0;
}
