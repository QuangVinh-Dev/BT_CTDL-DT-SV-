#include<iostream>
#include<math.h>
using namespace std;
int PT_Bac2(float *a, float *b, float *c, float &x1, float &x2)
{
    int sn=-1;//ki thuat cam co
    if((*a)==0)
    {
        if((*b)==0)
        {
            if((*c)==0)
            {
                sn=-1;
            }
            else
            {
                sn=0;
            }
        }
        else // neu a = 0 va b,c khac 0(bx + c = 0) 
        {
            x1=-(*c)/(*b);
            sn=1;
        }
    }
    double delta = (*b)*(*b) - 4*(*a)*(*c);
    if(delta<0){
        sn=0;
    }
    else if(delta ==0){
        x1=(-(*b))/(2*(*a));
        sn=1;
    }
    else if(delta>0){
        x1=(-(*b)+sqrt(delta))/(2*(*a));
        x2=(-(*b)-sqrt(delta))/(2*(*a));
        sn=2;
    }
    return sn;
}
int main()
{
    float a,b,c,x1,x2;
    cout<<"Nhap a: .\n";
    cin>>a;
    cout<<"Nhap b: .\n";
    cin>>b;
    cout<<"Nhap c: .\n";
    cin>>c;
    int sn=PT_Bac2(&a,&b,&c,x1,x2);
    if(sn==-1)
    {
        cout<<"Phuong trinh vo so nghiem.\n";
    }
    else if(sn==0)
    {
        cout<<"Phuong trinh vo nghiem.\n";
    }
    else if(sn==1)
    {
        cout<<"Phuong trinh co nghiem kep x1=x2= "<<x1<<endl;
    }
    else if(sn==2)
    {
        cout<<"Phuong trinh co 2 nghiem phan biet x1= "<<x1<<" va x2= "<<x2<<endl;
    }
    return 0;
}