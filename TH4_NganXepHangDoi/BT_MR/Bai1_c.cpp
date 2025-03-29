#include<iostream>
using namespace std;

//Su dung de quy
void ThapHN(int n,char a,char b,char c)
{
	//Truong hop 1 dia
	if(n==1)
		{
			cout<<a<<"-->"<<b<<endl;
			return ;
		}
//	//Truong hop co 2 dia
//	if(n==2)
//		{
//			cout<<"t"<<a<<"-->"<<b<<endl;
//			cout<<"t"<<a<<"-->"<<c<<endl;
//			cout<<"t"<<b<<"-->"<<c<<endl;
//		}
	//truong hop n>=3
	ThapHN(n-1,a,c,b);
	ThapHN(1,a,b,c);
	ThapHN(n-1,b,a,c);
}

int main()
{
	int n;char a='A',b='B',c='C';
	cout<<"Nhap n :";cin>>n;
	ThapHN(n,a,b,c);
	return 0;
}