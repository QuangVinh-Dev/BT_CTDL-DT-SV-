#include <iostream>
using namespace std;

struct TreeNode {
    int key; // Khóa của node
    int So_lan; // Số lần xuất hiện
    TreeNode* left;
    TreeNode* right;
};

struct BST_TREE {
    TreeNode* pRoot; // Nút gốc của cây
};

// Hàm tạo node mới
TreeNode* CreateNode(int value) {
    TreeNode* p = new TreeNode;
    p->key = value;
    p->So_lan = 1;
    p->left = p->right = NULL;
    return p;
}

// Hàm chèn một phần tử vào BST
void InsertNode(TreeNode*& root, int value) {
    if (root == NULL) {
        root = CreateNode(value);
        return;
    }
    if (value < root->key)
        InsertNode(root->left, value);
    else if (value > root->key)
        InsertNode(root->right, value);
    else
        root->So_lan++; // Nếu trùng giá trị, tăng So_lan
}

// Tìm node nhỏ nhất trong cây con phải (dùng cho xóa)
TreeNode* FindMin(TreeNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Hàm xóa nút trong BST
TreeNode* DeleteNode(TreeNode* root, int value) {
    if (root == NULL) {
        cout << "Khong tim thay " << value << " trong cay." << endl;
        return root;
    }

    if (value < root->key)
        root->left = DeleteNode(root->left, value);
    else if (value > root->key)
        root->right = DeleteNode(root->right, value);
    else {
        // Nếu So_lan > 1, chỉ giảm số lần xuất hiện
        if (root->So_lan > 1) {
            root->So_lan--;
            cout << "Giam So_lan cua " << value << " xuong " << root->So_lan << endl;
            return root;
        }

        // Nếu So_lan == 1, xóa theo quy tắc BST
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Nếu có 2 con, tìm phần tử nhỏ nhất của cây con phải
        TreeNode* temp = FindMin(root->right);
        root->key = temp->key;
        root->So_lan = temp->So_lan; // Sao chép số lần xuất hiện
        temp->So_lan = 1; // Đặt về 1 để xóa
        root->right = DeleteNode(root->right, temp->key);
    }
    return root;
}

// Hàm xóa giá trị trong cây BST_TREE
void XoaGiaTri(BST_TREE& t, int value) {
    t.pRoot = DeleteNode(t.pRoot, value);
}

// Hàm duyệt cây theo NLR
void NLR(TreeNode* root) {
    if (root == NULL) return;
    cout << root->key << " (" << root->So_lan << ") ";
    NLR(root->left);
    NLR(root->right);
}

// Hàm khởi tạo cây
void KhoiTaoCay(BST_TREE& t) {
    t.pRoot = NULL;
}

// Hàm nhập dữ liệu cho cây BST_TREE
void NhapCay(BST_TREE& t, int arr[], int n) {
    for (int i = 0; i < n; i++)
        InsertNode(t.pRoot, arr[i]);
}

// Hàm test key
void TestBST() {
    BST_TREE t;
    KhoiTaoCay(t);

    int arr[] = {50, 30, 70, 20, 40, 60, 80, 30, 70, 50}; // 30, 50, 70 xuất hiện 2 lần
    int n = sizeof(arr) / sizeof(arr[0]);

    // Chèn các phần tử vào BST
    NhapCay(t, arr, n);

    // Xuất cây trước khi xóa
    cout << "Cay truoc khi xoa: ";
    NLR(t.pRoot);
    cout << endl;

    // Thử nghiệm xóa các phần tử
    XoaGiaTri(t, 30); // Giảm So_lan
    XoaGiaTri(t, 50); // Giảm So_lan
    XoaGiaTri(t, 80); // Xóa hoàn toàn
    XoaGiaTri(t, 100); // Không tồn tại

    // Xuất cây sau khi xóa
    cout << "Cay sau khi xoa: ";
    NLR(t.pRoot);
    cout << endl;
}

int main() {
    TestBST();
    return 0;
}
