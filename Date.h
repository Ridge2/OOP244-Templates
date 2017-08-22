/**********************************************************
// Milestone 1
// Date.h
// Version 1.0
// 2017/07/05
// Revision History
///////////////////////////////////////////////////////////
// Name: Ridge Frnancis  Date: 23/06/2017 
// 
///////////////////////////////////////////////////////////
**********************************************************/
#ifndef SICT_DATE_H_
#define SICT_DATE_H_
#include <iostream>
//Sict namepace containing all the the object variables
namespace sict{
    #define NO_ERROR 0 
    #define CIN_FAILED 1 
    #define YEAR_ERROR 2
    #define MON_ERROR 3 
    #define DAY_ERROR 4

    class Date {
        int year_;
        int mon_;
        int day_;
        int readErrorCode_;
        int value() const;
        void errCode(int);
    public:
        Date();
        Date(int, int , int);
        int mdays()const;
        bool operator==(const Date& D)const;
        bool operator!=(const Date& D)const;
        bool operator<(const Date& D)const;
        bool operator>(const Date& D)const;
        bool operator<=(const Date& D)const;
        bool operator>=(const Date& D)const;    
        ~Date();
        int errCode() const;   
        bool bad() const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
    };
    std::istream& operator>>(std::istream& istr, Date& s);
    std::ostream& operator<<(std::ostream& ostr, const Date& s);
}
#endif
