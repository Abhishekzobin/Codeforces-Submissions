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
int a[111], b[111];

bool f[111];
int n = 0;
void dfs(int i)
{
	f[i] = true;
	for (int k = 1; k <= n; k++)
	{
		if (f[k])
			continue;
		if (a[i] > a[k] && a[i] < b[k])
			dfs(k);
		else if (b[i] > a[k] && b[i] < b[k])
			dfs(k);
	}
}
int k;

void solve()
{
	cin >> k;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= k; i++)
	{
		int x, y, m;
		cin >> m;
		if (m == 1)
		{
			n++;
			cin >> a[n];
			cin >> b[n];
		}
		if (m == 2)
		{
			cin >> x;
			cin >> y;
			memset(f, 0, sizeof(f));
			dfs(x);
			if (f[y])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
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