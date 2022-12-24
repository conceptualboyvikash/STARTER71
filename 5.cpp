#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void sol()
{
    lli n, m;
    cin >> n >> m;
    pair<lli, lli> p[m];
    for (lli i = 0; i < m; i++)
        cin >> p[i].first;
    for (lli i = 0; i < m; i++)
        cin >> p[i].second;
    lli a, b, score;
    a = 0;
    b = 0;
    score = 0;
    for (lli i = 0, t = 0; i < n && t < m; i++)
    {
        if (p[t].second == 1 ||(a<b &&(i+1!=p[t].first))||(a+1!=b && a<b))
        {

            a++;
        }
        else if (p[t].second == 2 ||( b<a && i+1!=p[t].first)|| (b+1!=a && b<a))
        {
            b++;
        }
        
        if (i + 1 == p[t].first)
        {
            if (p[t].second == 1)
            {

                if (a > b)
                    score = score + 1;
                else
                {

                    a = 0;
                    b = 0;
                }
            }
            else
            {

                if (a < b)
                    score = score + 1;
                else
                {
                    a = 0;
                    b = 0;
                }
            }
            t++;
        }
    }
    cout<<score<<"\n";

    return;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        sol();
    }
    return 0;
}