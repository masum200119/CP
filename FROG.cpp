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

int func(int i)
{
	if(i==0)return 0;
	if(dp[i]!=-1)return dp[i];
	int cost=INT_MAX;
	for(int j=1;j<=k;j++)
	{
		if(i-j>=0)
		{
			cost=min(cost,func(i-j)+abs(arr[i]-arr[i-j]));
		}
		
	}
	return dp[i]=cost;
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<func(n-1)<<endl;

}
signed main()
{
	
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
        solve();
    
    return 0;
}
