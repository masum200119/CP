#include<bits/stdc++.h>
using namespace std;
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
int Knap_Sack(int ind,int k)
{
	if(k==0)
	{
		return 0;
	}
	if(ind<0)
	{
		return 0;
	}
	if(dp[ind][k]!=-1)return dp[ind][k];
	int ans=Knap_Sack(ind-1,k);
	if(k-wt[ind]>=0)
	{
		ans=max(ans,Knap_Sack(ind-1,k-wt[ind])+val[ind]);
	}
	return dp[ind][k]=ans;
	
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
	cout<<Knap_Sack(n-1,k);

}
signed main()
{
	MASUM();
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // int tc;
    // cin>>tc;
    // for(int i=1; i<=tc; i++)
    // {
        solve();
    //}
    return 0;
}
