//Cài bằng stackinit
#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
int front =-1;
int rear =-1;
int arr[MAX];
//Tao queue
void Init()
{
    front=rear=-1; //Khơi tạo hàng đợi rỗng
}
//Kiem tra hang doi co bi day khong
bool IsFull()
{
    return rear==MAX-1;
}
//Kiem tra hang doi co bi rong khong
bool IsEmpty()
{
    return (front==-1 && rear==-1);
}
//Them phan tu vao hang doi
void Push(int value)
{
    if(IsFull())
    {
        cout<<" Hang doi day";
        return ;
    }
    //Neu hang doi rong thi front va rear se cung 0
    if(IsEmpty())
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    arr[rear]=value;
}
//lay phan tu khoi hang doi
int Pop()
{
    if(IsEmpty())
    {
        cout<<"Hang doi rong";
        return -1;
    }
    if (front == rear) {
        front = rear = -1; // Nếu chỉ có một phần tử, đặt hàng đợi về rỗng
    } else {
        front++; // Tăng chỉ số đầu của hàng đợi
    }
}
//Lay phan tu dau hang doi ma khong xoa
int PeekStack() {
    if (!IsEmpty()) {
        return arr[front]; // Trả về phần tử đầu của hàng đợi
    }
    cout << "Queue is empty\n";
    return -1;
}
//Xoa toan bo hang doi
void Clear() {
    front = rear = -1; // Xóa toàn bộ hàng đợi
}
int main()
{
    return 0;
}