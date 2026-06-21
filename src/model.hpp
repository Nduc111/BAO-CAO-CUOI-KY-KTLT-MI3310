#ifndef model_hpp
#define model_hpp
#include <string>
using namespace std;

struct Transaction
{
    int id;
    int day;
    int month;
    int year;
    string category;
    double amount;
    bool isIncome;
    string note;
};
struct Budget
{
    string category;
    double limitAmount;
    int month;
    int year;
};
#endif
