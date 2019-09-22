#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;


struct Node {
  Node(int weight, int solid, int val)
  {
    this->weight = weight;
    this->solid = solid;
    this->val = val;
  }
  int weight;
  int solid;
  int val;
};

vector <Node> arr;
ll int dp[1005][10005];


bool cmp(Node n1, Node n2)
{
  if(n1.solid + n1.weight < n2.solid + n2.weight)
    return true;
  return false;
}


ll int kil(int idx, int weight)
{
  if(weight >=10005)
    return 0;

  if(idx == arr.size())
    return 0;

  if(dp[idx][weight] != -1)
    return dp[idx][weight];

  dp[idx][weight] = 0;
  dp[idx][weight] = max(dp[idx][weight], kil(idx+1, weight));
  if(arr[idx].solid >= weight)
    dp[idx][weight] = max(dp[idx][weight], kil(idx+1, weight + arr[idx].weight) + arr[idx].val);

  return dp[idx][weight];
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof dp);
  int n, x, y, z;
  cin>>n;

  for(int i=0;i<n;i++)
  {
    cin>>x>>y>>z;
    arr.push_back(Node(x, y, z));
  }
  sort(arr.begin(), arr.end(), cmp);
  cout<<kil(0, 0)<<endl;

  return 0;
}
