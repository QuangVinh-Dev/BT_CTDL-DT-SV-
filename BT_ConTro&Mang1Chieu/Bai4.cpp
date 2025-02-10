#include <iostream>
using namespace std;

// Hàm nhập mảng đã sắp xếp tăng dần
void nhapMang(float **arr, int *size, char name) {
    cout << "Moi ban nhap so luong phan tu mang " << name << ": ";
    cin >> *size;
    
    while (*size <= 0 || *size > 100) {
        cout << "Nhap sai, moi ban nhap lai: ";
        cin >> *size;
    }

    // Cấp phát động cho mảng
    *arr = new float[*size];
    
    cout << "Nhap cac phan tu cua mang " << name << " theo thu tu tang dan:\n";
    for (int i = 0; i < *size; i++) {
        do {
            cout << "Phan tu " << name << "[" << i << "]: ";
            cin >> (*arr)[i];
        } while (i > 0 && (*arr)[i] < (*arr)[i - 1]); // Đảm bảo nhập tăng dần
    }
}

// Hàm xuất mảng 1 chiều
void xuatMang(float *arr, int size, char name) {
    cout << "Mang " << name << " co " << size << " phan tu: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Hàm merge hai mảng tăng dần thành mảng C
void merge(float *a, int n, float *b, int m, float **c, int *p) {
    *p = n + m;
    *c = new float[*p]; // Cấp phát bộ nhớ cho mảng C

    int i = 0, j = 0, k = 0;

    // Hợp nhất hai mảng theo thuật toán Merge
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            (*c)[k++] = a[i++];
        } else {
            (*c)[k++] = b[j++];
        }
    }

    // Sao chép phần còn lại của mảng A (nếu còn)
    while (i < n) {
        (*c)[k++] = a[i++];
    }

    // Sao chép phần còn lại của mảng B (nếu còn)
    while (j < m) {
        (*c)[k++] = b[j++];
    }
}

int main() {
    float *a, *b, *c;
    int n, m, p;

    // Nhập hai mảng A và B
    nhapMang(&a, &n, 'A');
    nhapMang(&b, &m, 'B');

    // Xuất mảng A và B
    xuatMang(a, n, 'A');
    xuatMang(b, m, 'B');

    // Hợp nhất hai mảng theo thuật toán Merge
    merge(a, n, b, m, &c, &p);

    // Xuất mảng C
    cout << "\nMang C (hop nhat tu A va B): ";
    xuatMang(c, p, 'C');

    // Giải phóng bộ nhớ
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
