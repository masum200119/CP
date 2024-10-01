class Solution {
public:
    int dp[10000];
    int func(int i,vector<int>&arr)
    {
	    if(dp[i]!=-1)return dp[i];
	    int ans=1;
	    for(int j=0;j<i;j++)
	    {
            if(arr[i]>arr[j])
            {
                ans=max(ans,1+func(j,arr));
            }
	    }
	return dp[i]=ans;
}
    int lengthOfLIS(vector<int>& nums) {

    memset(dp,-1,sizeof(dp));
    int ans=0;
	for(int j=0;j<nums.size();j++)
	{
		ans=max(func(j,nums),ans);
	}
    return ans;
    }
};
