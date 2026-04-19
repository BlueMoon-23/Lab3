#include <iostream>
#include "cDaThuc.h"
using namespace std;

int main()
{
    cDaThuc DaThucA, DaThucB;
    cout << "Nhap da thuc A:\n";
    DaThucA.Nhap();
    cout << "Nhap da thuc B:\n";
    DaThucB.Nhap();
    cout << "Da thuc A: ";
    DaThucA.Xuat();
    cout << "\nDa thuc B: ";
    DaThucB.Xuat();
    double x;
    cout << "\nNhap gia tri x: ";
    cin >> x;
    cout << "Gia tri cua da thuc A tai x: ";
    cout << DaThucA.TinhGiaTri(x);
    cout << "\nGia tri cua da thuc B tai x: ";
    cout << DaThucB.TinhGiaTri(x);
    cout << "\nTong cua da thuc A va da thuc B la: ";
    cDaThuc DaThucC = DaThucA.Cong(DaThucB);
    DaThucC.Xuat();
    cout << "\nHieu cua da thuc A va da thuc B la: ";
    cDaThuc DaThucD = DaThucA.Tru(DaThucB);
    DaThucD.Xuat();
}
