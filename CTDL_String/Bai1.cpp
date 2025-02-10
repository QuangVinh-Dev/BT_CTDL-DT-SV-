#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Moi ban nhap chuoi s: "<<endl;
    getline(cin, s);
    sort(s.begin(), s.end());
    cout<<"Chuoi sau khi sap xep la"<<s<<endl;
    return 0;

}