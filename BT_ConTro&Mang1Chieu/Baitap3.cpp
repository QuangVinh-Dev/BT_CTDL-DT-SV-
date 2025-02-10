#include <iostream>
#define Max 100
using namespace std;

void Nhap_Mang(char **a, int *n) {
    cout << "Nhap so phan tu cua mang: ";
    cin >> (*n);
    while ((*n) <= 0 || (*n) > Max) {
        cout << "Nhap sai, moi nhap lai: ";
        cin >> (*n);
    }

    // Cấp phát đúng kiểu char*
    (*a) = new char[(*n)];
    for (int i = 0; i < *n; i++) {
        cout << "Nhap phan tu thu " << i << " : ";
        cin >> (*a)[i];
    }
}

void Xuat_Mang(char *a, int n) {
    for (int i = 0; i < n; i++) {  // Sửa n-1 thành n
        cout << a[i] << " ";
    }
    cout << endl;
}

bool KT_Nguyen_Am(char c) {
    char nguyenam[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    for (int i = 0; i < 10; i++) {
        if (c == nguyenam[i]) {
            return true;
        }
    }
    return false;
}

bool tao_mang_Nguyen_Am(char *a, int n, char **b, int *m) {
    *m = 0;
    *b = new char[n];  // Cấp phát mảng b

    for (int i = 0; i < n; i++) {
        if (KT_Nguyen_Am(a[i])) {
            (*b)[(*m)++] = a[i];
        }
    }
    return (*m > 0);  // Trả về false nếu không có nguyên âm nào
}

int main() {
    char *a, *b;
    int n, m;

    Nhap_Mang(&a, &n);
    tao_mang_Nguyen_Am(a, n, &b, &m);

    cout << "Mang nguyen am: ";
    if (m > 0) 
        Xuat_Mang(b, m);
    else 
        cout << "Mang khong co nguyen am." << endl;

    delete[] a;
    delete[] b;
    return 0;
}
