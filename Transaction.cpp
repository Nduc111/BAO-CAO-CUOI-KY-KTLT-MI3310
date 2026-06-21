#include "Transaction.hpp"
#include "Utils.hpp"
#include <iostream>
using namespace std;

void addTransaction(DynamicArray<Transaction>& arr) {
    Transaction t;
    // Tự động tăng ID
    t.id = (arr.size() == 0) ? 1 : arr[arr.size() - 1].id + 1;

    int d, m, y;
    // Vòng lặp nhập ngày tháng cho đến khi hợp lệ
    while (true) {
        cout << "Nhap ngay, thang, nam (cach nhau bang dau cach): ";
        cin >> d >> m >> y;
        if (isValidDate(d, m, y)) {
            t.day = d; t.month = m; t.year = y; 
            break; 
        }
        cout << "Ngay thang khong hop le! Vui long nhap lai.\n";
    }

    cout << "Nhap danh muc: "; getline(cin >> ws, t.category);
    cout << "Nhap so tien: "; t.amount = getValidAmount(); 

    cout << "Thu nhap (1) hoac Chi tieu (0): "; cin >> t.isIncome;
    cout << "Nhap ghi chu: "; getline(cin >> ws, t.note);
    
    arr.push_back(t); // Thêm đối tượng vào mảng động
    cout << "Them giao dich thanh cong!\n";
}

void displayTransactions(const DynamicArray<Transaction>& arr) {
    if (arr.size() == 0) { cout << "Danh sach trong!\n"; return; }
    
    cout << "ID\tNgay\t\tDanh muc\tSo tien\t\tLoai\tGhi chu\n";
    // Duyệt toàn bộ mảng và in thông tin
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i].id << "\t" << arr[i].day << "/" << arr[i].month << "/" << arr[i].year 
        << "\t" << arr[i].category 
        << "\t\t" << (long long)arr[i].amount 
        << "\t\t" << (arr[i].isIncome ? "Thu" : "Chi") 
        << "\t" << arr[i].note << "\n";
    }
}

void editTransaction(DynamicArray<Transaction>& arr) {
    int targetId; cout << "Nhap ID can sua: "; cin >> targetId;
    int index = -1;
    
    // Tìm kiếm vị trí của giao dịch dựa trên ID
    for (int i = 0; i < arr.size(); i++) { 
        if (arr[i].id == targetId) { index = i; break; } 
    }
    if (index == -1) { cout << "Khong tim thay ID!\n"; return; } 
    
    int d, m, y;
    // Yêu cầu nhập lại ngày tháng
    while (true) {
        cout << "Nhap ngay, thang, nam moi: ";
        cin >> d >> m >> y;
        if (isValidDate(d, m, y)) {
            arr[index].day = d; arr[index].month = m; arr[index].year = y; 
            break;
        }
        cout << "Ngay thang khong hop le! Vui long nhap lai.\n";
    }
    
  
    cout << "Nhap danh muc moi: "; cin >> arr[index].category;
    cout << "Nhap so tien moi: "; arr[index].amount = getValidAmount();
    cout << "Thu nhap (1) hoac Chi tieu (0) moi: "; cin >> arr[index].isIncome;
    cout << "Nhap ghi chu moi: "; getline(cin >> ws, arr[index].note);
    cout << "Cap nhat thanh cong!\n";
}

void deleteTransaction(DynamicArray<Transaction>& arr) {
    int targetId; cout << "Nhap ID can xoa: "; cin >> targetId;
    int index = -1;
    
    // Tìm vị trí ID 
    for (int i = 0; i < arr.size(); i++) { 
        if (arr[i].id == targetId) { index = i; break; } 
    }
    if (index == -1) { cout << "Khong tim thay ID!\n"; return; }
    
    arr.erase(index); // Gọi hàm xóa phần tử của DynamicArray tại vị trí index
    cout << "Xoa giao dich thanh cong!\n";
}