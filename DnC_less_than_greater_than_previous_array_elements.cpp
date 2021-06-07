#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, n) for (int i = 0; i < n; i++)

void merge(vector<pair<int, int>> &a, int start, int end, vector<int> &great)
{
    if (start == end)
    {
        return;
    }
    merge(a, start, (start + end) / 2, great);
    merge(a, (start + end) / 2 + 1, end, great);

    int j1 = start, j2 = (start + end) / 2 + 1, k = 0;
    ;
    vector<pair<int, int>> c(end - start + 1);
    while (j1 <= (start + end) / 2 && j2 <= end)
    {
        if (a[j1].first > a[j2].first)
        {
            great[a[j2].second] += (start + end) / 2 - j1 + 1;
            c[k++] = a[j2++];
        }
        else
        {
            c[k++] = a[j1++];
        }
    }
    while (j1 <= (start + end) / 2)
    {
        c[k++] = a[j1++];
    }
    while (j2 <= end)
    {
        c[k++] = a[j2++];
    }
    k = 0;
    while (k <= end - start)
    {
        a[k + start] = c[k];
        k++;
    }
}

void merge2(vector<pair<int, int>> &a, int start, int end, vector<int> &less)
{
    if (start == end)
    {
        return;
    }
    merge2(a, start, (start + end) / 2, less);
    merge2(a, (start + end) / 2 + 1, end, less);

    int j1 = start, j2 = (start + end) / 2 + 1, k = 0;
    ;
    vector<pair<int, int>> c(end - start + 1);
    while (j1 <= (start + end) / 2 && j2 <= end)
    {
        if (a[j1].first < a[j2].first)
        {
            less[a[j2].second] += (start + end) / 2 - j1 + 1;
            c[k++] = a[j2++];
        }
        else
        {
            c[k++] = a[j1++];
        }
    }
    while (j1 <= (start + end) / 2)
    {
        c[k++] = a[j1++];
    }
    while (j2 <= end)
    {
        c[k++] = a[j2++];
    }
    k = 0;
    while (k <= end - start)
    {
        a[k + start] = c[k];
        k++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    vector<pair<int, int>> a(t);
    rep(i, t)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<int> less(t, 0);
    vector<int> great(t, 0);
    vector<pair<int, int>> a1 = a;
    merge(a1, 0, t - 1, great);
    a1 = a;
    merge2(a1, 0, t - 1, less);
    ll f = 0;
    rep(i, t)
    {
        f += 2 * (min(less[i], great[i])) + 1;
    }
    // ll f = 0;
    // multiset<ll> s;
    // for (ll i = 1; i <= t; i++)
    // {
    //     ll n;
    //     cin >> n;
    //     multiset<ll>::iterator it = s.lower_bound(n);
    //     ll pos = distance(s.begin(), it);
    //     it = s.lower_bound(n + 1);
    //     ll pos2 = distance(s.begin(), it);
    //     pos2 = i - pos2 - 1;

    //     s.insert(n);
    //     f += 2 * min(pos, pos2) + 1;
    // }
    cout << f << endl;
}