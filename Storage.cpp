#include "Storage.hpp"
#include <fstream>
#include <sstream>
using namespace std;

void saveTransactions(const DynamicArray<Transaction>& arr, const string& filename)
{
    ofstream file(filename); // Mở file ở chế độ ghi
    if(!file.is_open()) return; 
    
    // Duyệt qua toàn bộ danh sách giao dịch 
    for(int i=0; i<arr.size(); i++)
    {
       
        file << arr[i].id << "," 
        << arr[i].day << "," 
        << arr[i].month << "," 
        << arr[i].year << "," 
        << arr[i].category << "," 
        << (long long)arr[i].amount << "," 
        << arr[i].isIncome << "," 
        << arr[i].note << "\n";
    }
    file.close(); // Đóng file sau khi ghi xong
}

void loadTransactions(DynamicArray<Transaction>& arr, const string& filename)
{
    ifstream file(filename); // Mở file ở chế độ đọc
    if(!file.is_open()) return; 
    
    string line;
    // Đọc lần lượt từng dòng cho đến hết file
    while(getline(file, line))
    {
        if(line.empty()) continue; // Bỏ qua các dòng trống
        
        stringstream ss(line); // Dùng stringstream để cắt chuỗi
        string token;
        Transaction t;
        
        // Đọc từng phần tử phân cách bằng dấu phẩy và chuyển đổi kiểu dữ liệu tương ứng
        getline(ss, token, ','); t.id = stoi(token);
        getline(ss, token, ','); t.day = stoi(token);
        getline(ss, token, ','); t.month = stoi(token);
        getline(ss, token, ','); t.year = stoi(token);
        getline(ss, t.category, ',');
        getline(ss, token, ','); t.amount = stod(token);
        getline(ss, token, ','); t.isIncome = (token == "1"); // Chuyển chuỗi "1" thành boolean true
        getline(ss, t.note); // Đọc phần ghi chú còn lại
        
        arr.push_back(t); // Thêm giao dịch vừa đọc vào mảng
    }
    file.close();
}

void saveBudgets(const DynamicArray<Budget>& arr, const string& filename)
{
    ofstream file(filename); // Mở file ghi ngân sách
    if(!file.is_open()) return;
    
    for(int i=0; i<arr.size(); i++)
    {
        // Ghi dữ liệu ngân sách
        file << arr[i].category << "," 
        << (long long)arr[i].limitAmount << ","
        << arr[i].month << "," 
        << arr[i].year << "\n";
    }
    file.close();
}

void loadBudgets(DynamicArray<Budget>& arr, const string& filename)
{
    ifstream file(filename); // Mở file đọc ngân sách
    if(!file.is_open()) return;
    
    string line;
    while(getline(file, line))
    {
        if(line.empty()) continue;
        
        stringstream ss(line);
        string token;
        Budget b;
        
        
        getline(ss, b.category, ',');
        getline(ss, token, ','); b.limitAmount = stod(token);
        getline(ss, token, ','); b.month = stoi(token);
        getline(ss, token, ','); b.year = stoi(token);
        
        arr.push_back(b);
    }
    file.close();
}