#ifndef Budget_hpp
#define Budget_hpp
#include "DynamicArray.hpp"
#include "model.hpp"

void addBudget(DynamicArray<Budget>& arr);
void displayBudgets(const DynamicArray<Budget>& arr);
void editBudget(DynamicArray<Budget>& arr);

#endif