#include<iostream>
#include<cstring>
using namespace std;

// (a) Cấu trúc SinhVien
struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
    SinhVien* next;
};

// Hàm nhập một sinh viên
void NhapSinhVien(SinhVien*& sv) {
    sv = new SinhVien;
    cout << "Nhap ho ten: ";
    cin.ignore(); // Xóa bộ đệm trước khi nhập chuỗi
    cin.getline(sv->hoTen, 50);
    cout << "Nhap dia chi: ";
    cin.getline(sv->diaChi, 70);
    cout << "Nhap lop: ";
    cin.getline(sv->lop, 10);
    cout << "Nhap khoa: ";
    cin >> sv->khoa;
    sv->next = NULL;
}

// Hàm xuất một sinh viên
void XuatSinhVien(SinhVien* sv) {
    cout << "Ho ten: " << sv->hoTen << " | Dia chi: " << sv->diaChi 
         << " | Lop: " << sv->lop << " | Khoa: " << sv->khoa << endl;
}

// 4 hàm so sánh theo từng tiêu chí
int SoSanhHoTen(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->hoTen, sv2->hoTen);
}

int SoSanhDiaChi(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->diaChi, sv2->diaChi);
}

int SoSanhLop(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->lop, sv2->lop);
}

int SoSanhKhoa(SinhVien* sv1, SinhVien* sv2) {
    return sv1->khoa - sv2->khoa;
}

// (b) Danh sách liên kết ListSV
// Khởi tạo danh sách rỗng
void Init(SinhVien*& pHead) {
    pHead = NULL;
}

// Kiểm tra danh sách rỗng
bool IsEmpty(SinhVien* pHead) {
    return pHead == NULL;
}

// Thêm phần tử vào cuối danh sách
void InsertLast(SinhVien*& pHead, SinhVien* sv) {
    if (IsEmpty(pHead)) {
        pHead = sv;
    } else {
        SinhVien* p = pHead;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = sv;
    }
}

// Xóa phần tử theo tiêu chí (dùng con trỏ hàm so sánh)
void DeleteSinhVien(SinhVien*& pHead, const char* value, int (*SoSanh)(SinhVien*, SinhVien*), int field) {
    if (IsEmpty(pHead)) {
        cout << "Danh sach rong, khong the xoa!" << endl;
        return;
    }
    
    // Nếu phần tử đầu cần xóa
    SinhVien temp;
    strcpy(temp.hoTen, field == 0 ? value : "");
    strcpy(temp.diaChi, field == 1 ? value : "");
    strcpy(temp.lop, field == 2 ? value : "");
    temp.khoa = field == 3 ? atoi(value) : 0;
    
    if (SoSanh(pHead, &temp) == 0) {
        SinhVien* p = pHead;
        pHead = pHead->next;
        delete p;
        return;
    }
    
    // Tìm và xóa phần tử
    SinhVien* p = pHead;
    while (p->next != NULL && SoSanh(p->next, &temp) != 0) {
        p = p->next;
    }
    
    if (p->next == NULL) {
        cout << "Khong tim thay sinh vien voi gia tri " << value << endl;
    } else {
        SinhVien* q = p->next;
        p->next = q->next;
        delete q;
    }
}

// Thêm một danh sách vào danh sách hiện tại
void AppendList(SinhVien*& list1, SinhVien* list2) {
    if (IsEmpty(list2)) return;
    
    SinhVien* p = list2;
    while (p != NULL) {
        SinhVien* sv = new SinhVien;
        strcpy(sv->hoTen, p->hoTen);
        strcpy(sv->diaChi, p->diaChi);
        strcpy(sv->lop, p->lop);
        sv->khoa = p->khoa;
        sv->next = NULL;
        InsertLast(list1, sv);
        p = p->next;
    }
}

// Xuất danh sách
void Display(SinhVien* pHead) {
    if (IsEmpty(pHead)) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    SinhVien* p = pHead;
    while (p != NULL) {
        XuatSinhVien(p);
        p = p->next;
    }
    cout << "-------------------" << endl;
}

// Hủy danh sách
void Destroy(SinhVien*& pHead) {
    while (pHead != NULL) {
        SinhVien* p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// Sắp xếp danh sách bằng Selection Sort với con trỏ hàm so sánh
void SelectionSort(SinhVien*& pHead, int (*SoSanh)(SinhVien*, SinhVien*)) {
    if (IsEmpty(pHead) || pHead->next == NULL) return;
    
    SinhVien* i = pHead;
    while (i != NULL) {
        SinhVien* min = i;
        SinhVien* j = i->next;
        while (j != NULL) {
            if (SoSanh(j, min) < 0) {
                min = j;
            }
            j = j->next;
        }
        if (min != i) {
            // Hoán đổi dữ liệu giữa i và min
            SinhVien temp;
            strcpy(temp.hoTen, i->hoTen);
            strcpy(temp.diaChi, i->diaChi);
            strcpy(temp.lop, i->lop);
            temp.khoa = i->khoa;
            
            strcpy(i->hoTen, min->hoTen);
            strcpy(i->diaChi, min->diaChi);
            strcpy(i->lop, min->lop);
            i->khoa = min->khoa;
            
            strcpy(min->hoTen, temp.hoTen);
            strcpy(min->diaChi, temp.diaChi);
            strcpy(min->lop, temp.hoTen);
            min->khoa = temp.khoa;
        }
        i = i->next;
    }
}

// (c) Chương trình chính
int main() {
    SinhVien* listSV = NULL;
    Init(listSV);
    
    // 1. Nhập 10 sinh viên
    cout << "Nhap thong tin 10 sinh vien:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Sinh vien " << i + 1 << ":\n";
        SinhVien* sv;
        NhapSinhVien(sv);
        InsertLast(listSV, sv);
    }
    
    // 2. In danh sách
    cout << "\nDanh sach sinh vien ban dau:\n";
    Display(listSV);
    
    // 3. Xóa sinh viên có tên "Nguyen Van Teo"
    DeleteSinhVien(listSV, "Nguyen Van Teo", SoSanhHoTen, 0);
    
    // 4. Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    DeleteSinhVien(listSV, "Nguyen Van Cu", SoSanhDiaChi, 1);
    
    // 5. Thêm sinh viên mới
    SinhVien* svMoi = new SinhVien;
    strcpy(svMoi->hoTen, "Tran Thi Mo");
    strcpy(svMoi->diaChi, "25 Hong Bang");
    strcpy(svMoi->lop, "TT0901");
    svMoi->khoa = 2009;
    svMoi->next = NULL;
    InsertLast(listSV, svMoi);
    
    // 6. In danh sách sau khi chỉnh sửa
    cout << "\nDanh sach sau khi chinh sua:\n";
    Display(listSV);
    
    // (Tùy chọn) Sắp xếp và in lại danh sách theo họ tên
    SelectionSort(listSV, SoSanhHoTen);
    cout << "\nDanh sach sau khi sap xep theo ho ten:\n";
    Display(listSV);
    
    // Hủy danh sách trước khi kết thúc
    Destroy(listSV);
    
    return 0;
}