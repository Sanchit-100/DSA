#include <iostream>
#define ll long long

using namespace std;

//You have to tile a N*M wall with bricks of dimension M*1
//you can place brick vertically or horizontally
//find the no. of ways to do so


// Recurrence relation
// f(N)=f(N-1)+f(N-M)

ll mod=1e9+7;
int count_bricks(ll n, ll m, ll dp[])
{
    // base case
    if (n <= m-1)
    {
        return 1;
    }

    //lookup case
    if(dp[n]!=-1) return dp[n];

    // rec case
    ll vertical = count_bricks(n - 1,m,dp);
    ll horizontal = count_bricks(n - m,m,dp);
    dp[n]=(vertical + horizontal)%mod;
    return dp[n];
}

int main()
{	
	int t;
	cin>>t;
    ll n,m;
	while(t--){
		cin >> n >> m;
        ll* dp=new ll[n+1];
        for(ll i=0;i<n+1;i++){
            dp[i]=-1;
        }
    	cout<<count_bricks(n,m,dp)<<endl;
	}
    
    return 0;
}