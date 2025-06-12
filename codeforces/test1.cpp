#include <bits/stdc++.h>

using namespace std;

// --- Type Shortcuts ---
#define ll long long
#define ull unsigned long long
#define ld long double

// --- Constants ---
#define pi (3.141592653589)
#define mod 1000000007
#define INF 1e9
#define EPS 1e-9
const int MAX_N = 1e5 + 5;

// --- Container/Iterator Helpers ---
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define is insert

// --- Loop Shortcuts ---
#define fr(n) for(long long i=0;i<n;i++)
#define rep(i,a,b) for(long long i=a;i<b;i++)
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define rfr(n) for(int i=n-1;i>=0;i--)

// --- Input/Output & Debugging ---
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define endl '\n'
#define debug(x) cout << #x << " : " << x << endl
#define nl cout << "\n"

// --- Type Aliases ---
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef map<int, int> mii;
typedef set<int> si;
typedef unordered_map<int, int> umii;
typedef unordered_set<int> usi;

// --- Main Logic Structure ---
template <typename T>
void printArray(const std::vector<T>& arr, const std::string& separator = " ",
                const std::string& prefix = "", const std::string& suffix = "\n") {
    std::cout << prefix;
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i < arr.size() - 1) { // Don't print separator after the last element
            std::cout << separator;
        }
    }
    std::cout << suffix;
}

template <typename T>
void reverseSubarray(int l, int r, std::vector<T>& arr) {
    // Convert 1-based indexes to 0-based indexes
    int actual_l = l - 1;
    int actual_r = r - 1;

    // Check for valid index range
    if (actual_l < 0 || actual_r >= static_cast<int>(arr.size()) || actual_l > actual_r) {
        // You can throw an exception, return an error code, or handle this
        // based on your application's error handling strategy.
        // For simplicity, we'll just return here.
        return;
    }

    // Use std::reverse to reverse the specified range
    // std::reverse takes iterators to the beginning and one past the end of the range
    std::reverse(arr.begin() + actual_l, arr.begin() + actual_r + 1);
}

void solve() {
    int n;
    cin >> n;
    
    cout << 2 * (n - 1) << endl;
    vi arr(n);
    for (int i = 1; i <= n; ++i)
        arr[i - 1] = i;

    printArray(arr);
        
    for (int i = 2; i <= n; ++i)
    {
        // cout << i << ' ' << 1 << ' ' << n - i + 2 << endl;
        // cout << i << ' ' << 2 << ' ' << n << endl;
            
        for (int i = 1; i <= n; ++i)
            arr[i - 1] = i;
        
        reverseSubarray(1, n - i + 2, arr);
        reverseSubarray(2, n, arr);

        printArray(arr);
    }
}

int main() {
    fast;
    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
