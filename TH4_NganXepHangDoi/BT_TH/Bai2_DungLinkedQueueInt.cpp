#include<iostream>
using namespace std;

// Khoi tao danh sach lien ket
struct Node {
    int data; // du lieu cua node
    Node* next; // con tro tro den node tiep theo
};

// Khoi tao 2 nut dau va cuoi
Node* front = NULL;
Node* rear = NULL;

// Khoi tao hang doi rong
void Init() {
    front = NULL;
    rear = NULL;
}

// Kiem tra danh sach rong
bool IsEmpty() {
    return (front == NULL && rear == NULL);
}

// Them phan tu vao hang doi
void PushStack(int value) {
    Node* temp = new Node; // khoi tao node moi
    temp->data = value; // gan gia tri cho node
    temp->next = NULL; // Nut moi khong tro den nut nao
    // Neu hang doi rong
    if (IsEmpty()) {
        front = rear = temp; // front va rear cung tro node moi
    } else {
        rear->next = temp; // rear tro den node moi
        rear = temp; // rear tro den node moi
    }
}

// Lay phan tu khoi hang doi
void PopStack() {
    if (IsEmpty()) {
        cout << "Hang doi rong\n";
        return;
    }
    // Luu tru node dau de xoa
    Node* temp = front;
    // Chuyen front den node tiep theo
    front = front->next;
    // xoa node dau
    delete temp;
    if (front == nullptr) {
        rear = nullptr; // Neu hang doi rong, dat rear ve nullptr
    }
}

// Lay phan tu dau hang doi ma khong xoa
int PeekStack() {
    if (!IsEmpty()) {
        return front->data; // Tra ve du lieu cua nut dau
    }
    cout << "Queue is empty\n";
    return -1;
}

// Xoa hang doi
void Clear() {
    while (!IsEmpty()) {
        PopStack(); // xoa phan tu cho den khi hang doi rong
    }
}

// Test case
int main() {
    Init();
    cout << "Them cac phan tu vao hang doi: 10, 20, 30\n";
    PushStack(10);
    PushStack(20);
    PushStack(30);
    
    cout << "Phan tu o dau hang doi: " << PeekStack() << "\n";
    
    cout << "Xoa mot phan tu khoi hang doi\n";
    PopStack();
    
    cout << "Phan tu o dau hang doi sau khi xoa: " << PeekStack() << "\n";
    
    cout << "Xoa toan bo hang doi\n";
    Clear();
    
    cout << "Kiem tra hang doi co rong khong: " << (IsEmpty() ? "Co" : "Khong") << "\n";
    return 0;
}