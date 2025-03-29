#include<iostream>
#include<stack>
using namespace std;

//Phien ban dung de quy
int Reverse_recursive(int num,int rev=0)
{
    //Neu n=0 thi tra ve 
    if(num==0) return rev;
    //Neu n khac 0 thi in ra so cuoi cung cua n
    else  {
        rev =rev*10 + num%10;
        return Reverse_recursive(num/10,rev);
    }
}

//Phien ban su dung stack
int Reverse_stack(int num)
{
    stack<int> s;
    //Tach tung so 
    while(num !=0)
    {
        s.push(num%10);//lay chu so cuoi cung
        num /=10;//loai bo chu so cuoi cung
    }
    int rev=0;//so dao nguoc
    int place=1;//vi tri hang
    while (!s.empty()) {
        rev += s.top() * place; // Lấy chữ số từ stack
        s.pop();               // Xóa chữ số đã lấy
        place *= 10;           // Tăng vị trí hàng
    }
    return rev;

    
}
int main()
{
    int num;
    cout<<"Nhap so can dao nguoc: ";cin>>num;
    cout<<"So dao nguoc de quy: "<<Reverse_recursive(num)<<endl;   
    cout<<"So dao nguoc su dung stack: "<<Reverse_stack(num)<<endl;
    return 0;
}