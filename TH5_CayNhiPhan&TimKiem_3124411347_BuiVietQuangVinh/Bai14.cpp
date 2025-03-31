#include <iostream>
using namespace std;

// Cấu trúc nút trong cây nhị phân tìm kiếm (BST)
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Cấu trúc nút trong danh sách liên kết đơn
struct NodeList {
    int data;
    NodeList* next;
};

// Hàm tạo một nút mới trong BST
TreeNode* CreateNode(int value) {
    TreeNode* p = new TreeNode;
    p->data = value;
    p->left = p->right = NULL;
    return p;
}

// Tìm vị trí cần chèn một nút vào cây BST
TreeNode* FindInsertNode(TreeNode* root, int value) {
    if (root == NULL) return NULL;
    TreeNode* p = root;
    TreeNode* f = p;

    while (p != NULL) {
        f = p;
        if (p->data > value)
            p = p->left;
        else
            p = p->right;
    }
    return f;
}

// Chèn một nút vào cây BST
void InsertNode(TreeNode*& root, int value) {
    TreeNode* n = CreateNode(value);
    if (root == NULL) {
        root = n;
        return;
    } else {
        TreeNode* f = FindInsertNode(root, value);
        if (f != NULL) {
            if (f->data > value)
                f->left = n;
            else
                f->right = n;
        }
    }
}

// Tạo cây nhị phân tìm kiếm từ một mảng
void CreateTree(TreeNode*& root, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        InsertNode(root, arr[i]);
    }
}

//  Hàm duyệt cây theo thứ tự NRL (Root - Right - Left)
void Duyet_NRL(TreeNode* root) {
    if (root != NULL) {
        cout << root->data << " "; // Xuất dữ liệu trong nút gốc
        Duyet_NRL(root->right); // Duyệt nhánh phải trước
        Duyet_NRL(root->left);  // Duyệt nhánh trái sau
    }
}


void InsertToList(NodeList*& head, int value) {
    NodeList* newNode = new NodeList;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void TreeToList(TreeNode* root, NodeList*& head) {
    if (root == NULL) return;

    // Duyệt nhánh phải trước (giá trị lớn hơn)
    TreeToList(root->right, head);

    // Chèn nút hiện tại vào danh sách liên kết đơn (chèn đầu để giữ thứ tự giảm dần)
    InsertToList(head, root->data);

    // Duyệt nhánh trái sau (giá trị nhỏ hơn)
    TreeToList(root->left, head);
}

// ✅ Hàm in danh sách liên kết đơn
void PrintList(NodeList* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    TreeNode* root = NULL;
    NodeList* head = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);


    CreateTree(root, values, n);


    cout << "Cay duyet theo thu tu NRL: ";
    Duyet_NRL(root);
    cout << endl;


    TreeToList(root, head);

    // In danh sách liên kết đơn
    cout << "Danh sach lien ket giam dan tu BST: ";
    PrintList(head);

    return 0;
}
