#include<iostream>
#define MAX 100
using namespace std;
void NhapMang(int **a,int *n)
{
    cout<<"Nhap so phan tu cua mang: ";
    cin>>(*n);
    while ((*n)<=0 || (*n)>MAX)
    {
        cout<<"Nhap sai ,moi nhap lai: ";
        cin>>(*n);
    }
    (*a)=new int[(*n)];
    for(int i=0;i<*n;i++)
    {
        cout<<"Nhap phan tu thu "<<i<<" : ";
        cin>>(*a)[i];
    }
}
bool KT_Chan_Le(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        // so dau chan so 2 chan thi Sai
        if(a[i]%2==0 && a[i+1]%2==0 || a[i]%2!=0 && a[i+1]%2!=0)
        {
            return false;
        }
    }
    return true;
}
bool KT_Toan_Chan(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]%2!=0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int *a,n;
    NhapMang(&a,&n);
    if(KT_Chan_Le(a,n))
    {
        cout<<"+Day co tinh chan le .\n";
    }
    else
    {
        cout<<"+Day khong co tinh chan le .\n";
    }
    if(KT_Toan_Chan(a,n))
    {
        cout<<"+Day toan so chan .\n";
    }
    else
    {
        cout<<"+Day khong toan so chan .\n";
    }
    delete[] a;
    return 0;
}