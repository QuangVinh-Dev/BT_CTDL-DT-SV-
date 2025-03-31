#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

typedef Node* Tree;

// Hàm tạo một nút mới
Node* CreateNode(int value) {
    Node* p = new Node;
    if (p == NULL) return NULL;
    p->left = p->right = NULL;
    p->data = value;
    return p;
}

// Hàm thêm một nút vào cây BST
void ThemNode(Tree &root, int value) {
    if (root == NULL) {
        root = CreateNode(value);
    } else {
        if (value < root->data) ThemNode(root->left, value);
        else if (value > root->data) ThemNode(root->right, value);
    }
}

// Hàm đếm số lượng nút trong cây
int DemNode(Tree root) {
    if (root == NULL) return 0;
    return 1 + DemNode(root->left) + DemNode(root->right);
}

// Hàm tính tổng giá trị các nút trong cây
int TinhTong(Tree root) {
    if (root == NULL) return 0;
    return root->data + TinhTong(root->left) + TinhTong(root->right);
}

// ✅ Hàm kiểm thử cây BST
void TestBST() {
    Tree root = NULL;

    // Tạo danh sách giá trị kiểm tra
    int testValues[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(testValues) / sizeof(testValues[0]);

    // Thêm các giá trị vào cây
    for (int i = 0; i < n; i++) {
        ThemNode(root, testValues[i]);
    }

    // Kiểm tra số lượng nút
    cout << "✅ Test: So luong nut trong cay BST: " << DemNode(root) << " (Ky vong: 7)" << endl;

    // Kiểm tra tổng giá trị các nút
    cout << "✅ Test: Tong cac nut trong cay BST: " << TinhTong(root) << " (Ky vong: 350)" << endl;

    // Kiểm tra thêm một node mới
    cout << "➡ Them gia tri 25 vao cay BST..." << endl;
    ThemNode(root, 25);
    cout << "✅ Test: So luong nut moi sau khi them: " << DemNode(root) << " (Ky vong: 8)" << endl;
}

int main() {
    TestBST();
    return 0;
}
