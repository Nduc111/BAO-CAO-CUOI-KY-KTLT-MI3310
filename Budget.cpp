#include "Budget.hpp"
#include "Utils.hpp"
#include <iostream>
using namespace std;

void addBudget(DynamicArray<Budget>& arr)
{
    Budget b;
    // Nhập thông tin ngân sách mới
    cout << "Nhap danh muc: "; getline(cin >> ws, b.category);
    cout << "Nhap han muc tien: "; b.limitAmount = getValidAmount(); // Dùng hàm tiện ích để kiểm tra đầu vào số tiền
    cout << "Nhap thang: "; cin >> b.month;
    cout << "Nhap nam: "; cin >> b.year;
    
    arr.push_back(b); 
    cout << "Them han muc ngan sach thanh cong!\n";
}

void displayBudgets(const DynamicArray<Budget>& arr)
{
    if(arr.size() == 0)
    {
        cout << "Danh sach ngan sach trong!\n";
        return;
    }
    
    cout << "Danh muc\tHan muc\t\tThang/Nam\n";
    // In thông tin ngân sách
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i].category << "\t\t" 
             << (long long)arr[i].limitAmount << "\t\t" 
             << arr[i].month << "/" << arr[i].year << "\n";
    }
}

void editBudget(DynamicArray<Budget>& arr)
{
    string cat;
    int m, y;
    
    cout << "Nhap danh muc can sua: "; 
    getline(cin >> ws, cat); 
    
    cout << "Nhap thang: "; 
    m = getValidAmount(); 
    
    cout << "Nhap nam: "; 
    y = getValidAmount();
    
    int index = -1;
    // Tìm kiếm ngân sách 
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i].category == cat && arr[i].month == m && arr[i].year == y)
        {
            index = i; 
            break; 
        }
    }
    
    if(index == -1)
    {
        cout << "Khong tim thay han muc ngan sach phu hop!\n";
        return;
    }
    
    // Yêu cầu nhập hạn mức mới cho ngân sách
    cout << "Nhap han muc tien moi: "; 
    arr[index].limitAmount = getValidAmount(); 
    cout << "Cap nhat ngan sach thanh cong!\n";
}