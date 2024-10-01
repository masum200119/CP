#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define int long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define endl "\n"
#define pb push_back
#define pp pop_back()
#define vtr vector<int>
#define sz size()
int arr[1000005];
int n,k;
int dp[15][10000005];


void MASUM()
{
	#ifndef Masum
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int coin_change(int k,int ind)
{
	if(k==0)return 1;
	if(ind<0)return 0;
	if(dp[ind][k]!=-1)return dp[ind][k];
	int ans =INT_MAX;
	for(int i=0;i<=k;i+=arr[ind])
	{
		if(k-i>=0)
		{
			ans=min(ans,coin_change(k-i,ind-1)+1);
		}
	}
	return dp[ind][k]=ans;
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<coin_change(k,n-1)+1;

}
signed main()
{
	MASUM();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        solve();
    }
    return 0;
}
