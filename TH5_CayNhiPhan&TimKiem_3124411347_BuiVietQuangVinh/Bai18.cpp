/*Cho một mảng a gồm n phần tử kiểu số nguyên int. Ta có thể sắp xếp mảng a
bằng cách:
• Từ mảng a, tạo một cây nhị phân tìm kiếm T.
• Duyệt cây T và đưa các nút trở lại mảng a.
• Yêu cầu
a) Cho biết phương pháp duyệt cây T để đưa các nút lên mảng sao cho mảng
được sắp tăng dần.
b) Cho biết cấu trúc cây T.
c) Xây dựng hàm
• Tạo cnp T từ mảng a.
• Duyệt cây để đưa các phần tử trở lại mảng sao cho mảng được sắp thứ tự
tăng dần. */


//Câu a:Duyệt cây theo thứ từ LNR


#include<iostream>
using namespace std;
struct NODE
{
    int data;
    struct NODE*left;
    struct NODE*right;
};
typedef struct NODE Node;
typedef Node*TREE;


//Tao cay nhi phan tu mang
void Init(TREE &t)
{
    t=nullptr;
}
Node* GetNode(int value){
    Node*p=new Node;
    if(p==nullptr) return NULL;
    p->data=value;
    p->left=p->right=nullptr;
    return p;

}

int InsertNode(TREE &t,int value)
{
    if(t)
    {
        if(t->data==value)
            return 0;
        if(t->data <value) return InsertNode(t->right,value);
        else return InsertNode(t->left,value);
    }
    t=GetNode(value);
    if(t==nullptr) return -1;
    return 1;
}


int TaoCay(TREE &t,int arr[],int n)
{
    Init(t);
    for(int i=0;i<n;i++)
    {
        if(InsertNode(t,arr[i])==-1) return 0;
    }
    return 1;
}

//Duyet cay dau tro laii vao mang
void LNR(TREE t,int arr[],int &n)
{
    if(t==nullptr) return ;
    LNR(t->left,arr,n);
    arr[n++]=t->data;
    n++;
    LNR(t->right,arr,n);
}
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Test case
int main() {
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    TREE t;
    TaoCay(t, arr, n);

    int sortedArr[100], sortedSize = 0;
    LNR(t, sortedArr, sortedSize);

    cout << "Mảng sau khi sắp xếp tăng dần bằng BST: ";
    PrintArray(sortedArr, sortedSize);

    return 0;
}
