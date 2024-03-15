//
// Created by יהודה on 04/09/2023.
//

#include "Teacher.h"

#ifndef UNTITLED57_TEMP_H
#define UNTITLED57_TEMP_H


class Temp: public Teacher{
private:
    float weekly_hours;

public:
    Temp(float weekly=0,char **name= nullptr,int P=0,long ID=0,float num1=0,char *name1= nullptr): Teacher(name,P,ID,num1,name1),weekly_hours(weekly){

    }
    float get_salary()const{
        float money1;
        if(seniority>5 && weekly_hours>10){
            money1=(weekly_hours*300)+700;
            return money1;
        }
        else{
            money1=weekly_hours*300;
            return money1;
        }
    }
    void print()const{
        cout<<"name: ";
        cout<<getName();
        cout<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Seniority: "<<seniority<<endl;
        cout<<"Amount of weekly hours he teaches: "<<weekly_hours<<endl;
        cout<<"salary: "<<this->get_salary()<<endl;
        cout<<endl;
    }
    ~Temp(){

    }


};



#endif //UNTITLED57_TEMP_H
