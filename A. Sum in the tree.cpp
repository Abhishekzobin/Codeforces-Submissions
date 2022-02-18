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
vi gr[N];
void solve()
{
	int n;
	cin >> n;
	int val[n + 1];
	memset(val, 0, sizeof val);
	int par[n + 1];
	memset(par, 1, sizeof par);
	for (int i = 2; i <= n; i++)
	{
		cin >> par[i];
		gr[i].pb(par[i]);
		gr[par[i]].pb(i);
	}
	int s[n + 1];
	memset(s, 0, sizeof s);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	val[1] = s[1];
	pra(s,n+1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == -1 && gr[i].size() > 1)
		{
			if (val[i] == 0)
			{
				int num = inf;
				for (auto v : gr[i])
				{
					if (v != par[i])
						num = min(num, s[v]);
				}
				val[i] = num - s[par[i]];
				pr(i, num, s[par[i]],par[i]);
				if (val[i] < 0)
				{
					cout << -1 << endl;
					R;
				}
				bool flag = true;
				for (auto v : gr[i])
				{
					if (v != par[i])
					{
						if (s[v] == num && flag)
						{
							val[v] = 0;
							flag = false;
						}
						else
						{
							val[v] = s[v] - s[par[i]] - val[i];
						}
					}
				}
			}
		}
	}
	pra(val, n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += val[i];
	}
	cout << sum << endl;
}
int32_t main()
{

	livu_sz
	vsingh

	int t = 1;
	//cin>>t;
	while (t--)
		solve();

	return 0;
}