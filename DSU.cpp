#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ll>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ll,ll>
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
ll root(vi &dsu,ll x)
{
    while(dsu[x]!=x)
    {
        dsu[x]=dsu[dsu[x]];
        x=dsu[x];
    }
    return x;
}
void dounion(vi &dsu,ll x,ll y)
{
    ll x1=root(dsu,x);
    ll y1=root(dsu,y);
    dsu[x1]=y1;
    return;
}
ll findifconnected(vi &dsu,ll x,ll y)
{
    if(root(dsu,x)==root(dsu,y)) return 1;
    else return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,t,x,y,z;
    cin>>n>>m;
    vi arr(n);
    vi dsu(n);
    rep(i,n)
    {
        cin>>arr[i];
        dsu[i]=i;
    }
    rep(i,m)
    {
        cin>>t;
        if(t==1)
        {
            cin>>x;
            z=root(dsu,x-1);
        }
        else if(t==2)
        {
            cin>>x>>y;
            dounion(dsu,x-1,y-1);
        }
        else if(t==3)
        {
            cin>>x>>y;
            z=findifconnected(dsu,x-1,y-1);
        }
    }
    rep(i,n) cout<<dsu[i]<<" ";
    return 0;
}
