# Ứng Dụng Quản Lý Tài Chính Cá Nhân (Personal Finance Manager)

> Bài tập cá nhân môn **Kỹ Thuật Lập Trình**: Xây dựng ứng dụng quản lý thu/chi và ngân sách bằng C++.

![Language](https://img.shields.io/badge/Language-C%2B%2B11-blue)
![Build](https://img.shields.io/badge/Build-g%2B%2B-green)
![Tests](https://img.shields.io/badge/Tests-assert-orange)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)

Ứng dụng chạy trên giao diện dòng lệnh (CLI), cho phép ghi chép các khoản thu/chi hằng ngày theo danh mục, thiết lập hạn mức ngân sách theo tháng, xem báo cáo thống kê dạng biểu đồ text và cảnh báo khi vượt ngân sách. Dữ liệu được lưu vào file `.txt` và tự động nạp lại ở lần chạy sau.

---

## Tính năng

- **Ghi chép giao dịch:**
  - Thêm, sửa, xóa các khoản **Thu** và **Chi**.
  - Mỗi giao dịch gồm: ngày/tháng/năm, danh mục, số tiền, loại (thu/chi) và ghi chú.
- **Quản lý ngân sách:** Thêm và sửa hạn mức chi tiêu cho từng danh mục theo tháng/năm.
- **Thống kê & báo cáo:**
  - Tổng hợp thu/chi và số dư theo tháng/năm.
  - Hiển thị tỷ lệ chi tiêu theo từng danh mục kèm biểu đồ ASCII trực quan.
  - Cảnh báo khi số tiền đã chi vượt hạn mức ngân sách đã thiết lập.
- **Sắp xếp & tìm kiếm:**
  - Sắp xếp danh sách giao dịch giảm dần theo số tiền (bubble sort).
  - Tìm kiếm/lọc giao dịch theo tên danh mục (linear search).
- **Lưu trữ dữ liệu:** Tự động đọc dữ liệu khi khởi động và ghi dữ liệu xuống file khi lưu/thoát chương trình.

---

## Thiết kế / Kiến trúc

Chương trình được tổ chức theo hướng **module hóa**, tách biệt dữ liệu, logic xử lý và giao diện:

- **Lớp dữ liệu (Model):** File `model.hpp` định nghĩa struct `Transaction` (Giao dịch) và `Budget` (Ngân sách) — đại diện cho các thực thể trong thực tế.
- **Cấu trúc dữ liệu tự cài đặt:** File `DynamicArray.hpp` cung cấp mảng động dạng template (`DynamicArray<T>`), tự quản lý cấp phát/giải phóng bộ nhớ, dùng để thay thế cho `std::vector`.
- **Logic xử lý nghiệp vụ:**
  - `Transaction.hpp/.cpp`: thêm, hiển thị, sửa, xóa giao dịch.
  - `Budget.hpp/.cpp`: thêm, hiển thị, sửa hạn mức ngân sách.
  - `Report.hpp/.cpp`: tính toán và in báo cáo tài chính theo tháng, kiểm tra cảnh báo vượt ngân sách.
- **Thuật toán:** File `Algo.hpp` chứa các hàm template dùng chung: `bubbleSortDescending` (sắp xếp giảm dần theo số tiền) và `linearSearchCategory` (tìm kiếm tuyến tính theo danh mục).
- **Tiện ích (Utils):** File `Utils.hpp/.cpp` chứa các hàm hỗ trợ dùng chung như kiểm tra ngày hợp lệ (`isValidDate`, có xét năm nhuận) và đọc số tiền hợp lệ từ người dùng (`getValidAmount`).
- **Lưu trữ (Storage):** File `Storage.hpp/.cpp` đảm nhiệm việc đọc/ghi danh sách giao dịch và ngân sách vào file `.txt` theo định dạng phân tách bằng dấu phẩy (CSV-like).
- **Giao diện dòng lệnh (CLI):** Hàm `main()` trong `main.cpp` hiển thị menu, điều hướng lựa chọn của người dùng và gọi đến các hàm xử lý tương ứng.

---

## Cấu trúc thư mục

```text
├──data/
│   ├── transactions.txt           # Dữ liệu giao dịch đã lưu
│   └──  budgets.txt                 # Dữ liệu ngân sách đã lưu
├── src/
│   ├── model.hpp                # Định nghĩa struct Transaction, Budget
│   ├── DynamicArray.hpp          # Mảng động tự cài đặt bằng template (Generic Array)
│   ├──Algo.hpp                  # Thuật toán sắp xếp (bubble sort) và tìm kiếm (linear search)
│   ├── Utils.hpp / Utils.cpp     # Hàm tiện ích: kiểm tra ngày hợp lệ, đọc số tiền hợp lệ
│   ├── Transaction.hpp / .cpp    # Xử lý logic Giao dịch (thêm/sửa/xóa/hiển thị)
│   ├── Budget.hpp / .cpp         # Xử lý logic Ngân sách (thêm/sửa/hiển thị)
│   ├── Report.hpp / .cpp         # Tạo báo cáo tài chính theo tháng, cảnh báo vượt ngân sách
│   ├── Storage.hpp / .cpp        # Đọc/ghi dữ liệu giao dịch và ngân sách vào file text
│   ├── main.cpp                  # Điểm đầu vào (Entry point), chứa menu CLI
├──tests/
│   └──test.cpp                   # Unit test (dùng assert) cho Utils, DynamicArray,...
└── README.md                   # Tài liệu mô tả dự án
```

---

## Yêu cầu hệ thống

Chương trình yêu cầu trình biên dịch C++ hỗ trợ tiêu chuẩn **C++11 trở lên** (như MinGW GCC, Clang hoặc MSVC).

---

## Biên dịch và Chạy

### Bước 1: Sao chép dự án (Clone Repository)

Mở Terminal / Command Prompt và chạy lệnh:

```bash
git clone https://github.com/Nduc111/BAO-CAO-CUOI-KY-KTLT-MI3310.git
cd BAO-CAO-CUOI-KY-KTLT-MI3310
```

### Bước 2: Biên dịch chương trình chính (App)

```bash
g++ -std=c++11 main.cpp Transaction.cpp Budget.cpp Report.cpp Storage.cpp Utils.cpp -o chuongtrinh
```

### Bước 3: Biên dịch file Unit Test

```bash
g++ -std=c++11 test.cpp Utils.cpp -o test
```

### Bước 4: Chạy chương trình (Run)

**Chạy ứng dụng chính:**

```bash
./chuongtrinh
```

**Chạy Test:**

```bash
./test
```

> Trên Windows, file thực thi sẽ có đuôi `.exe` (ví dụ: `chuongtrinh.exe`, `test.exe`).

---

## Hướng dẫn sử dụng nhanh

Sau khi chạy chương trình, menu chính sẽ hiển thị các lựa chọn:

```
1. Them giao dich (Thu/Chi)
2. Hien thi danh sach giao dich
3. Sua giao dich theo ID
4. Xoa giao dich theo ID
5. Sap xep giao dich giam dan theo so tien
6. Them han muc ngan sach
7. Hien thi danh sach ngan sach
8. Sua han muc ngan sach
9. Xem bao cao tai chinh theo Thang/Nam
10. Kiem tra canh bao vuot ngan sach
11. Luu du lieu xuong file text
12. Tim/Loc giao dich theo danh muc
0. Thoat chuong trinh
```

Nhập số tương ứng và làm theo hướng dẫn nhập liệu trên màn hình.

---

## Ghi chú

- Đảm bảo các file `transactions.txt` và `budgets.txt` nằm cùng cấp với file thực thi để chương trình đọc/ghi dữ liệu đúng.
- Trong lần chạy đầu tiên (chưa có dữ liệu), chương trình vẫn khởi động bình thường và sẽ tạo file dữ liệu khi lưu.
- Chương trình tự động lưu dữ liệu khi chọn mục **11** hoặc khi thoát bằng mục **0**.
