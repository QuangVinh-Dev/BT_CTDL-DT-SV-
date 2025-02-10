#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s;
    int k;
    cout<<"Moi ban nhap chuoi s: "<<endl;getline(cin, s);
    cout<<"Moi ban nhap so k: "<<endl;cin>>k;
    if(k<=s.length()&&k>=0)
    {
        s.erase(s.begin()+k);
        cout<<"Chuoi sau khi xoa tai vi tri "<<k<<"la : "<<s<<endl;
    }
    else
    {
        cout<<"Vi tri  khong hop le"<<endl;
    }
    return 0;

}