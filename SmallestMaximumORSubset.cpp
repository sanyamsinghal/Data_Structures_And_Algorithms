#include "bits/stdc++.h"
using namespace std;
#define nl cout << "\n"
#define fr(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fa(v) for (auto &i : v)
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
//#define int long long
const int N = (1 << 20) + 10;
int a[N], b[N], c[N];
void transform(int *from, int *to)
{
    if (to - from == 1)
        return;
    int *mid = from + (to - from) / 2;
    transform(from, mid);
    transform(mid, to);
    for (int i = 0; i < mid - from; i++)
        *(mid + i) += *(from + i);
}

void inverse(int *from, int *to)
{
    if (to - from == 1)
        return;
    int *mid = from + (to - from) / 2;
    inverse(from, mid);
    inverse(mid, to);
    for (int i = 0; i < mid - from; i++)
        *(mid + i) -= *(from + i);
}
int get_brute(int n)
{
    pair<int, int> ans{-1, -1};
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int OR = 0, cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if ((mask >> j) & 1)
            {
                cnt++;
                OR |= b[j];
            }
        }
        ans = max(ans, {OR, -cnt});
    }
    return -ans.second;
}

int32_t main()
{
    int mx = (1 << 20);
    int n, x, OR = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a[x] = 1, c[x] = 1, OR |= x, b[i] = x;
    }
    transform(a, a + mx); //// multiplier
    int ans = 1;
    int brute = get_brute(n);
    while (!c[OR])
    {
        ans++;
        transform(c, c + mx);
        for (int i = 0; i < mx; i++)
            c[i] = a[i] * c[i];
        inverse(c, c + mx);
    }

    if (ans != brute)
    {
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        nl;
    }
    cout << "norml ----> " << ans << "\n";
    cout << "brute ----> " << brute << "\n";
}