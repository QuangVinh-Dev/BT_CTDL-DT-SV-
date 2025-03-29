#include<iostream>
#include<stack>
using namespace std;

//Khoi tao cau truc lu thong tin di chuyen
struct Move{
    int num;//so dia
    char from;//coc nguon
    char to;//coc dich
    char aux;//coc trung gian
};

//Ham thuc hien thap Ha Noi khong dung de quy
void ThapHaNoi(int num,char from,char to,char aux)
{
    //Khoi tao stack luu cac buoc di chuyen
    stack<Move> s;
    //Dua bai toan vao tong the stack
    s.push({num,from,to,aux});
    while(!s.empty())
    {
        Move current =s.top();//Lay phan tu dau tiene cua stack
        s.pop();//Xoa phan tu dau tien cua stack
        //TH1: Neu chi co 1 dia
        if(current.num==1) 
        {
            cout<< current.from << " --> " << current.to << endl;
        }
        //TH2:Neu co nhieu hon 1 dia
        else
        {
            //Dua n-1 dia tu from sang aux
            s.push({current.num - 1, current.aux, current.to, current.from});
            //chuyen dia lon sang to
            s.push({1, current.from, current.to, current.aux});
            //chuyen n-1 dia tu aux sang to
            s.push({current.num - 1, current.from, current.aux, current.to});   
        }
    }
}


int main()
{
    int num;cout<<"Nhap so dia :";cin>>num;
    ThapHaNoi(num,'A','B','C');
    return 0;
}

