#include <iostream>
#include "DynamicArray.hpp"
#include "model.hpp"
#include "Storage.hpp"
#include "Transaction.hpp"
#include "Budget.hpp"
#include "Report.hpp"
#include "Algo.hpp"
using namespace std;
void printMenu()
{
    cout << "\n================ MENU QUAN LY TAI CHINH ================\n";
    cout << "1. Them giao dich (Thu/Chi)\n";
    cout << "2. Hien thi danh sach giao dich\n";
    cout << "3. Sua giao dich theo ID\n";
    cout << "4. Xoa giao dich theo ID\n";
    cout << "5. Sap xep giao dich giam dan theo so tien\n";
    cout << "6. Them han muc ngan sach\n";
    cout << "7. Hien thi danh sach ngan sach\n";
    cout << "8. Sua han muc ngan sach\n";
    cout << "9. Xem bao cao tai chinh theo Thang/Nam\n";
    cout << "10. Kiem tra canh bao vuot ngan sach\n";
    cout << "11. Luu du lieu xuong file text\n";
    cout << "12. Tim/Loc giao dich theo danh muc\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "========================================================\n";
    cout << "Nhap lua chon cua ban: ";
}

int main()
{
    DynamicArray<Transaction> txList;
    DynamicArray<Budget> bgList;
    
    loadTransactions(txList, "transactions.txt");
    loadBudgets(bgList, "budgets.txt");
    
    int choice;
    while(true)
    {
        printMenu();
         cin >> choice;
        if(choice == 0)
        {
            saveTransactions(txList, "transactions.txt");
            saveBudgets(bgList, "budgets.txt");
            cout << "Da tu dong luu du lieu. Tam biet!\n";
            break;
        }
        switch(choice)
        {
            case 1: addTransaction(txList); break;
            case 2: displayTransactions(txList); break;
            case 3: editTransaction(txList); break;
            case 4: deleteTransaction(txList); break;
            case 5: bubbleSortDescending(txList);  cout << "Da sap xep xong! Bam phim 2 de xem ket qua.\n"; break;
            case 6: addBudget(bgList); break;
            case 7: displayBudgets(bgList); break;
            case 8: editBudget(bgList); break;
            case 9: {
                int m, y;
                cout << "Nhap thang can xem: ";  cin >> m;
                cout << "Nhap nam can xem: ";  cin >> y;
                MonthlyReport(txList, m, y);
                break;
            }
            case 10: {
                int m, y;
                cout << "Nhap thang can kiem tra: ";  cin >> m;
                cout << "Nhap nam can kiem tra: ";  cin >> y;
                BudgetAlert(txList, bgList, m, y);
                break;
            }
            case 11: {
                saveTransactions(txList, "transactions.txt");
                saveBudgets(bgList, "budgets.txt");
                cout << "Da luu du lieu thanh cong!\n";
                break;
            }
            case 12: {
                 string targetCat;
                 cout << "Nhap ten danh muc muon tim kiem (vi du: anuong): ";
                 getline( cin >>  ws, targetCat);
                 cout << "\n--- KET QUA TIM KIEM DANH MUC: " << targetCat << " ---\n";
                linearSearchCategory(txList, targetCat); 
                break;
            }
            default:  cout << "Lua chon khong hop le! Vui long nhap lai.\n"; break;
        }
    }
    return 0;
}
