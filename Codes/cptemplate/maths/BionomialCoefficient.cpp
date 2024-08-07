#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace chrono;

#ifndef varunkmr15
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif

using ll = long long;
using ull = unsigned long long;
using lld = long double;

//PBDS
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key

//Constants
constexpr ll INF = 2e18;
constexpr lld EPS = 1e-16;
constexpr ll MOD = 1000000007;
constexpr ll MOD1 = 998244353;
constexpr ll PI = 3.141592653589793238462;

//Macros
#define mii map<int, int>
#define pii pair<int, int>
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yn(f) f?cout<<"YES\n":cout<<"NO\n"
#define int long long

//typedef for using __int128
typedef __int128 ell;
// For printing ell
// Use it without raw input buffer
std::ostream&
operator<<( std::ostream& dest, __int128_t value ) { std::ostream::sentry s( dest ); if ( s ) { __uint128_t tmp = value < 0 ? -value : value; char buffer[ 128 ]; char* d = std::end( buffer ); do {    -- d; *d = "0123456789"[ tmp % 10 ]; tmp /= 10;} while ( tmp != 0 ); if ( value < 0 ) {-- d; *d = '-';} int len = std::end( buffer ) - d; if ( dest.rdbuf()->sputn( d, len ) != len ) {dest.setstate( std::ios_base::badbit );} } return dest; }
// For reading _int128 to_read = read()
// Use it without raw input buffer
__int128 read() { __int128 x = 0, f = 1; char ch = getchar(); while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();} while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();} return x * f; }

//debugger
#ifndef ONLINE_JUDGE
#include "debug_temp.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream& istream, pair<T1, T2>& p) { return (istream >> p.first >> p.second); }

template <typename T> // cin >> vector<T>
istream& operator>>(istream& istream, vector<T>& v) { for (auto& it : v) cin >> it; return istream; }

//Sorting
bool sorta(const pair<int, int> &a, const pair<int, int> &b) {return (a.second < b.second);}
bool sortd(const pair<int, int> &a, const pair<int, int> &b) {return (a.second > b.second);}

//Bits
string decToBinary(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}
ll binaryToDecimal(string n) {string num = n; ll dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += base; base = base * 2;} return dec_value;}

//Check
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(int n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}

// Mathematical functions
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);} // gcd(a,b..n) gives us the minimum multiple we can form by considering all those n numbers some times
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  // only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} // O(sqrt(N)) {Finds count of number coprime with n}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
ll NcR(int n, int r) {if (n < r)return 0; int p = 1, k = 1; if (n - r < r) r = n - r; if (r != 0) {while (r) {p *= n; k *= r; int m = gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; return p;}
// To find modulo inverse, call expo(a,mod-2,mod) if mod is prime else expo(a,phin(mod)-1,mod)
// Use sqrtl() instead of sqrt()

// Calulate in O(log(MOD)) has a precomputation of O(factorial size)
vector<int>factorial(200000, 0);
long long binomial_coefficient(int n, int k) {
    if (n < k)return 0LL;
    return mod_mul(factorial[n], mod_mul(mminvprime(factorial[k], MOD), mminvprime(factorial[n - k], MOD), MOD), MOD);
}

void solve() {
    
}

int32_t main() {
#ifdef varunkmr15
    freopen("Error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start1 = high_resolution_clock::now();
    int t = 1;
    factorial[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        factorial[i] = mod_mul( factorial[i - 1], i, MOD );
    }
    cin >> t;
    for (int testcase = 1; testcase <= t; ++testcase) {
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop1 - start1);
#ifdef varunkmr15
    cerr << "Time taken: " << duration . count() / 1e9 << "s" << endl;
#endif
    return 0;
}
