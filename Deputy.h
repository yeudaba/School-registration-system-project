//
// Created by יהודה on 04/09/2023.
//

#include "Tutor.h"

#ifndef UNTITLED57_DEPUTY_H
#define UNTITLED57_DEPUTY_H


class Deputy :public Tutor{

public:
    Deputy(char *c= nullptr,char **name= nullptr,int P=0,long ID=0,float num1=0,char *name1= nullptr): Tutor(c,name,P,ID,num1,name1){

    }
    void print()const{
        cout<<"name: ";
        cout<<getName();
        cout<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Seniority: "<<seniority<<endl;
        cout<<"Educator in the classroom: ";
        cout<<GetClass()<<endl;
        cout<<"salary: "<<this->get_salary()<<endl;
        cout<<endl;
    }
    float get_salary()const{
        float num1;
        num1=Tutor::get_salary()+2500;
        return num1;
    }
    ~Deputy(){

    }


};



#endif //UNTITLED57_DEPUTY_H
