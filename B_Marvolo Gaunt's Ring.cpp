#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define mp make_pair
int minleft[100005],minright[100005],maxleft[100005],maxright[100005],a[100005];
int main()
{
	int i,j,k;
	int n,p,q,r;
	cin>>n>>p>>q>>r;
	for(i=1;i<=n;i++)
		sd(a[i]);
	minleft[1]=maxleft[1]=a[1];
	minright[n]=maxright[n]=a[n];
	for(i=2;i<=n;i++)
	{
		minleft[i]=min(minleft[i-1],a[i]);
		maxleft[i]=max(maxleft[i-1],a[i]);
	}
	for(i=n-1;i>=1;i--)
	{
		minright[i]=min(minright[i+1],a[i]);
		maxright[i]=max(maxright[i+1],a[i]);
	}
	ll ans=-3e18;
	for(i=1;i<=n;i++)
	{
		ll leftval = (p<0) ? 1ll*minleft[i]*p : 1ll*maxleft[i]*p;
		ll rightval = (r<0) ? 1ll*minright[i]*r : 1ll*maxright[i]*r;
		ans=max(ans,leftval+rightval+1ll*q*a[i]);
	}
	cout<<ans<<endl;
	return 0;
}