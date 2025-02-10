#include<iostream>
#include<cstring>
using namespace std;

#define MAX 20

typedef struct {
    char Ten[50];
    int SoLuong;
    char DVT[10];
    float DonGia;
} LoaiHoa;

typedef struct {
    LoaiHoa aLoaiHoa[MAX];
    int SoLuong;
} DanhSachLoaiHoa;

void NhapDanhSach(DanhSachLoaiHoa &ds) {
    cout << "Nhap so luong loai hoa: ";
    cin >> ds.SoLuong;
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Nhap thong tin loai hoa thu " << i + 1 << ":\n";
        cout << "Ten loai: ";
        cin.ignore();
        cin.getline(ds.aLoaiHoa[i].Ten, 50);
        cout << "So luong: ";
        cin >> ds.aLoaiHoa[i].SoLuong;
        cout << "Don vi tinh: ";
        cin.ignore();
        cin.getline(ds.aLoaiHoa[i].DVT, 10);
        cout << "Don gia: ";
        cin >> ds.aLoaiHoa[i].DonGia;
    }
}

void XuatDanhSach(DanhSachLoaiHoa ds) {
    cout << "So luong loai hoa: " << ds.SoLuong << endl;
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Loai hoa thu " << i + 1 << ":\n";
        cout << "Ten loai: " << ds.aLoaiHoa[i].Ten << endl;
        cout << "So luong: " << ds.aLoaiHoa[i].SoLuong << endl;
        cout << "Don vi tinh: " << ds.aLoaiHoa[i].DVT << endl;
        cout << "Don gia: " << ds.aLoaiHoa[i].DonGia << endl;
    }
}

int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai) {
    for (int i = 0; i < ds.SoLuong; i++) {
        if (strcmp(ds.aLoaiHoa[i].Ten, tenloai) == 0) {
            return i;
        }
    }
    return -1;
}

void XuLyBanHoa(DanhSachLoaiHoa &ds, char *tenloai, int soluong) {
    int index = TimLoaiHoa(ds, tenloai);
    if (index == -1) {
        cout << "Khong tim thay loai hoa " << tenloai << endl;
    } else {
        if (ds.aLoaiHoa[index].SoLuong < soluong) {
            cout << "Khong du so luong hoa " << tenloai << " de ban" << endl;
        } else {
            float tongtien = soluong * ds.aLoaiHoa[index].DonGia;
            cout << "Tong tien: " << tongtien << endl;
            ds.aLoaiHoa[index].SoLuong -= soluong;
        }
    }
}

int main() {
    DanhSachLoaiHoa ds;
    NhapDanhSach(ds);
    XuatDanhSach(ds);

    char tenloai[50];
    int soluong;
    cout << "Nhap ten loai hoa can mua: ";
    cin.ignore();
    cin.getline(tenloai, 50);
    cout << "Nhap so luong can mua: ";
    cin >> soluong;

    XuLyBanHoa(ds, tenloai, soluong);
    XuatDanhSach(ds);

    return 0;
}