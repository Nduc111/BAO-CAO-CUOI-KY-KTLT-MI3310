#include "Utils.hpp"
#include <iostream>
using namespace std;

bool isValidDate(int day, int month, int year) {
    // Kiểm tra các giá trị cơ bản 
    if (year < 2000 || month < 1 || month > 12 || day < 1) return false;
    
    // Mảng chứa số ngày tối đa của 12 tháng (index 0 bỏ trống để dễ truy cập)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Kiểm tra năm nhuận: chia hết cho 4 nhưng không chia hết cho 100, hoặc chia hết cho 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[2] = 29; 
    }
    
    return day <= daysInMonth[month]; 
}

double getValidAmount() {
    double amount;
    // Vòng lặp yêu cầu nhập liên tục cho đến khi đúng định dạng
    while (true) {
        cin >> amount;
        // Kiểm tra xem luồng nhập có bị lỗi không
        if (cin.fail() || amount <= 0) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "So tien khong hop le! Vui long nhap lai so duong: ";
        } else {
            cin.ignore(1000, '\n'); 
            return amount; 
        }
    }
}

int getValidMonth() {
    int m;
    // Vòng lặp yêu cầu nhập lại nếu sai định dạng tháng
    while (true) {
        cin >> m;
        if (cin.fail() || m < 1 || m > 12) {
            cin.clear(); 
            
            char c;
            while (cin.get(c)) { 
                if (c == '\n') break; // Gặp enter thì dừng xóa
            }
            cout << "Loi: Thang phai tu 1 den 12! Vui long nhap lai: ";
        } else {
            char c;
            while (cin.get(c)) { 
                if (c == '\n') break; 
            }
            return m;
        }
    }
}
