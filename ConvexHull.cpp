#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(ll i=0;i<n;i++)
#define hell                1000000007LL
#define vi                  vector<ld>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<ld,ld>
#define all(c)              c.begin(),c.end()
#define sz(c)               c.size()
pii p;
bool cmp(pii &a,pii &b)
{
    if(((a.fi-p.fi)*(b.se-a.se)-(a.fi-b.fi)*(p.se-a.se))>0) return true;
    else return false;
}
void findHull(vector< pii > &ans,vector< pii > &arr,pii l,pii r)
{
    if(!sz(arr)) return;
    else
    {
        ll it=0;
        ld d=0;
        rep(i,sz(arr))
        {
            ld c=(1.0*abs((arr[i].se-l.se)*(r.fi-l.fi)-(r.se-l.se)*(arr[i].fi-l.fi)))/sqrt(1.0*(((l.fi-r.fi)*(l.fi-r.fi))+(l.se-r.se)*(l.se-r.se)));
            if(c>d)
            {
                d=c;
                it=i;
            }
        }
        ans.pb(arr[it]);
        vector< pii > arr1,arr2;
        ll z1=(r.se-l.se)*(arr[it].fi-l.fi)-(arr[it].se-l.se)*(r.fi-l.fi);
        ll z2=(l.se-arr[it].se)*(r.fi-arr[it].fi)-(r.se-arr[it].se)*(l.fi-arr[it].fi);
        rep(i,sz(arr))
        {
            if(i!=it)
            {
                if(((arr[i].se-l.se)*(arr[it].fi-l.fi)-(arr[it].se-l.se)*(arr[i].fi-l.fi))*z1<0) arr1.pb(arr[i]);
                else if(((arr[i].se-arr[it].se)*(r.fi-arr[it].fi)-(r.se-arr[it].se)*(arr[i].fi-arr[it].fi))*z2<0) arr2.pb(arr[i]);
            }
        }
        findHull(ans,arr1,l,arr[it]);
        findHull(ans,arr2,arr[it],r);
        return;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ld n;
    cin>>n;
    if(n!=0)
    {
        vector< pii > arr(n),ans,arr1,arr2;
        rep(i,n) cin>>arr[i].fi>>arr[i].se;
        sort(all(arr));
        ans.pb(arr[0]);
        ans.pb(arr[n-1]);
        rep(i,n-2)
        {
            pii z=arr[i+1];
            if((z.se-arr[0].se)*(arr[n-1].fi-arr[0].fi)>(arr[n-1].se-arr[0].se)*(z.fi-arr[0].fi)) arr1.pb(z);
            else if((z.se-arr[0].se)*(arr[n-1].fi-arr[0].fi)<(arr[n-1].se-arr[0].se)*(z.fi-arr[0].fi)) arr2.pb(z);
        }
        findHull(ans,arr1,arr[0],arr[n-1]);
        findHull(ans,arr2,arr[n-1],arr[0]);
        sort(all(ans));
        p=ans[0];
        sort(ans.begin(),ans.end(),cmp);
        cout<<sz(ans)<<endl;
        rep(i,sz(ans)) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    }
    return 0;
}
