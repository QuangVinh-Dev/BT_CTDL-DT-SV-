#include <iostream>
#include <fstream>

using namespace std;

void docCacSoNguyen(const string& tenFile) {
    ifstream file(tenFile);
    if (!file) {
        cerr << "Không thể mở file!" << endl;
        return;
    }
    
    int n;
    file >> n; // Đọc số lượng phần tử
    int mangSoNguyen[1000]; // Giả sử mảng có tối đa 1000 phần tử
    
    for (int i = 0; i < n; ++i) {
        file >> mangSoNguyen[i]; // Đọc từng số nguyên vào mảng
    }
    
    file.close();
    
    cout << "Các số nguyên trong file: ";
    for (int i = 0; i < n; ++i) {
        cout << mangSoNguyen[i] << " ";
    }
    cout << endl;
}

int main() {
    docCacSoNguyen("DaySoNguyen.inp");
    return 0;
}
