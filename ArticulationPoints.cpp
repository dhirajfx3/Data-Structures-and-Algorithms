#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define inf                 (ll)1e15
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
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
    if(n<2) return false;
    else if(n==2) return true;
    else if(n%2==0) return false;
    else
    {
        ll z=sqrt(n);
        rep(i,z-1) if(n%(i+2)==0) return false;
        return true;
    }
}
void dfs(vii &g,vi &vis,vi &disc,vi &low,vi &ans,ll c,ll p,ll st,ll h)
{
    disc[c]=h;
    vis[c]=1;
    low[c]=h;
    ll cnt=0,z=inf;
    for(auto i:g[c])
    {
        if(!vis[i])
        {
            cnt++;
            dfs(g,vis,disc,low,ans,i,c,st,h+1);
            low[c]=min(low[c],low[i]);
            if(low[i]>=disc[c] && c!=st) ans[c]=1;
        }
        if(i!=p) low[c]=min(low[c],disc[i]);
    }
    if(cnt>1 && c==st) ans[c]=1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vii g(n);
    rep(i,m)
    {
        ll u,v;
        cin>>u>>v;
        g[--u].pb(--v);
        g[v].pb(u);
    }
    vi vis(n,0),disc(n,inf),low(n,inf),ans(n,0);
    rep(i,n)
    {
        if(!vis[i])
        {
            dfs(g,vis,disc,low,ans,i,i,i,1LL);
        }
    }
    rep(i,n) cout<<ans[i]<<" ";
    return 0;
}
