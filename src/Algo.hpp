#ifndef Algo_hpp
#define Algo_hpp

#include "DynamicArray.hpp"
#include <iostream>
#include <iomanip> 

template< typename T >
void bubbleSortDescending(DynamicArray<T>& arr)
{
    int n = arr.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j].amount < arr[j+1].amount)
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


template< typename T >
void linearSearchCategory(const DynamicArray<T>& arr, const std::string& key)
{
    int n = arr.size();
    bool found = false;

    std::cout << "ID\tNgay\t\tDanh muc\tSo tien\t\tLoai\tGhi chu\n";

    for(int i = 0; i < n; i++)
    {
        if(arr[i].category == key)
        {
            std::cout << arr[i].id << "\t" 
                      << arr[i].day << "/" << arr[i].month << "/" << arr[i].year << "\t" 
                      << arr[i].category << "\t\t" 
                      << std::fixed << std::setprecision(0) << arr[i].amount << "\t\t" 
                      << (arr[i].isIncome ? "Thu" : "Chi") << "\t" 
                      << arr[i].note << "\n";
            found = true;
        }
    }

    if(!found)
    {
        std::cout << "(Khong tim thay giao dich nao thuoc danh muc \"" << key << "\")\n";
    }
}

#endif
