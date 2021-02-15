// LONGEST COMMON SUBSEQUENCE
// RECURSIVE SOLUTION

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

ll lcs(char *a, ll n, char *b, ll m){
    if(n==0 || m==0)
        return 0 ;
    if(a[n-1]==b[m-1])
        return 1+lcs(a, n-1, b, m-1) ;
    else
        return max(lcs(a, n, b, m-1), lcs(a, n-1, b, m)) ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll n ;
    cin >> n ;
    char a[n] ;
    for(ll i=0; i<n; i++)
        cin >> a[i] ;
    
    ll m ;
    cin >> m ;
    char b[m] ;
    for(ll i=0; i<m; i++)
        cin >> b[i] ;
    
    ll ans = lcs(a, n, b, m) ;
    cout << ans << endl ;
    
    return 0 ;
}

// LONGEST COMMON SUBSEQUENCE 
// DYNAMMIC PROGRAMMING VERSION

#include <bits/stdc++.h>

using namespace std ;
#define ll long long int

ll lcs(char *a, ll m, char *b, ll n){
    ll dp[m + 1][n + 1] ;
    for(ll i=0; i<=m; i++){
        for(ll j=0; j<=n; j++){    
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1 ;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) ;
        }
    }  
    
    return dp[m][n] ;
}

signed main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    
    ll m ;
    cin >> m ;
    char a[m] ;
    for(ll i=0; i<m; i++)
        cin >> a[i] ;
    
    ll n ;
    cin >> n ;
    char b[n] ;
    for(ll i=0; i<n; i++)
        cin >> b[i] ;
    
    ll ans = lcs(a, m, b, n) ;
    cout << ans << endl ;

    return 0 ;
}