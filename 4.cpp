#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void sol()
{
    lli n;
    cin >> n;
    lli arr[n];
    for (lli i = 0; i < n; i++)
        cin >> arr[i];
    map<lli, lli> m;
    map<lli, lli> m2;
    lli count = 0;
    map<lli, lli> m3;
    map<lli, lli> m4;
    for (int i = 0; i < n; i++)
    {
        if (m3[arr[i]] == 0 || m4[arr[i]]==0)
        {
            count += arr[i];
            m3[arr[i]]++;
            m4[arr[i]]=arr[i];
        }
        m4[arr[i]]--;
    }
    if (count >n)
    {
        cout << "-1\n";
    }

    else
    {
        lli k = 1;
        for (lli i = 0; i < n; i++)
        {
            if (m[arr[i]] == 0 || m2[arr[i]] == 0)
            {
                m[arr[i]] = k;
                m2[arr[i]] = arr[i];

                k++;
            }

            cout << m[arr[i]] << " ";
            m2[arr[i]]--;
        }
        cout << endl;
    }

    return;
}

int main()
{
    lli n;
    cin >> n;
    while (n--)
    {
        sol();
    }
    return 0;
}