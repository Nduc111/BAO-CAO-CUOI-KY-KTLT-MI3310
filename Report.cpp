#include "Report.hpp"
#include <iostream>
#include <iomanip> 
using namespace std;

void MonthlyReport(const DynamicArray<Transaction>& txArr, int month, int year)
{
    double totalIncome = 0;
    double totalExpense = 0;
    cout << "--- BAO CAO TAI CHINH THANG " << month << "/" << year << " ---\n";
    
    // Tính tổng thu và tổng chi trong tháng/năm được yêu cầu
    for(int i=0; i<txArr.size(); i++)
    {
        if(txArr[i].month == month && txArr[i].year == year)
        {
            if(txArr[i].isIncome) totalIncome += txArr[i].amount; // Cộng dồn thu nhập
            else totalExpense += txArr[i].amount; // Cộng dồn chi tiêu
        }
    }
    
    cout << "Tong thu nhap: " << (long long)totalIncome << "\n";
    cout << "Tong chi tieu: " << (long long)totalExpense << "\n";
    cout << "So du con lai: " << (long long)(totalIncome - totalExpense) << "\n"; // Tính số dư
    
    // Nếu có phát sinh chi tiêu, tiến hành thống kê theo danh mục
    if(totalExpense > 0)
    {
        cout << "\n--- TY LE CHI TIEU THEO DANH MUC ---\n";
        DynamicArray<string> cats; // Mảng lưu tên các danh mục duy nhất
        DynamicArray<double> amounts; // Mảng lưu tổng tiền tương ứng của từng danh mục
        
        for(int i=0; i<txArr.size(); i++) 
        {
            // Chỉ xét các khoản chi tiêu trong tháng/năm yêu cầu
            if(txArr[i].month == month && txArr[i].year == year && !txArr[i].isIncome)
            {
                int idx = -1;
                // Kiểm tra xem danh mục này đã có trong mảng cats chưa
                for(int j=0; j<cats.size(); j++)
                {
                    if(cats[j] == txArr[i].category) { idx = j; break; } 
                }
                
                if(idx != -1) {
                    amounts[idx] += txArr[i].amount; // Nếu đã có, cộng dồn tiền
                }
                else {
                    cats.push_back(txArr[i].category); // Nếu chưa có, thêm danh mục mới
                    amounts.push_back(txArr[i].amount); // Thêm khoản tiền đầu tiên
                }
            }
        }
        
        // In báo cáo tỷ lệ phần trăm
        for(int i=0; i<cats.size(); i++)
        {
            double pct = (amounts[i] / totalExpense) * 100; // Tính phần trăm chi tiêu của danh mục
            
            // Căn lề và định dạng số hiển thị 
            cout << "- " << left << setw(12) << cats[i] << ": "
                 << fixed << setprecision(0) << setw(9) << amounts[i] << " VND"
                 << " | " << setprecision(1) << setw(5) << pct << "% [";
            
            // Vẽ biểu đồ ASCII đơn giản (1 dấu # tương ứng 2%)
            int hashes = static_cast<int>(pct / 2);
            for(int h = 0; h < hashes; h++) cout << "#";
            cout << "]\n";
        }
    } 
    else 
    {
        cout << "\nThang nay khong co chi tieu nen khong co ty le danh muc.\n";
    }
}

void BudgetAlert(const DynamicArray<Transaction>& txArr, const DynamicArray<Budget>& bgArr, int month, int year)
{
    cout << "--- KIEM TRA HAN MUC NGAN SACH THANG " << month << "/" << year << " ---\n";
    
    if(bgArr.size() == 0)
    {
        cout << "Chua cau hinh ngan sach cho thang nay!\n";
        return;
    }
    
    // Duyệt qua từng ngân sách đã thiết lập
    for(int i=0; i<bgArr.size(); i++)
    {
        if(bgArr[i].month == month && bgArr[i].year == year)
        {
            double spent = 0;
            // Tính tổng số tiền đã chi cho danh mục tương ứng với ngân sách
            for(int j=0; j<txArr.size(); j++)
            {
                if(txArr[j].month == month && txArr[j].year == year && txArr[j].category == bgArr[i].category && !txArr[j].isIncome)
                {
                    spent += txArr[j].amount;
                }
            }
            
            cout << "Danh muc: " << bgArr[i].category << " | Han muc: " << fixed << setprecision(0) << bgArr[i].limitAmount << " | Da tieu: " << spent;
            
            // Cảnh báo nếu số tiền đã chi lớn hơn hạn mức
            if(spent > bgArr[i].limitAmount) 
                cout << " -> [CANH BAO] Da tieu vuot han muc " << (spent - bgArr[i].limitAmount) << "!\n";
            else 
                cout << " -> [An toan]\n";
        }
    }
}