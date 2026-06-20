class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(triangle.size());
        for(int i=0;i<triangle.size();i++){
            dp[i]=vector<int> (triangle[i].size(),-1);
        }
        for(int j=0;j<triangle[n-1].size();j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int first = dp[i+1][j];
                int sec = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] +min(first,sec);
            }
        }
        return dp[0][0];
    }
};
