#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9 + 7;
ll int INF = 1e17;


int cost[200005];
int harr[200005];
ll int dp[200005];
ll int seg[800005];


void update(int node, int start, int end, int l, int r, ll int val)
{
  if(end < l || start > r)
    return;

  if(start == end)
    seg[node] = val;
  else
  {
    int mid = (start + end) / 2;
    update(node*2, start, mid, l, r, val);
    update(node*2 + 1, mid+1, end, l, r, val);
    seg[node] = max(seg[node*2], seg[node*2+1]);
  }
  return;
}

ll int query(int node, int start, int end, int l, int r)
{
  if(end < l || start > r)
    return 0;

  if(l <= start && end <= r)
    return seg[node];

  ll int q1, q2;
  int mid = (start + end) / 2;
  q1 = query(node*2, start, mid, l, r);
  q2 = query(node*2+1, mid+1, end, l, r);

  return max(q1, q2);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  ll int y;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>harr[i];
  for(int i=0;i<n;i++)
    cin>>cost[i];

  for(int i=0;i<n;i++)
  {
    y = query(1, 0, n, 0, harr[i]);
    dp[harr[i]] = y + cost[i];
    update(1, 0, n, harr[i], harr[i], dp[harr[i]]);
  }

  for(int i=0;i<=n;i++)
    y = max(y, dp[i]);
  cout<<y<<endl;

  return 0;
}
