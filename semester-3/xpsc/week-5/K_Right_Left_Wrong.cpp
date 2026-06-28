#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
        }
        string s;
        cin >> s;

        int l = 0, r = n - 1;
        long long max_score = 0;

        while (l < r)
        {
            if (s[l] != 'L')
                l++;
            else if (s[r] != 'R')
                r--;
            else
            {
                max_score += (pref[r + 1] - pref[l]);
                l++;
                r--;
            }
        }

        cout << max_score << "\n";
    }

    return 0;
}