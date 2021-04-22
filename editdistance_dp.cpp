// class lass based solution of edit distance for sample 
// string s = geek;
// string t = gesek;

class Solution {
  public:
    int editDistance(string s, string t) {
        
        int row = s.size();
        int col = t.size();
        
        int dp[row+1][col+1];
        
        for(int i = 0;i<=row;i++){
            for(int j = 0;j<=col;j++){
                
                if(i==0){
                    dp[i][j] = j;continue;
                    // cout<<dp[i][j]<<endl;
                }
                if(j==0){
                    dp[i][j]=i;continue;
                    // cout<<dp[i][j]<<endl;
                }
                
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int a = dp[i-1][j];
                    int b = dp[i][j-1];
                    int c = dp[i-1][j-1];
                    int min = a;
                    if(b<min){
                        min=b;
                    }
                    if(c<min){
                        min = c;
                    }
                    dp[i][j]= min+1;
                    
                }
                
            }
        }
        for(int i = 0;i<=row;i++){
            // for(int j = 0;j<=col;j++){
            //     cout<<dp[i][j]<<" ";
            // }cout<<endl;
        }
        
        return dp[row][col];
        // Code here
    }
};