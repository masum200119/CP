#include<bits/stdc++.h>
using namespace std;
///priority_queue <int, vector<int>, greater<int> > 
#define all(x) x.begin(),x.end()
#define int long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define endl "\n"
#define pb push_back
#define pp pop_back()
#define vtr vector<int>
#define sz size()
int wt[10005];
int val[10005];

int dp[110][1000005];


void MASUM()
{
	#ifndef Masum
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int Knap_Sack(int ind,int value_left)
{
	if(value_left==0)
	{
		return 0;
	}
	if(ind<0)
	{
		return 1e15;
	}
	if(dp[ind][value_left]!=-1)return dp[ind][value_left];
	int ans = Knap_Sack(ind-1,value_left);
	if(value_left-val[ind]>=0)
	{
		ans=min(ans,Knap_Sack(ind-1,value_left-val[ind])+wt[ind]);
	}
	
	return dp[ind][value_left]=ans;
	
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>wt[i]>>val[i];
	}
	int mx=1e5;
	for(int i=mx;i>=0;i--)
	{
		if(Knap_Sack(n-1,i)<=k)
		{
			cout<<i<<endl;
			break;
		}
	}

}
signed main()
{
	MASUM();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int tc;
    // cin>>tc;
    // for(int i=1; i<=tc; i++)
    // {
        solve();
    //}
    return 0;
}
