#include <iostream>
#include "cTamGiac.h"
using namespace std;

int main()
{
    cTamGiac TamGiac;
    TamGiac.Nhap();
    TamGiac.Xuat();
    cout << "\n";
    TamGiac.KiemTra();
    cout << "\nChu vi tam giac: " << TamGiac.ChuVi();
    cout << "\nDien tich tam giac: " << TamGiac.DienTich();
    Diem vector;
    cout << "\nNhap toa do vector tinh tien de tinh tien tam giac: ";
    vector.Nhap();
    TamGiac.TinhTien(vector);
    cout << "\nTam giac sau khi tinh tien: ";
    TamGiac.Xuat();
    double Goc;
    cout << "\nNhap goc quay (don vi do) de quay tam giac: ";
    cin >> Goc;
    TamGiac.Quay(Goc);
    cout << "\nTam giac sau khi quay: ";
    TamGiac.Xuat();
    double TyLePhongTo;
    cout << "\nNhap ty le phong to de phong to tam giac: ";
    cin >> TyLePhongTo;
    TamGiac.PhongTo(TyLePhongTo);
    cout << "\nTam giac sau khi phong to: ";
    TamGiac.Xuat();
    double TyLeThuNho;
    cout << "\nNhap ty le thu nho de thu nho tam giac: ";
    cin >> TyLeThuNho;
    TamGiac.ThuNho(TyLeThuNho);
    cout << "\nTam giac sau khi thu nho: ";
    TamGiac.Xuat();
}


