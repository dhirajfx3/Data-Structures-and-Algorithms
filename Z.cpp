#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<int>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<int,int>
#define all(c)              c.begin(),c.end()
#define mini(c)             min_element(all(c))
#define maxi(c)             max_element(all(c))
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll Max(ll a, ll b) { return a > b ? a : b; }
ll Min(ll a, ll b) { return a < b ? a : b; }
ll power(ll x, ll y,ll p)
{
    ll res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=((res%p)*(x%p))%p;
        y=y>>1;
        x=((x%p)*(x%p))%p;
    }
    return res;
}
bool isprime(ll n)
{
	if(n==2) return true;
	if(n%2==0) return false;
	for(ll i=3;i<=sqrt(n);i+=2)
    {
		if(n%i==0) return false;
	}
	return true;
}
ll z[1000002];
void create(string s)
{
    ll l=0,r=0;
    rep(i,s.length()-1)
    {
        if(i+1>r)
        {
            l=i+1;
            r=i+1;
            while(r<s.length() && s[r-l]==s[r]) r++;
            z[i+1]=r-l;
            r--;
        }
        else
        {
            ll k=i+1-l;
            if(z[k]<r-i) z[i+1]=z[k];
            else
            {
                l=i+1;
                while(r<s.length() && s[r-l]==s[r]) r++;
                z[i+1]=r-l;
                r--;
            }
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    create(s);
    return 0;
}
