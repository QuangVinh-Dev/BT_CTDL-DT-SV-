#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DienThoai {
    string maDienThoai;
    string nhanHieu;
    int gia;
};

class QuanLyDienThoai {
private:
    vector<DienThoai> danhSach;
    const int MAX_SIZE = 100;

public:
    void themDienThoai();
    void timDienThoai();
    void capNhatGia();
    void xoaDienThoai();
    void hienThiDanhSach();
    void menu();
};

void QuanLyDienThoai::themDienThoai() {
    if (danhSach.size() >= MAX_SIZE) {
        cout << "Danh sách đầy, không thể thêm!\n";
        return;
    }
    DienThoai dt;
    cout << "Nhập mã điện thoại: ";
    cin >> dt.maDienThoai;
    
    for (const auto &item : danhSach) {
        if (item.maDienThoai == dt.maDienThoai) {
            cout << "Điện thoại đã tồn tại!\n";
            return;
        }
    }
    
    cout << "Nhập nhãn hiệu: ";
    cin.ignore();
    getline(cin, dt.nhanHieu);
    cout << "Nhập giá: ";
    cin >> dt.gia;
    danhSach.push_back(dt);
    cout << "Thêm điện thoại thành công!\n";
}

void QuanLyDienThoai::timDienThoai() {
    string ma;
    cout << "Nhập mã điện thoại cần tìm: ";
    cin >> ma;
    for (const auto &dt : danhSach) {
        if (dt.maDienThoai == ma) {
            cout << "Nhãn hiệu: " << dt.nhanHieu << ", Giá: " << dt.gia << "\n";
            return;
        }
    }
    cout << "Không tìm thấy điện thoại!\n";
}

void QuanLyDienThoai::capNhatGia() {
    string ma;
    int giaMoi;
    cout << "Nhập mã điện thoại cần cập nhật giá: ";
    cin >> ma;
    for (auto &dt : danhSach) {
        if (dt.maDienThoai == ma) {
            cout << "Nhập giá mới: ";
            cin >> giaMoi;
            dt.gia = giaMoi;
            cout << "Cập nhật giá thành công!\n";
            return;
        }
    }
    cout << "Không tìm thấy điện thoại!\n";
}

void QuanLyDienThoai::xoaDienThoai() {
    string ma;
    cout << "Nhập mã điện thoại cần xóa: ";
    cin >> ma;
    for (size_t i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].maDienThoai == ma) {
            danhSach.erase(danhSach.begin() + i);
            cout << "Xóa điện thoại thành công!\n";
            return;
        }
    }
    cout << "Không tìm thấy điện thoại!\n";
}

void QuanLyDienThoai::hienThiDanhSach() {
    if (danhSach.empty()) {
        cout << "Danh sách trống!\n";
        return;
    }
    for (const auto &dt : danhSach) {
        cout << "Mã: " << dt.maDienThoai << ", Nhãn hiệu: " << dt.nhanHieu << ", Giá: " << dt.gia << "\n";
    }
}

void QuanLyDienThoai::menu() {
    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Thêm điện thoại\n";
        cout << "2. Tìm điện thoại\n";
        cout << "3. Cập nhật giá điện thoại\n";
        cout << "4. Xóa điện thoại\n";
        cout << "5. Hiển thị danh sách điện thoại\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn: ";
        cin >> choice;

        switch (choice) {
            case 1: themDienThoai(); break;
            case 2: timDienThoai(); break;
            case 3: capNhatGia(); break;
            case 4: xoaDienThoai(); break;
            case 5: hienThiDanhSach(); break;
            case 0: cout << "Thoát chương trình!\n"; break;
            default: cout << "Lựa chọn không hợp lệ!\n";
        }
    } while (choice != 0);
}

int main() {
    QuanLyDienThoai qldt;
    qldt.menu();
    return 0;
}
