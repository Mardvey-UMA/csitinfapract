#include <iostream>
#include <algorithm>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>
using namespace std;
ofstream fout("output.txt");
class Data{
private:
    int year, month, day;
public:
    bool setYear(int year){
        if (year > 0){
            this -> year = year;
            return true;
        }
        return false;
    }
    bool setDay(int day){
        int extra_month = day / 32;
        if (day > 0){
            if (day > 31){
                day = day % 31;
            }
            this -> day = day;
            setMonth(this->month + extra_month);
            return true;
        }
        return false;
    }
    bool setMonth(int month){
        int extra_year = month / 13;
        if (month > 0){
            if (month > 12){
                month = month % 12;
            }
            this -> month = month;
            setYear(this->year + extra_year);
            return true;
        }
        return false;
    }
    int getYear(){
        return year;
    }
    int getDay(){
        return day;
    }
    int getMonth(){
        return month;
    }
    void printData(string format = "mm/dd/yyyy"){
        string* months = new string[13];
        months[1] = "January";
        months[2] = "February";
        months[3] = "March";
        months[4] = "April";
        months[5] = "May";
        months[6] = "June";
        months[7] = "July";
        months[8] = "August";
        months[9] = "September";
        months[10] = "October";
        months[11] = "November";
        months[12] = "December";
        if (format == "text"){
            fout << day << " " << months[month] << " " << year << endl;
            delete[]months;
        }else if(format == "dd/mm/yyyy"){
            string dm = "", dd = "";
            if (day < 10) dd = "0";
            if (month < 10) dm = "0";
            fout << dd << day << "." << dm << month << "." << year << endl;
        }else if(format == "mm/dd/yyyy"){
            string dm = "", dd = "";
            if (day < 10) dd = "0";
            if (month < 10) dm = "0";
            fout << dm << month << "." <<  dd << day << "." << year << endl;
        }else if(format == "dd/mm/yy"){
            string dm = "", dd = "";
            if (day < 10) dd = "0";
            if (month < 10) dm = "0";
            fout << dd << day << "." << dm << month << "." << year % 100 << endl;
        }

    }
    Data getNextDay() const{
        Data newData = *this;
        newData.setDay(this->day + 1); 
        return newData;
    }
    Data getPreviousDay() const{
        Data newData = *this;
        newData.setDay(this->day - 1); 
        return newData;
    }
    Data changeYear(int y) const{
        Data newData = *this;
        newData.setYear(this->year + y);
        return newData;
    }
    Data changeMonth(int m) const{
        Data newData = *this;
        newData.setMonth(this->month + m);
        return newData;
    }
    Data changeDay(int d) const{
        Data newData = *this;
        newData.setDay(this->day + d);
        return newData;
    }
    bool operator < (const Data& other){
        if (year < other.year){
            return true;
        }else if (month < other.month){
            return true;
        }else if (day < other.day){
            return true;
        }
        return false;
    }
    bool operator == (const Data& other){
        return ((day == other.day) && (month == other.month) && (day == other.day));
    }

    static int* Data_diff(Data& d1, Data& d2){
        int* diff = new int[3];
        int d = abs(d2.day - d1.day) + abs(d2.month - d1.month) * 31 + abs(d2.year - d1.year)*12*31;
        diff[2] = d / 365;
        d = d % 365;
        diff[1] = d / 31;
        diff[0] = d % 31;
        fout << "Elapsed time\n";
        fout << "Years: " << diff[2] << endl;
        fout << "Months: " << diff[1] << endl;
        fout << "Days: " << diff[0] << endl;
        return diff;
    }
    Data() : day(1), month(1), year(1970) {};
    Data (int day, int month, int year){
        setDay(day);
        setMonth(month); 
        setYear(year);
    }

};


int main(){
    setlocale(LC_ALL, "Russian");
    Data d1(13, 4, 2023);
    Data d2(9, 3, 2021);
    Data d3(14, 1, 1988);
    Data d4(20, 4, 2023);
    fout << "Прошло вот столько времени между\n";
    d1.printData("text");
    d2.printData("text");
    Data::Data_diff(d1, d2);
    fout << "Следующий день после\n";
    d1.printData("text");
    auto dt = d1.getNextDay();
    dt.printData("text");
    fout << "Предыдущий день перед\n";
    d1.printData("text");
    dt = d1.getPreviousDay();
    dt.printData("text");
    fout << "Прибавим к дате 3 дня, получаем\n";
    dt = d1.changeDay(3);
    dt.printData("text");
    fout << "Прибавим 10 месяца\n";
    dt = d1.changeMonth(10);
    dt.printData("text");
    fout << "Отнимем 5 лет\n";
    dt = d1.changeYear(-5);
    dt.printData("text");
//_getch();
}
