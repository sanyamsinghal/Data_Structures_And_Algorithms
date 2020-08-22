#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define loop(i, k, n) for (ll i = k; i <= n; i++)
#define sort_cut(x) (x).begin(), (x).end()

void printVector(vector<ll> &v)
{
    for (ll x : v)
        cout << x << " ";
    cout << endl;
}

/* ---------------------Code--------------------  */

bool comp(vll a, vll b)
{
    if (a[0] == b[0])
        return a[2] <= b[2];
    return a[0] < b[0];
}

void remove(ll element, map<ll, ll> &freq, ll &ans)
{
    freq[element]--;
    if (freq[element] == 0)
        ans--;
}

void add(ll element, map<ll, ll> &freq, ll &ans)
{
    freq[element]++;
    if (freq[element] == 1)
        ans++;
}

int main()
{
    ll n, q;
    cin >> n;
    ll bs = ceil(sqrt(n));

    vector<ll> arr(n);
    loop(i, 0, n - 1) cin >> arr[i];

    cin >> q;
    vector<vector<ll>> queries;
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        queries.push_back({l / bs, l, r, i});
    }

    sort(sort_cut(queries), comp);

    map<ll, ll> freq;
    ll left = queries[0][1];
    ll right = left;
    freq[arr[left]] = 1;
    vector<ll> answers(q);
    ll ans = 1;
    for (ll i = 0; i < q; i++)
    {
        // cout << queries[i][1] << " " << queries[i][2] << endl;
        while (left < queries[i][1])
        {
            remove(arr[left], freq, ans);
            left++;
        }

        while (left > queries[i][1])
        {
            left--;
            add(arr[left], freq, ans);
        }

        while (right > queries[i][2])
        {
            remove(arr[right], freq, ans);
            right--;
        }

        while (right < queries[i][2])
        {
            right++;
            add(arr[right], freq, ans);
        }
        answers[queries[i][3]] = ans;
    }

    for (ll i = 0; i < q; i++)
        cout << answers[i] << "\n";

    return 0;
}