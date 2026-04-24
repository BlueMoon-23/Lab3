#include "cArray.h"
#include <iostream>
using namespace std;

int main()
{
    int SoPhanTu;
    cout << "Nhap so phan tu cua mang (n > 0): ";
    do {
        cin >> SoPhanTu;
    } while (SoPhanTu <= 0);
    cout << "Tao mang ngau nhien\n";
    cArray DSSoNguyen;
    DSSoNguyen.MangNgauNhien(SoPhanTu);
    cout << "Mang vua duoc tao la: ";
    DSSoNguyen.Xuat();
    int x;
    cout << "\nNhap phan tu x can dem so lan xuat hien: ";
    cin >> x;
    cout << "\nSo lan xuat hien cua " << x << " la: " << DSSoNguyen.SoLanXuatHien(x);
    if (DSSoNguyen.KiemTraTangDan()) {
        cout << "\nKiem tra: mang ban dau tang dan";
    }
    else {
        cout << "\nKiem tra: mang ban dau khong tang dan";
    }
    cout << "\nPhan tu le nho nhat trong mang la: ";
    int minOdd = DSSoNguyen.PhanTuLeNhoNhat();
    if (minOdd != -1) cout << minOdd;
    else cout << "Khong ton tai phan tu le trong mang.";
    cout << "\nSo nguyen to lon nhat trong mang la: ";
    int maxPrime = DSSoNguyen.SoNguyenToLonNhat();
    if (maxPrime != -1) cout << maxPrime;
    else cout << "Khong ton tai so nguyen to trong mang.";
    cout << "\nSap xep mang tang dan";
    DSSoNguyen.SapXepTangDan();
    cout << "\nMang sau khi sap xep tang dan la: ";
    DSSoNguyen.Xuat();
}
