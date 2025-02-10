#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
#define MAX 100
//Câu a
typedef struct
{
    char Maso[10];
    char Ho[10];
    char Ten[50];
    int Gioitinh;//0: Nam, 1: Nu
    int ThamNien;
} NhanVien;
typedef struct
{
    NhanVien aNhanVien[MAX];
    int soluong;
}PhongBan;
//Câu b
void NhapPB(PhongBan &pb)
{
    cout<<"Nhap so luong nhan vien: ";
    cin>>pb.soluong;
    //Nhập thông tin cho từng nhân viên
    for(int i=0;i<pb.soluong;i++)
    {
        cout<<"Nhap ma so nhan vien thu "<<i+1<<": "<<endl;
            cout<<"Nhap ma so: ";cin>>pb.aNhanVien[i].Maso;
            cout<<"Nhap ho: ";cin>>pb.aNhanVien[i].Ho;
            cout<<"Nhap ten: ";cin>>pb.aNhanVien[i].Ten;
            cout<<"Nhap gioi tinh (0: Nam, 1: Nu): ";cin>>pb.aNhanVien[i].Gioitinh; 
            cout<<"Nhap tham nien: ";cin>>pb.aNhanVien[i].ThamNien;
    }
}
// Câu c
void XuatPB(PhongBan pb)
{
    cout<<"So luong nhan vien: "<<pb.soluong<<endl;
    for(int i=0;i<pb.soluong;i++)
    {
        cout<<"Thong tin nhan vien thu "<<i+1<<": "<<endl;
        cout<<"Ma so: "<<pb.aNhanVien[i].Maso<<endl;
        cout<<"Ho: "<<pb.aNhanVien[i].Ho<<endl;
        cout<<"Ten: "<<pb.aNhanVien[i].Ten<<endl;
        cout<<"Gioi tinh: "<<pb.aNhanVien[i].Gioitinh<<endl;
        cout<<"Tham nien: "<<pb.aNhanVien[i].ThamNien<<endl;
    }
}
//Câu d
void Demsiso(PhongBan pb,int &sonam,int &sonu)
{
    sonam=0;
    sonu=0;
    for(int i=0;i<pb.soluong;i++)
    {
        if(pb.aNhanVien[i].Gioitinh==0)
            sonam++;
        else
            sonu++;
    }
}
//Câu e
void SapXepTangTheoThamNien(PhongBan &pb) {
    for (int i = 0; i < pb.soluong - 1; i++) {
        for (int j = i + 1; j < pb.soluong; j++) {
            if (pb.aNhanVien[i].ThamNien > pb.aNhanVien[j].ThamNien) {
                NhanVien temp = pb.aNhanVien[i];
                pb.aNhanVien[i] = pb.aNhanVien[j];
                pb.aNhanVien[j] = temp;
            }
        }
    }
}
int main()
{
    PhongBan pb;
    int sonam,sonu;
    NhapPB(pb);
    XuatPB(pb);
    Demsiso(pb,sonam,sonu);
    cout<<"So nhan vien nam: "<<sonam<<endl;
    cout<<"So nhan vien nu: "<<sonu<<endl;
    SapXepTangTheoThamNien(pb);
    cout<<"Danh sach nhan vien sau khi sap xep tang theo tham nien: "<<endl;
    XuatPB(pb);
    getch();
    return 0;
}