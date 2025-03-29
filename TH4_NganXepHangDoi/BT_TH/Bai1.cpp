#include <iostream>
#include <stack>
#include <string>
#define MAX 100

using namespace std;

// Cấu trúc Stack dùng mảng
int top;
int arr[MAX];

// Khởi tạo Stack
void Init() {
    top = -1;
}

// Kiểm tra Stack rỗng
bool IsEmpty() {
    return (top == -1);
}

// Kiểm tra Stack đầy
bool IsFull() {
    return (top == MAX - 1);
}

// Thêm phần tử vào Stack
void Push(int value) {
    if (IsFull()) {
        cout << "Stack đầy!" << endl;
        return;
    }
    arr[++top] = value;
}

// Xóa phần tử khỏi Stack
int Pop() {
    if (IsEmpty()) {
        cout << "Stack rỗng!" << endl;
        return -1;
    }
    return arr[top--];
}

// Lấy phần tử đầu Stack mà không xóa
int Peek() {
    if (IsEmpty()) {
        cout << "Stack rỗng!" << endl;
        return -1;
    }
    return arr[top];
}

// Xóa toàn bộ Stack
void Clear() {
    top = -1;
}

// (b) Ứng dụng đảo số
int Reverse(int num) {
    Init();
    while (num != 0) {
        Push(num % 10);
        num /= 10;
    }
    int reversed = 0;
    int factor = 1;
    while (!IsEmpty()) {
        reversed += Pop() * factor;
        factor *= 10;
    }
    return reversed;
}

// (c) Kiểm tra chuỗi đối xứng
bool IsPalindrome(const string &str) {
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    for (char ch : str) {
        if (s.top() != ch) return false;
        s.pop();
    }
    return true;
}

// (d) Chuyển số thập phân sang nhị phân
void DecimalToBinary(int num) {
    Init();
    while (num > 0) {
        Push(num % 2);
        num /= 2;
    }
    while (!IsEmpty()) {
        cout << Pop();
    }
    cout << endl;
}

// (e) Chuyển trung tố sang hậu tố và tính toán biểu thức hậu tố
float Evaluate(char *Postfix) {
    stack<float> S;
    const char *p = Postfix;
    while (*p != '\0') {
        while (*p == ' ' || *p == '\t') p++;
        if (isdigit(*p)) {
            float num = 0;
            while (isdigit(*p)) {
                num = num * 10 + (*p - '0');
                p++;
            }
            S.push(num);
        } else {
            if (S.size() < 2) {
                cout << "Không đủ toán hạng!" << endl;
                return 0;
            }
            float op1 = S.top(); S.pop();
            float op2 = S.top(); S.pop();
            float result = 0;
            switch (*p) {
                case '+': result = op2 + op1; break;
                case '-': result = op2 - op1; break;
                case '*': result = op2 * op1; break;
                case '/': 
                    if (op1 == 0) {
                        cout << "Lỗi chia cho 0!" << endl;
                        return 0;
                    }
                    result = op2 / op1; break;
                default:
                    cout << "Toán tử không hợp lệ!" << endl;
                    return 0;
            }
            S.push(result);
        }
        p++;
    }
    return S.top();
}

int main() {
    Init();
    cout << " Câu b : Đảo số của 12345: " << Reverse(12345) << endl;
    cout << " Câu c : Kiểm tra 'madam' có đối xứng không: " << (IsPalindrome("madam") ? "Có" : "Không") << endl;
    cout << " Câu d : Số 10 đổi sang nhị phân: "; DecimalToBinary(10);
    
    char postfix[] = "23 34 + 2 *";
    cout << " Câu e : Giá trị của biểu thức hậu tố: " << Evaluate(postfix) << endl;
    
    return 0;
}
