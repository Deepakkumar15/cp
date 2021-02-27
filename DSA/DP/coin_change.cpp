// COIN CHANGE PROBLEM
// RECURSION + MEMOIZATION SOLUTION
class Solution{
    public:
        long long int dp[1005][1005] ;
        Solution(){
            memset(dp, -1, sizeof(dp)) ;
        }
                
        long long int count( int S[], int m, int n ){
            if(n==0) 
                return 1 ;
            if(m==0)
                return 0 ;
            
            if(dp[m][n] != -1)
                return dp[m][n] ;
                
            if(S[m-1]<=n)
                return dp[m][n] = count(S, m-1, n) + count(S, m, n-S[m-1]) ;
            else
                return dp[m][n] = count(S, m-1, n) ;
            
        }
};



// ITERATIVE DP VERSION
class Solution{
    public:
                
        long long int count( int S[], int m, int n ){
            long long int dp[m+1][n+1] ;
            for(int i=0; i<=m; i++)
                dp[i][0]=1 ;
            for(int j=1; j<=n; j++)
                dp[0][j]=0 ;
                
            for(int i=1; i<=m; i++){
                for(int j=1; j<=n; j++){
                    if(S[i-1]<=j)
                        dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]] ;
                    else
                        dp[i][j] = dp[i-1][j] ;
                }
            }    
            
            return dp[m][n] ;
            
        }

};
