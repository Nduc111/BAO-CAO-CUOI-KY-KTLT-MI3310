#include <cassert>
#include <iostream>
#include "../src/Utils.hpp"
#include "../src/DynamicArray.hpp"
#include "../src/model.hpp" 

using namespace std;

void test_isValidDate() {
    cout << "[TEST] Dang kiem tra logic isValidDate...\n";
    
    // Kiểm tra giới hạn năm (yêu cầu >= 2000)
    assert(isValidDate(1, 1, 2000) == true);     // Đúng biên dưới
    assert(isValidDate(31, 12, 1999) == false);  // Dưới biên

    // Kiểm tra giới hạn tháng (1 - 12)
    assert(isValidDate(15, 0, 2026) == false);   // Dưới biên tháng
    assert(isValidDate(15, 13, 2026) == false);  // Vượt biên tháng

    // Kiểm tra các tháng có số ngày cố định
    assert(isValidDate(31, 1, 2026) == true);    // Tháng 1 có 31 ngày
    assert(isValidDate(32, 1, 2026) == false);   
    assert(isValidDate(30, 4, 2026) == true);    // Tháng 4 có 30 ngày
    assert(isValidDate(31, 4, 2026) == false);   // Vượt biên tháng 4

    // Kiểm tra logic năm nhuận (Tháng 2) 
    assert(isValidDate(28, 2, 2023) == true);    // Năm thường
    assert(isValidDate(29, 2, 2023) == false);   // Năm thường không có ngày 29
    
    assert(isValidDate(29, 2, 2024) == true);    // Năm nhuận (chia hết cho 4)
    assert(isValidDate(30, 2, 2024) == false);   // Vượt biên năm nhuận
    
    assert(isValidDate(29, 2, 2100) == false);   // Năm chia hết cho 100 nhưng KHÔNG chia hết cho 400 (Không nhuận)
    
    cout << "  -> isValidDate: PASS (Khong phat hien loi logic)\n";
}

void test_DynamicArray() {
    cout << "[TEST] Dang kiem tra cau truc du lieu DynamicArray...\n";

    // Test các thao tác cơ bản với kiểu int
    DynamicArray<int> a;
    assert(a.size() == 0); 
    
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    assert(a.size() == 3);
    
    // Test thao tác xóa 
    a.erase(1);                     // Xóa phần tử ở giữa (số 20)
    assert(a.size() == 2);
    assert(a[0] == 10);
    assert(a[1] == 30);             // Số 30 phải được đẩy lên đúng vị trí
    
    a.erase(0);                     // Xóa phần tử ở đầu
    assert(a.size() == 1);
    assert(a[0] == 30);
    
    a.erase(5);                     // Thử xóa index ngoài biên (không được crash chương trình)
    assert(a.size() == 1);          // Kích thước vẫn phải giữ nguyên

    // Test tải bộ nhớ (Memory Load) với struct thực tế (Transaction)
    DynamicArray<Transaction> txArr;
    int loadLimit = 1000;           // Nạp 1000 giao dịch để kích hoạt nhân đôi capacity liên tục
    for(int i = 0; i < loadLimit; i++) {
        Transaction t;
        t.id = i;
        t.amount = i * 1500.0;
        txArr.push_back(t);
    }
    
    assert(txArr.size() == loadLimit);
    assert(txArr[500].id == 500);           // Truy xuất phần tử ở giữa an toàn
    assert(txArr[999].amount == 1498500.0); // Dữ liệu không bị mất mát khi chuyển vùng nhớ

    cout << "  -> DynamicArray: PASS (Quan ly bo nho dong on dinh)\n";
}

int main() {
    cout << "========================================\n";
    cout << "      BAT DAU CHAY UNIT TEST\n";
    cout << "========================================\n\n";
    
    test_isValidDate();
    cout << "----------------------------------------\n";
    test_DynamicArray();
    
    cout << "\n========================================\n";
    cout << ">>> TAT CA TEST DA PASS! <<<\n";
    cout << "========================================\n";
    
    return 0;
}
