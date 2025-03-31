#include <iostream>
#include <stack>
#include <queue>
#include <cmath> // Dùng abs() để kiểm tra độ cao
using namespace std;

// **Định nghĩa cấu trúc cây nhị phân**
struct NODE {
    int info;
    NODE* pLeft;
    NODE* pRight;
};
typedef NODE* TREE;

// **Tạo một nút mới**
NODE* CreateNode(int value) {
    NODE* p = new NODE;
    if (!p) return NULL;
    p->info = value;
    p->pLeft = p->pRight = NULL;
    return p;
}

// **Chèn một nút vào cây nhị phân tìm kiếm (BST)**
void InsertNode(TREE &root, int value) {
    if (root == NULL) {
        root = CreateNode(value);
        return;
    }
    if (value < root->info)
        InsertNode(root->pLeft, value);
    else if (value > root->info)
        InsertNode(root->pRight, value);
}

// **1️⃣ Duyệt cây theo thứ tự NLR không dùng đệ quy (dùng stack)**
void DuyetNLR_KhongDeQuy(TREE root) {
    if (root == NULL) return;
    stack<NODE*> s;
    s.push(root);

    while (!s.empty()) {
        NODE* temp = s.top();
        s.pop();
        cout << temp->info << " "; // Xử lý nút hiện tại

        if (temp->pRight) s.push(temp->pRight);
        if (temp->pLeft) s.push(temp->pLeft);
    }
}

// **2️⃣ Duyệt cây theo mức không dùng đệ quy (dùng queue)**
void DuyetTheoMuc(TREE root) {
    if (root == NULL) return;
    queue<NODE*> q;
    q.push(root);

    while (!q.empty()) {
        NODE* temp = q.front();
        q.pop();
        cout << temp->info << " ";

        if (temp->pLeft) q.push(temp->pLeft);
        if (temp->pRight) q.push(temp->pRight);
    }
}

// **3️⃣ Tìm phần tử lớn nhất trong cây**
NODE* LonNhat(TREE t) {
    if (t == NULL) return NULL;
    NODE* lc = t;
    NODE* a = LonNhat(t->pLeft);
    if (a && a->info > lc->info) lc = a;
    NODE* b = LonNhat(t->pRight);
    if (b && b->info > lc->info) lc = b;
    return lc;
}

// **4️⃣ Tìm phần tử nhỏ nhất trong cây**
NODE* NhoNhat(TREE t) {
    if (t == NULL) return NULL;
    NODE* lc = t;
    NODE* a = NhoNhat(t->pLeft);
    if (a && a->info < lc->info) lc = a;
    NODE* b = NhoNhat(t->pRight);
    if (b && b->info < lc->info) lc = b;
    return lc;
}

// **5️⃣ Tính chiều cao của cây**
int ChieuCao(TREE t) {
    if (t == NULL) return 0;
    int a = ChieuCao(t->pLeft);
    int b = ChieuCao(t->pRight);
    return max(a, b) + 1;
}

// **6️⃣ Kiểm tra cây có cân bằng không**
int ktCanBang(TREE root) {
    if (root == NULL) return 1;
    
    if (!ktCanBang(root->pLeft) || !ktCanBang(root->pRight)) return 0;

    NODE* a = LonNhat(root->pLeft);
    if (a && a->info > root->info) return 0;

    a = NhoNhat(root->pRight);
    if (a && a->info < root->info) return 0;

    int x = ChieuCao(root->pLeft);
    int y = ChieuCao(root->pRight);

    return abs(x - y) <= 1;
}

// **Hàm kiểm tra và hiển thị kết quả**
void TestCanBang(TREE root) {
    if (ktCanBang(root))
        cout << "Cay can bang\n";
    else
        cout << "Cay khong can bang\n";
}

// **Hàm chính để test**
int main() {
    TREE t = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Tạo cây từ mảng
    for (int i = 0; i < n; i++) {
        InsertNode(t, arr[i]);
    }

    // Test các thuật toán
    cout << "Duyet NLR (khong de quy): ";
    DuyetNLR_KhongDeQuy(t);
    cout << "\n";

    cout << "Duyet theo muc: ";
    DuyetTheoMuc(t);
    cout << "\n";

    cout << "Phan tu lon nhat: " << LonNhat(t)->info << "\n";
    cout << "Phan tu nho nhat: " << NhoNhat(t)->info << "\n";
    cout << "Chieu cao cua cay: " << ChieuCao(t) << "\n";

    // Kiểm tra cây có cân bằng không
    TestCanBang(t);

    return 0;
}
