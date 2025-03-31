#include<iostream>
using namespace std;

//Tao cấu trúc cây nhị phân
struct Node
{
    int data;
    Node* left;
    Node* right;
};
typedef Node* Tree;

Node* CreateNode(int value)
{
    Node* p = new Node;
    if(p == NULL) return NULL;
    p->left = NULL;
    p->right = NULL;
    p->data = value;
    return p;
}

//Them node vao cay
void ThemNode(Tree &root, Node* p)
{
    if (root == NULL)
        root = p;
    else
    {
        if (p->data < root->data) 
            ThemNode(root->left, p);
        else if (p->data > root->data) 
            ThemNode(root->right, p);
    }
}

//Nhap Node
void NhapNode(Tree &root)
{
    int n, value;
    cout << "Nhap so luong Node: "; 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap gia tri Node thu " << i + 1 << ": "; 
        cin >> value;
        Node* p = CreateNode(value);
        if (p == NULL)
        {
            cout << "Khong tao duoc Node" << endl;
            return;
        }
        ThemNode(root, p);
    }
}

//Cau a: Viết chương trình tính trung bình cộng các nút trong cây.

//dem Node
int DemNode(Tree root)
{
    if (root == NULL) return 0;
    return DemNode(root->left) + DemNode(root->right) + 1;
}

//Tinh tong Node
int TinhTong(Tree root)
{
    if(root == NULL) return 0;
    return root->data + TinhTong(root->left) + TinhTong(root->right);
}

//Tinh trung binh cong
float TrungBinhCong(Tree root)
{
    int count = DemNode(root);
    if(count == 0) return 0;
    return (float)TinhTong(root)/count;
}

// Cau b: Viết chương trình tính trung bình cộng các số dương trong cây.

int DemNodeDuong(Tree root)
{
    if (root == NULL) return 0;
    int count = DemNodeDuong(root->left) + DemNodeDuong(root->right);
    if (root->data > 0) return count + 1;
    return count;
}

int TinhTongDuong(Tree root)
{
    if (root == NULL) return 0;
    int sum = TinhTongDuong(root->left) + TinhTongDuong(root->right);
    if (root->data > 0) return sum + root->data;
    return sum;
}

float TrungBinhCongDuong(Tree root)
{
    int count = DemNodeDuong(root);
    if (count == 0) return 0;
    return (float)TinhTongDuong(root) / count;
}

// Cau c: Viết chương trình tính trung bình cộng các số âm trong cây.

int DemNodeAm(Tree root)
{
    if (root == NULL) return 0;
    int count = DemNodeAm(root->left) + DemNodeAm(root->right);
    if (root->data < 0) return count + 1;
    return count;
}

int TongAm(Tree root)
{
    if (root == NULL) return 0;
    int sum = TongAm(root->left) + TongAm(root->right);
    if (root->data < 0) return sum + root->data;
    return sum;
}

float TrungBinhCongAm(Tree root)
{
    int count = DemNodeAm(root);
    if (count == 0) return 0;
    return (float)TongAm(root) / count;
}

// Cau d: Viết chương trình tính tính tỉ số R=a/b. Với a là tổng các nút có giá trị
// dương, b là tổng các nút có giá trị âm.
float tinhtyso(Tree root)
{
    int a = TinhTongDuong(root);
    int b = TongAm(root);
    if (b == 0) return 0;
    return (float)a / b;
}
void TestCase()
{
    Tree root = NULL;
    int testValues[] = {10, -5, 15, 3, -8, 12, 20, -2, 4};
    int n = sizeof(testValues) / sizeof(testValues[0]);
    
    for (int i = 0; i < n; i++)
    {
        Node* p = CreateNode(testValues[i]);
        ThemNode(root, p);
    }
    
    cout << "\nTest Case: \n";
    cout << "Cau a: Trung binh cong cac node trong cay la: " << TrungBinhCong(root) << endl;
    cout << "Cau b: Trung binh cong cac node duong trong cay la: " << TrungBinhCongDuong(root) << endl;
    cout << "Cau c: Trung binh cong cac node am trong cay la: " << TrungBinhCongAm(root) << endl;
    cout << "Cau d: Ty so R = a/b la: " << tinhtyso(root) << endl;
}

int main()
{
    Tree root = NULL;
    NhapNode(root);
    cout << "Cau a: Trung binh cong cac node trong cay la: " << TrungBinhCong(root) << endl;
    cout << "Cau b: Trung binh cong cac node duong trong cay la: " << TrungBinhCongDuong(root) << endl;
    cout << "Cau c: Trung binh cong cac node am trong cay la: " << TrungBinhCongAm(root) << endl;
    cout << "Cau d: Ty so R = a/b la: " << tinhtyso(root) << endl;
    TestCase();
    return 0;
}