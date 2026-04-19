#include "cArray.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hàm tạo mảng ngẫu nhiên
void cArray::MangNgauNhien(const int& n) {
    iSoPhanTu = n;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        aDSSoNguyen.push_back(rand() % 100); // tạo số ngẫu nhiên từ 0 đến 99
    }
}

// Xuất các phần tử mảng
void cArray::Xuat() {
    for (int i = 0; i < iSoPhanTu; i++) {
        cout << aDSSoNguyen[i] << ' ';
    }
}

// Trả về số lần xuất hiện giá trị x trong mảng
int cArray::SoLanXuatHien(const int& x) {
    int count = 0;
    for (int i = 0; i < iSoPhanTu; i++) {
        if (aDSSoNguyen[i] == x) count++;
    }
    return count;
}

// Trả về true nếu mảng tăng dần và ngược lại
bool cArray::KiemTraTangDan() {
    for (int i = 0; i < iSoPhanTu - 1; i++) {
        if (aDSSoNguyen[i] > aDSSoNguyen[i + 1]) return false;
    }
    return true;
}

// Trả về phần tử lẻ nhỏ nhất trong mảng
int cArray::PhanTuLeNhoNhat() {
    int minEven = 100;
    for (int i = 0; i < iSoPhanTu; i++) {
        if (aDSSoNguyen[i] < minEven && aDSSoNguyen[i] % 2 == 1) minEven = aDSSoNguyen[i];
    }
    if (minEven != 100) return minEven;
    return -1;
}

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(const int& x) {
    if (x < 2) return false;
    if (x == 2) return true;
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

// Trả về số nguyên tố lớn nhất trong mảng
int cArray::SoNguyenToLonNhat() {
    int maxPrime = -1;
    for (int i = 0; i < iSoPhanTu; i++) {
        if (aDSSoNguyen[i] > maxPrime && laSoNguyenTo(aDSSoNguyen[i])) maxPrime = aDSSoNguyen[i];
    }
    return maxPrime;
}

// Sắp xếp theo giải thuật HeapSort
void Heapify(vector<int>& array, int count, int position) {
    int max_index = position;
    if (2 * position + 1 < count && array[2 * position + 1] > array[max_index]) max_index = 2 * position + 1;
    if (2 * position + 2 < count && array[2 * position + 2] > array[max_index]) max_index = 2 * position + 2;
    if (max_index != position) {
        swap(array[max_index], array[position]);
        Heapify(array, count, max_index);
    }
}
void HeapSort(vector<int>& array, int count) {
    for (int i = count / 2 - 1; i >= 0; i--) {
        Heapify(array, count, i);
    }
    for (int i = count - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        Heapify(array, i, 0);
    }
}

// Hàm sắp xếp mảng theo HeapSort
void cArray::SapXepTangDan() {
    HeapSort(aDSSoNguyen, aDSSoNguyen.size());
}