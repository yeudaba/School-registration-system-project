//
// Created by יהודה on 04/09/2023.
//

#include "Teacher.h"

#ifndef UNTITLED57_TUTOR_H
#define UNTITLED57_TUTOR_H

class Tutor:public Teacher{
protected:
    char *class1;

public:
    Tutor(char *c= nullptr,char **name= nullptr,int P=0,long ID=0,float num1=0,char *name1= nullptr):Teacher(name,P,ID,num1,name1){
        class1=new char[strlen(c)+1];
        strcpy(class1,c);
    }
    float get_salary() const {
        float num1;
        num1=Teacher::get_salary()+1000;
        return num1;
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
    ~Tutor(){
        delete[]class1;


    }
    char *GetClass()const{
        return class1;
    }

};


#endif //UNTITLED57_TUTOR_H
