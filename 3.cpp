#include<bits/stdc++.h>
using namespace std;
void sol()
{
int n;
cin>>n;
string s1,s2;
cin>>s1>>s2;
int n1_s1=0;
int n1_s2=0;
for(int i=0;i<s1.length();i++)
{
    if(s1[i]=='1')
        n1_s1++;
}
for(int i=0;i<s2.length();i++)
{
    if(s2[i]=='1')
        n1_s2++;
}
if(n1_s1==n1_s2)
    cout<<"YES\n";
else
    cout<<"NO\n";


return;
}
 
int main(){
int n;
cin>>n;
while(n--)
{sol();}
return 0;
}