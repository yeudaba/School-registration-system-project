//
// Created by יהודה on 04/09/2023.
//

#include "Worker.h"

#ifndef UNTITLED57_SECRETARY_H
#define UNTITLED57_SECRETARY_H

class Secretary: public Worker{
private:
    float Secretary_hours;

public:
    Secretary(char *name1= nullptr,long ID1=0,float num1=0,float Secretary_hours1=0): Worker(name1,ID1,num1),Secretary_hours(Secretary_hours1){

    }
    float get_salary()const{
        float num;
        num=5000+(200*seniority)+(60*Secretary_hours);
        return num;

    }
    void print()const{
        cout<<"name: ";
        cout<<getName()<<endl;
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"seniority: ";
        cout<<seniority<<endl;
        cout<<"salary: "<<get_salary()<<endl;
        cout<<endl;
    }
    ~Secretary(){
    }

};


#endif //UNTITLED57_SECRETARY_H
