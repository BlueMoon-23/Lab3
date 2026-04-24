#include <iostream>
#include "DSNhanVien.h"
using namespace std;

int main()
{
    DSNhanVien Danhsach;
    Danhsach.NhapDanhSach();
    Danhsach.XuatDanhSach();
    cout << "\nNhan vien co luong thap nhat: ";
    cout << Danhsach.NVLuongThapNhat().getHoTen();
    cout << "\nTong luong ma cong ty phai tra cho cac nhan vien san xuat: ";
    cout << Danhsach.TongLuong();
    cout << "\nNhan vien co tuoi cao nhat: ";
    cout << Danhsach.NVTuoiCaoNhat().getHoTen();
    Danhsach.SapXepTangDan();
    cout << "\nSau khi sap xep tang dan theo luong:\n";
    Danhsach.XuatDanhSach();
}
