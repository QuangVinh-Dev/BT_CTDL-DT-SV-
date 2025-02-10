#include <iostream>
#include <fstream>

using namespace std;

void docMang2Chieu(const string& tenFile) {
    ifstream file(tenFile);
    if (!file) {
        cerr << "Không thể mở file!" << endl;
        return;
    }
    
    int n, m;
    file >> n >> m; // Đọc số dòng và số cột
    int mangSoNguyen[100][100]; // Giả sử mảng có tối đa 100x100 phần tử
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            file >> mangSoNguyen[i][j]; // Đọc từng số nguyên vào mảng
        }
    }
    
    file.close();
    
    cout << "Mảng số nguyên trong file:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mangSoNguyen[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    docMang2Chieu("MangSo.inp");
    return 0;
}
