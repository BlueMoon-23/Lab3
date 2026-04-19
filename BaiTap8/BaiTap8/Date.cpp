#include "Date.h"
#include <iostream>
using namespace std;

// Phương thức thiết lập mặc định
Date::Date() {
	Ngay = 0;
	Thang = 0;
	Nam = 0;
}
// Phương thức thiết lập có truyền tham số
Date::Date(int day, int month, int year) {
	Ngay = day;
	Thang = month;
	Nam = year;
}
// Phương thức thiết lập sao chép
Date::Date(const Date& ngay) {
	Ngay = ngay.Ngay;
	Thang = ngay.Thang;
	Nam = ngay.Nam;
}
// Hàm nhập ngày
void Date::NhapDate() {
	do {
		cout << "Nhap ngay (0 < ngay < 32): ";
		cin >> Ngay;
	} while (Ngay < 1 && Ngay > 31);
	do {
		cout << "Nhap thang (0 < thang < 13): ";
		cin >> Thang;
	} while (Thang < 1 && Thang < 12);
	do {
		cout << "Nhap nam (nam > 0): ";
		cin >> Nam;
	} while (Nam < 0);
}
// Hàm kiểm tra ngày có hợp lệ hay không
bool Date::HopLe() {
	switch (Thang) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		return (Ngay <= 31);
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		return (Ngay <= 30);
	}
	case 2:
	{
		if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0) return (Ngay <= 29);
		return (Ngay <= 28);
	}
	}
}
// Hàm xuất ngày
void Date::XuatDate() {
	if (HopLe()) {
		cout << Ngay << '/' << Thang << '/' << Nam;
	}
	else {
		cout << "Ngay sinh khong hop le.";
	}
}
// Hàm kiểm tra ngày sinh này có lớn tuổi hơn ngày sinh khác không
bool Date::LonTuoiHon(const Date& other) {
	if (Nam == other.Nam) {
		if (Thang == other.Thang) {
			return (Ngay < other.Ngay);
		}
		return (Thang < other.Thang);
	}
	return (Nam < other.Nam);
}