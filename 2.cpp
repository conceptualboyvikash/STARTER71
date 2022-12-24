#include<bits/stdc++.h>
using namespace std;
void sol()
{
int k;
cin>>k;
string s;
cin>>s;
int odd=0,even=0;
for(int i=0;i<k;i++)
{
if(odd==1 && even==1)
    break;

    if(s[i]=='1' && i%2==0)
        even=1;
    else if(s[i]=='1' && i%2==1)
        odd=1;

}
if(odd==1 && even==1)
    cout<<"1\n";
else   
    cout<<"2\n";

return;
}
 
int main(){
int n;
cin>>n;
while(n--)
{sol();}
return 0;
}