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
