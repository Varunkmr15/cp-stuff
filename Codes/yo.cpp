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
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
     
constexpr ll INF = 2e18;
constexpr lld EPS = 1e-16;
constexpr ll MOD = 1000000007;
constexpr ll MOD1 = 998244353;
constexpr ll PI = 3.141592653589793238462;

#define mii map<int, int> 
#define pii pair<int, int>
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

//typedef for using __int128 
typedef __int128 ell;

// For printing ell
// Use it without raw input buffer
std::ostream&
operator<<( std::ostream& dest, __int128_t value ) {
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value; char buffer[ 128 ];
        char* d = std::end( buffer );
        do {    -- d; *d = "0123456789"[ tmp % 10 ]; tmp /= 10;} while ( tmp != 0 );
        if ( value < 0 ) {-- d; *d = '-';}
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {dest.setstate( std::ios_base::badbit );}
    }
    return dest;
}

// For reading _int128 to_read = read()
// Use it without raw input buffer
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

#ifndef ONLINE_JUDGE
#include "debug_temp.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream& istream, pair<T1, T2>& p){
    return (istream >> p.first >> p.second);
}
 
template <typename T> // cin >> vector<T>
istream& operator>>(istream& istream, vector<T>& v){
    for (auto& it : v)
        cin >> it;
    return istream;
}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} // O(sqrt(N)) {Finds count of number coprime with n}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}        
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}   
ll NcR(int n, int r) {int p = 1, k = 1; if (n - r < r) r = n - r; if (r != 0) {while (r) {p *= n; k *= r; int m = gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; return p;}

/*
dfs function to calculate distance to
a node 
*/

void dfs(int x,int p,vector<int>&depth,vector<vector<int>>&graph){
    for(auto e : graph[x]){
        if(e != p){
            depth[e] = depth[x]+1;
            dfs(e,x,depth,graph);
        }
    }
}

/*
dfs2 function to calculate the path 
from x (having parent p) -> v 
return path from v -> x and 
return empty vector if doesn't exist
*/

vector<int> dfs2(int x,int p,int v,vector<vector<int>>&graph){
    if(x==v){
        return {x};
    }
    for(auto e : graph[x]){
        if(e != p){
            vector<int>out = dfs2(e,x,v,graph);
            if(sz(out)){
                out.pb(x);
                return out;
            }
        }
    }
    return {};
}

string dectobin(int x){
    string a;
    while(x != 0){
        a += to_string(x%2);
        x >>= 1;
    }
    reverse(all(a));
    return a;
}

void solve(){
    int n,h;
    cin>>h>>n;
    vector<int>a(n),b(n);
    cin>>a>>b;
    priority_queue<pii>pq;
    map<int,vector<pii>>mp;
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
    }
    int ans=1;
    while(h>0){
        // debug(pq,mp);
        if(mp.find(ans)!=mp.end()){
            int n=sz(mp[ans]);
            for(auto x:mp[ans]){
                pq.push(x);
            }
            mp.erase(ans);
        }
        if(!pq.empty()){
            while(!pq.empty()){
                int val=pq.top().ff;
                h-=val;
                int time=ans+b[pq.top().ss];
                mp[time].push_back({val,pq.top().ss});
                pq.pop();
            }
            if(h<1)break;
            ans++;
        }
        else{
            debug("yo");
            ans=mp.begin()->ff;
            for(auto x:mp.begin()->ss){
                pq.push(x);
            }
            mp.erase(ans);
        }
        // debug(pq,mp);
    }
    cout <<ans <<nline;
    
}
     
int32_t main(){
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
    cin >> t;
    for(int testcase = 1; testcase <= t; ++testcase) {
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop1 - start1);
#ifdef varunkmr15
    cerr << "Time taken: " << duration . count() / 1e9 <<"s" << endl;
#endif
    return 0;
}                        