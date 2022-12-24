#include <iostream>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--)
    {
        int n,b;
        cin>>n>>b;
        pair<int,int>p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].first;
        for(int i=0;i<n;i++)
            cin>>p[i].second;
        long long int sum=0;

        for(int i=0;i<n;i++)
        {
            if(p[i].first>=b)
                sum+=p[i].second;
        }
        cout<<sum<<endl;
        
    }
	// your code goes here
	return 0;
}
