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
int dp[10000005];


void MASUM()
{
	#ifndef Masum
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}
int func(int ind,int k)
{
	if(k==0)return 1;
	if(ind<0)return 0;
	if(dp[k]!=-1)return dp[k];
	int ans =INT_MAX;
	for(int i=0;i<=k;i+=arr[ind])
	{
	
		ans=min(ans,1+func(ind-1,k-i));
		
	}
	return dp[k]=ans;
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<func(n-1,k);

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
