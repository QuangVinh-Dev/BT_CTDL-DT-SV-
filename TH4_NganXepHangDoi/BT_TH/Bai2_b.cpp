#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

struct Node
{
    char data[50];
    Node* next;
};
Node* front =NULL;
struct LinkedQueueInt {
    Node* front; // Con trỏ đầu của hàng đợi
    Node* rear; // Con trỏ cuối của hàng đợi
};
// Khởi tạo hàng đợi rỗng
void Init(LinkedQueueInt &queue){
    queue.front =NULL;
    queue.rear =NULL;
}
//Kiem tra hang doi rong
bool IsEmpty(LinkedQueueInt &queue)
{
    return (queue.front ==NULL && queue.rear ==NULL);
}
//Them  vao hang doi
void Enqueue(LinkedQueueInt &queue ,const char* name)
{
    Node*temp=new Node;//Khoi tao node moi
    strcpy(temp->data,name);//Gan gia tri cho node
    temp->next=NULL;//Nut moi khong tro den nut nao
    if(IsEmpty(queue))
    {
        queue.front=queue.rear=temp;//front va rear cung tro den node moi
    }
    else
    {
        queue.rear->next=temp;//rear tro den node moi
        queue.rear=temp;//dat rear ve node moi
    }
}
//Loai bo phan tu khoi hang doi
void Dequeue(LinkedQueueInt &queue)
{
    if(IsEmpty(queue))
    {
        cout<<"hang doi rong";
        return;
    }
    Node*temp=queue.front;//Luu tru node dau de xoa
    queue.front=queue.front->next;//dat front lam node tiep theo
    delete temp;//xoa node dau
    // neu hang doi rong
    if(queue.front==NULL)
    {
        queue.rear=NULL;//dat rear ve NULL
    }
    
}

const char* PeekQueue(LinkedQueueInt& queue) {
    if (!IsEmpty(queue)) {
        return queue.front->data; //Tra ve du lieu ban dau
    }
    return nullptr;
}

/*  Tích hợp Ai để kiếm testkey*/
int main() {
    LinkedQueueInt maleQueue, femaleQueue;
    Init(maleQueue);
    Init(femaleQueue);
    // Thêm các bạn nam và nữ vào hàng đợi
    Enqueue(maleQueue, "Nam 1");
    Enqueue(maleQueue, "Nam 2");
    Enqueue(femaleQueue, "Nữ 1");
    Enqueue(femaleQueue, "Nữ 2");

    // Xếp cặp
    while (!IsEmpty(maleQueue) && !IsEmpty(femaleQueue)) {
        const char* male = PeekQueue(maleQueue); // Lấy tên nam từ hàng đợi
        Dequeue(maleQueue); // Xóa nam khỏi hàng đợi
        const char* female = PeekQueue(femaleQueue); // Lấy tên nữ từ hàng đợi
        Dequeue(femaleQueue); // Xóa nữ khỏi hàng đợi
        std::cout << "Cặp: " << male << " và " << female << std::endl; // In ra cặp nam nữ
    }

    return 0;
}