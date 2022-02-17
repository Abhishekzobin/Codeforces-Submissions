// TC
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define fl(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define e1(a) \
    int a;    \
    cin >> a;
#define e2(a, b) \
    int a, b;    \
    cin >> a >> b;
#define e3(a, b, c) \
    int a, b, c;    \
    cin >> a >> b >> c;
#define av(arr, n)      \
    vector<int> arr(n); \
    fl(i, 0, n) cin >> arr[i];
#define aa(arr, n) \
    int arr[n];    \
    fl(i, 0, n) cin >> arr[i];
#define es(s)  \
    string(s); \
    cin >> (s);
#define vi vector<int>
#define vvi vector<vector<int>>
#define mod 1000000007
#define ff first
#define ss second
#define inf 10e15
#define pii pair<int, int>
#define mii map<int, int>
#define vl(n) cout << n << "\n"
#define vs(n) cout << n << " "
#define el cout << "\n"
#define UB upper_bound
#define LB lower_bound
#define vn(n) cout << n
#define dsc greater<int>()
#define ps(x, y) fixed << setprecision(y) << x
#define R return
#define livu_sz ios_base::sync_with_stdio(false);
#define vsingh cin.tie(NULL);
#define B break
#define C continue
int dmod(int x) {
	return ((x + mod) % mod);
}
int power(int x, int y)
{
	int res = 1;
	while (y)
	{
		if (y & 1) res = (res * x) % mod;
		x = (x * x) % mod; y >>= 1;
	}
	return res;
}
#define YC cout << "YES" \
                << "\n"
#define YS cout << "Yes" \
                << "\n"
#define NC cout << "NO" \
                << "\n"
#define NS cout << "No" \
                << "\n"
#define lcm(a, b) (a / __gcd(a, b)) * b
#define pa(a)        \
    for (auto e : a) \
    cout << e << " "
const int N = 1e6;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#ifndef ONLINE_JUDGE
#define pra(a, n)               \
    cerr << #a << ":";          \
    for (int i = 0; i < n; i++) \
        cerr << a[i] << " ";    \
    cerr << endl;
#define prm(mat, row, col)            \
    cerr << #mat << ":\n";            \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cerr << mat[i][j] << " "; \
        cerr << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p)
{
	return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class T>
void dbs(string str, T t) { cerr << str << ":" << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
	int idx = str.find(',');
	cerr << str.substr(0, idx) << ":" << t << ",";
	dbs(str.substr(idx + 1), s...);
}
#else
#define pr(...) \
    {           \
    }
#define pra(a, n) \
    {             \
    }
#define prm(mat, row, col) \
    {                      \
    }
#endif


// No matter how great the defeat is,
// if I am not the one winning,
// the war has not ended yet.



// Template ends
vvi gr;
int is[26][26];
int vis[27];
vi ans;
int indg[26];
bool dfs(int src,int par)
{
	vis[src]=1;
	ans.pb(src);
	for(auto v:gr[src])
	{
		pr(v,vis[v],src,par);
		if(vis[v]==0)
		{
			bool mila=dfs(v,src);
			if(mila)
			{
				return true;
			}
		}
		else if(vis[v]==1 && v!=par)
		{
			return true;
		}
	}
	return false;

}
void solve()
{
	es(s);
	memset(indg,0,sizeof indg);
	memset(is,0,sizeof is);
	memset(vis,0,sizeof vis);
	ans.resize(0);
	gr.resize(0);
	gr.resize(26);
	int n=s.size();
	for(int i=1;i<n;i++)
	{
		int a=s[i]-'a';
		int b=s[i-1]-'a';
		int mn=min(a,b);
		int mx=max(a,b);  
		if(is[mn][mx]==0)
		{
			gr[a].pb(b);
			gr[b].pb(a);
			is[mn][mx]=1;
			indg[a]++;
			indg[b]++; 
		}
	}
	pra(indg,26);
	for(int i=0;i<26;i++)
	{
		if(indg[i]>=3)
		{
			pr(indg[i],i);
			cout<<"NO"<<endl;
			R;
		}
	}
	pra(gr,26);
	bool flag=true;
	for(int i=0;i<26;i++)
	{
		if(vis[i]==0)
		{
			if(indg[i]==1)
			{
				flag=false;
				bool mila=dfs(i,26);
				if(mila)
				{
					cout<<"NO"<<endl;
					R;
				}
			}
		}
	}
	if(s.size()==1)
	{
		flag=false;
	}
	if(flag)
	{
		cout<<"NO"<<endl;
		R;
	}
	cout<<"YES"<<endl;
	pr(ans);
	for(auto v:ans)
	{
		cout<<char(v+'a');
	}
	for(int i=0;i<26;i++)
	{
		if(vis[i]==0)
		{
			cout<<char(i+'a');
		}
	}
	cout<<endl;
}
int32_t main()
{

	livu_sz
	vsingh

	int t = 1;
	cin>>t;
	while (t--)
		solve();

	return 0;
}