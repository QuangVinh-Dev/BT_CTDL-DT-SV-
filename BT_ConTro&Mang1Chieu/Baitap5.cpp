#include<iostream>
using namespace std;
void Nhap_Mang(int **a,int *n)
{
    while(*n>=100 || *n<=0)
    {
        cout<<"Nhap lai n: ";
        cin>>*n;
    }
    (*a)= new int[*n];
    for(int i=0;i<*n;i++)
    {
        cout<<"Nhap phan tu thu "<<i<<": ";
        cin>>(*a)[i];
    }
}
void Xuat_Mang(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
void tachchanle(int *a,int n,int **b,int *m,int **c,int *p)
{
    *m=0;
    *p=0;
    for(int i=0;i<n;i++)
    {
        if(*(a+i)%2==0)
        {
            (*m)++;
        }
        else
        {
            (*p)++;
        }
    }
    *b =new int [*m];
    *c =new int [*p];
    int sochan=0;int sole=0;
    for(int i=0;i<n;i++){
        if(*(a+i)%2==0){
            (*b)[sochan++]=*(a+i);
        }
        else{
            (*c)[sole++]=*(a+i);
        }
    }
}

int main()
{
    int *a,*b,*c;
    int n,m,p;
    cout<<"+ Day so a"<<endl;
    Nhap_Mang(&a,&n);
    Xuat_Mang(a,n);
    
    cout << "+ Day so b chua so chan" << endl;
    tachchanle(a, n, &b, &m, &c, &p);
    Xuat_Mang(b, m);

    cout << "+ Day so c chua so le" << endl;
    Xuat_Mang(c, p);

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

