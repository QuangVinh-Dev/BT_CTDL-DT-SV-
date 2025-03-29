#include<iostream>
#include<stack>
using namespace std;

//Phien ban dung de quy

int Fibonacci(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

//Phien ban su dung stack
int Fibonacci_Stack(int n)
{
    //truong hop co so
    if(n<=1) return n;
    stack<int> st;//luu gia tri can tinh
    st.push(n);//gia tri ban dau vao stack
    int result=0;//gia tri ket qua
    //duyet cac gia tri trong stack
    while(!st.empty())
    {
        int x=st.top();//lay gia tri tren cung cua stack
        st.pop();//xoa gia tri da lay
        if(x==1)   
            result +=1;//Neu x = 1 thi cong them 1 vao ket qua
        else if(x == 0) //Neu x = 0 thi khong lam gi ca
            continue;
        else{
            //DayF(n-1) vao stack
            st.push(x-1);
            st.push(x-2);
        }
    }
    return result;
}


int main()
{
    int n;
    cout<<"Nhap n: ";cin>>n;
    cout<<"Fibonacci(n) de quy = "<<Fibonacci(n)<<endl;
    cout<<"Fibonacci(n) khong de quy = "<<Fibonacci_Stack(n)<<endl;
    return 0;
}