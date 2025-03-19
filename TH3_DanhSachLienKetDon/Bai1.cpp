#include<iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* next;
};

// Khởi tạo danh sách rỗng
void Init(Node*& pHead) {
    pHead = NULL;
}

// Kiểm tra danh sách rỗng
bool IsEmpty(Node* pHead) {
    return (pHead == NULL);
}

// Tạo node mới
Node* CreateNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Thêm phần tử vào cuối danh sách
void InsertLast(Node*& pHead, int x) {
    Node* temp = CreateNode(x);
    if (IsEmpty(pHead)) {
        pHead = temp;
    } else {
        Node* p = pHead;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

// Xóa phần tử có giá trị k (xóa lần xuất hiện đầu tiên)
void DeleteValue(Node*& pHead, int k) {
    if (IsEmpty(pHead)) {
        cout << "Danh sach rong, khong the xoa!" << endl;
        return;
    }
    
    // Nếu phần tử đầu là k
    if (pHead->data == k) {
        Node* p = pHead;
        pHead = pHead->next;
        delete p;
        return;
    }
    
    // Tìm và xóa phần tử
    Node* p = pHead;
    while (p->next != NULL && p->next->data != k) {
        p = p->next;
    }
    
    if (p->next == NULL) {
        cout << "Khong tim thay gia tri " << k << " trong danh sach!" << endl;
    } else {
        Node* q = p->next;
        p->next = q->next;
        delete q;
    }
}

// Thêm toàn bộ danh sách thứ hai vào cuối danh sách thứ nhất
void AppendList(Node*& list1, Node* list2) {
    if (IsEmpty(list2)) return; // Nếu list2 rỗng thì không làm gì
    
    // Tạo bản sao của list2 để không ảnh hưởng list2 gốc
    Node* p = list2;
    while (p != NULL) {
        InsertLast(list1, p->data);
        p = p->next;
    }
}

// Xuất danh sách
void Display(Node* pHead) {
    if (IsEmpty(pHead)) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    Node* p = pHead;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Hủy danh sách
void Destroy(Node*& pHead) {
    while (pHead != NULL) {
        Node* p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    
    // (b) Chương trình chính
    
    // 1. Nhập 10 số nguyên vào list1
    cout << "Nhap 10 so nguyen cho danh sach thu nhat:\n";
    for (int i = 0; i < 10; i++) {
        int x;
        cout << "So thu " << i + 1 << ": ";
        cin >> x;
        InsertLast(list1, x);
    }
    
    // 2. In danh sách list1
    cout << "Danh sach thu nhat ban dau: ";
    Display(list1);
    
    // 3. Nhập số k và xóa k khỏi list1
    int k;
    cout << "Nhap so k can xoa: ";
    cin >> k;
    DeleteValue(list1, k);
    
    // 4. In danh sách list1 sau khi xóa
    cout << "Danh sach thu nhat sau khi xoa " << k << ": ";
    Display(list1);
    
    // 5. Nhập 5 số nguyên vào list2
    cout << "Nhap 5 so nguyen cho danh sach thu hai:\n";
    for (int i = 0; i < 5; i++) {
        int x;
        cout << "So thu " << i + 1 << ": ";
        cin >> x;
        InsertLast(list2, x);
    }
    
    // 6. Thêm list2 vào list1
    AppendList(list1, list2);
    
    // 7. In danh sách list1 sau khi thêm
    cout << "Danh sach thu nhat sau khi them danh sach thu hai: ";
    Display(list1);
    
    // Hủy cả hai danh sách trước khi kết thúc
    Destroy(list1);
    Destroy(list2);
    
    return 0;
}