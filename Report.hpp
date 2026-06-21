#ifndef Report_hpp
#define Report_hpp
#include "DynamicArray.hpp"
#include "model.hpp"

void MonthlyReport(const DynamicArray<Transaction>& txArr, int month, int year);
void BudgetAlert(const DynamicArray<Transaction>& txArr, const DynamicArray<Budget>& bgArr, int month, int year);

#endif
