#ifndef Transaction_hpp
#define Transaction_hpp
#include "DynamicArray.hpp"
#include "model.hpp"

void addTransaction(DynamicArray<Transaction>& arr);
void displayTransactions(const DynamicArray<Transaction>& arr);
void editTransaction(DynamicArray<Transaction>& arr);
void deleteTransaction(DynamicArray<Transaction>& arr);

#endif
