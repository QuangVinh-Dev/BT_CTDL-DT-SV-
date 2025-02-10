#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s;
    char chen;
    int k;
    cout<<"Moi ban nhap chuoi s: "<<endl;getline(cin, s);
    cout<<"Nhap vi tri can chen"<<endl;cin>>k;
    cout<<"Moi ban nhap ki tu can chen: "<<endl;cin>>chen;
    if (k >= 0 && k <= s.length()) {
        s.insert(s.begin() + k, chen);
        cout << "Chuoi sau khi them ky tu \"" << chen << "\" vao vi tri " << k << ": " << s <<endl;
    } else {
        cout << "Vi tri khong hop le!" <<endl;
    }
    
    return 0;
}