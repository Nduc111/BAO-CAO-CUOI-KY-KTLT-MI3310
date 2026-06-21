#ifndef Storage_hpp
#define Storage_hpp
#include "DynamicArray.hpp"
#include "model.hpp"
using namespace std;

void saveTransactions(const DynamicArray<Transaction>& arr,const string& filename);
void loadTransactions(DynamicArray<Transaction>& arr,const string& filename);
void saveBudgets(const DynamicArray<Budget>& arr,const string& filename);
void loadBudgets(DynamicArray<Budget>& arr,const string& filename);

#endif
