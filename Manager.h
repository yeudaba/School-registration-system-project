//
// Created by יהודה on 04/09/2023.
//

#include "Worker.h"

#ifndef UNTITLED57_MANAGER_H
#define UNTITLED57_MANAGER_H


class Manager: public Worker{

public:
    Manager(float m=0,char *name1= nullptr,long ID1=0,float num1=0): Worker(name1,ID1,num1){

    }
    float get_salary()const{
        float num;
        num=10000+(seniority*800);
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
    ~Manager(){

    }

    char *getName()const{
        return name;
    }

};



#endif //UNTITLED57_MANAGER_H
