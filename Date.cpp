#include <iostream>
#include <fstream>
#include "general.h"
#include "Date.h"
using namespace std;
namespace sict{
    //Default constructor
    //
    Date::Date() {
        year_ = 0;
        mon_ = 0;
        day_ = 0;
        readErrorCode_ = NO_ERROR;
    }
    //Default deconstructor
    //
    Date::~Date(){
    }

    Date::Date(int year, int mon, int day) {
        year_ = year;
        mon_ = mon;
        day_ = day;
        readErrorCode_ = NO_ERROR; 
    }
    //Write function writes data to the output stream
    //
    std::ostream& Date::write(ostream& ostr) const {
        ostr << year_ << "/"; 
        ostr.setf(ios::fixed);
        ostr.fill('0');
        ostr.width(2);
        ostr << mon_ << "/";
        ostr.width(2);
        ostr << day_;
        return ostr;
    }
    //Read function validates the data and sets values according
    //
    std::istream& Date::read(istream& istr) {
 	    istr >> year_;
		if (istr.get() != '/') {
			readErrorCode_ = CIN_FAILED;
			return istr;
		}
		istr >> mon_;
		if (istr.get() != '/') {
			readErrorCode_ = CIN_FAILED;
			return istr;
		}
		istr >> day_;
		if (year_ < MIN_YEAR || year_ > MAX_YEAR){
			readErrorCode_ = YEAR_ERROR;
		}
		else if (mon_ < 1 || mon_ > 12){
			readErrorCode_ = MON_ERROR;
		}
		else if (day_ < 1 || day_ > mdays()){
			readErrorCode_ = DAY_ERROR;
		}
		else {
			readErrorCode_ = NO_ERROR;
		}
		return istr;
    }
    //value function returns the month being operated on
    //
    int Date::value()const {
        return year_ * 372 + mon_ * 31 + day_;
    }
    //The mdays() function determines the day day of the month based on if there is a leap year or not
    //
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
        mon--;
        return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
    }
    //== operator overload compares two objects
    //
    bool Date::operator==(const Date& D) const {
        bool same = this->value() == D.value() ? true : false;  
        return same;
    }
    //!= operator overload compares two objects
    //
    bool Date::operator!=(const Date& D) const {
        bool same = this->value() != D.value() ? true : false;
        return same;
    }
    // < operator overload compares two objects
    //
    bool Date::operator<(const Date& D) const {
        bool same = this->value() < D.value() ? true : false;
        return same;
    }
    // > operator overload compares two objects
    //
    bool Date::operator>(const Date& D) const {
        bool same = this->value() > D.value() ? true : false;
        return same;
    }
    //>= operator overload compares two objects
    //
    bool Date::operator>=(const Date& D) const {
        bool same = this->value() >= D.value() ? true : false;
        return same;
    }
    //<= operator overload compares two objects
    //
    bool Date::operator<=(const Date& D) const {
        bool same = this->value() >= D.value() ? true : false;
        return same;
    }
    //Sets the readErrorCode to the errorCode value
    //
    void Date::errCode(int errorCode){
        readErrorCode_ = errorCode;
    }
    //Query and return the errorCode
    //
    int Date::errCode() const {
        return readErrorCode_;
    }
    //bad function returns true if the readErrorCode is != 0 false otherwise
    //
    bool Date::bad()const {
        bool valid = false;
        if(readErrorCode_ != 0) {
            valid = true;
        }
        return valid;
    }
    // >> overload operator
    //
    std::istream& operator>>(istream& istr, Date& s) {
        s.read(istr);
        return istr;
    }
    // << overload operator
    //
    std::ostream& operator<<(ostream& ostr, const Date& s) { 
        s.write(ostr);
        return ostr;  
    }
}   


