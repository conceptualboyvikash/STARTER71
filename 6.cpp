#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{

    int n, m;
    cin >> n >> m;
    vector<int> t(m + 1), c(m + 1), v(n + 1);
    for (int i = 1; i <= m; ++i)
        cin >> t[i];
    for (int i = 1; i <= m; ++i)
        cin >> c[i], v[t[i]] = c[i];

    const int K = 3;
    int dp[n + 2][K][K];
    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j < K; ++j)
            for (int k = 0; k < K; ++k)
                dp[i][j][k] = -1e9;
    }

    int ans = 0;
    dp[1][0][0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            for (int k = 0; k < K; ++k)
            {
                if (dp[i][j][k] == -1e9)
                    continue;
                if (j + 1 < k)
                {
                    int d = k - j - 1;
                    d %= 2;
                    if (d == 0)
                        d = 2;
                    dp[i + 1][0][d] = max(dp[i + 1][0][d], dp[i][j][k]);
                }
                else if (j + 1 == k)
                {
                    dp[i + 1][0][0] = max(dp[i + 1][0][0], dp[i][j][k]);
                }
                else
                {
                    int d = j + 1 - k;
                    d %= 2;
                    if (d == 0)
                        d = 2;
                    dp[i + 1][d][0] = max(dp[i + 1][d][0], dp[i][j][k]);
                }

                if (k + 1 < j)
                {
                    int d = j - k - 1;
                    d %= 2;
                    if (d == 0)
                        d = 2;
                    dp[i + 1][d][0] = max(dp[i + 1][d][0], dp[i][j][k]);
                }
                else if (k + 1 == j)
                {
                    dp[i + 1][0][0] = max(dp[i + 1][0][0], dp[i][j][k]);
                    // if(i == 2 && j == 1 && k == 0) {
                    //     cout << "H" << " "<< dp[i][j][k] << " ";
                    //     cout << dp[i + 1][0][0] << '\n';
                    //     cout << i + 1 << " " << 0 << " " << 0 << "->" << dp[i + 1][0][0] << "\n";
                    // }
                }
                else
                {
                    int d = k + 1 - j;
                    d %= 2;
                    if (d == 0)
                        d = 2;
                    dp[i + 1][0][d] = max(dp[i + 1][0][d], dp[i][j][k]);
                }
            }
        }

        for (int j = 0; j < K; ++j)
        {
            for (int k = 0; k < K; ++k)
            {
                if (j == 0 && k == 0)
                    continue;
                if (v[i] == 1)
                {
                    if (j > k)
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], 1 + dp[i + 1][j][k]);
                    else
                    {
                        dp[i + 1][0][0] = max(dp[i + 1][0][0], dp[i + 1][j][k]);
                        dp[i + 1][j][k] = -1e9;
                    }
                }
                else if (v[i] == 2)
                {
                    if (j < k)
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], 1 + dp[i + 1][j][k]);
                    else
                    {
                        dp[i + 1][0][0] = max(dp[i + 1][0][0], dp[i + 1][j][k]);
                        dp[i + 1][j][k] = -1e9;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n + 1; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            for (int k = 0; k < K; ++k)
            {
                ans = max(ans, dp[i][j][k]);
            }
        }
    }

    // for(int aa = 0; aa <= 12; ++aa) {
    //     cout << aa <<": \n";

    //     for(int i = 0; i <= n + 1; ++i) {
    //         for(int j = 0; j < K; ++j) {
    //             for(int k = 0; k < K; ++k) {
    //                 if(dp[i][j][k] == aa) {
    //                     cout << i << " " << j << " " << k << '\n';
    //                 }
    //             }
    //         }
    //     }
    //     cout << "\n";
    // }

    // for(int i = 1; i <= n + 1; ++i) {
    //     for(int j = 0; j < K; ++j) {
    //         for(int k = 0; k < K; ++k) {
    //             cout << (dp[i][j][k] == -1e9 ? -1 : dp[i][j][k]) << " ";
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    // cout << dp[3][0][0] << '\n';

    cout << ans << '\n';
}

signed main()
{

    ios ::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}

/*
1
    6 4
    1 2 4 6
    2 1 2 1
*/