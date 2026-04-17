#include <iostream>
#include "cDaGiac.h"

int main()
{
    cDaGiac DaGiac;
    DaGiac.Nhap();
    DaGiac.Xuat();
    cout << "\n";
    DaGiac.KiemTra();
    cout << "\nChu vi da giac: " << DaGiac.ChuVi();
    cout << "\nDien tich da giac: " << DaGiac.DienTich();
    Diem vector;
    cout << "\nNhap toa do vector tinh tien de tinh tien da giac: ";
    vector.Nhap();
    DaGiac.TinhTien(vector);
    cout << "\nDa giac sau khi tinh tien: ";
    DaGiac.Xuat();
    double Goc;
    cout << "\nNhap goc quay (don vi do) de quay da giac: ";
    cin >> Goc;
    DaGiac.Quay(Goc);
    cout << "\nDa giac sau khi quay: ";
    DaGiac.Xuat();
    double TyLePhongTo;
    cout << "\nNhap ty le phong to de phong to da giac: ";
    cin >> TyLePhongTo;
    DaGiac.PhongTo(TyLePhongTo);
    cout << "\nDa giac sau khi phong to: ";
    DaGiac.Xuat();
    double TyLeThuNho;
    cout << "\nNhap ty le thu nho de thu nho da giac: ";
    cin >> TyLeThuNho;
    DaGiac.ThuNho(TyLeThuNho);
    cout << "\nDa giac sau khi thu nho: ";
    DaGiac.Xuat();

}
