//
// Created by יהודה on 04/09/2023.
//
#include "Worker.h"

#ifndef UNTITLED57_TEACHER_H
#define UNTITLED57_TEACHER_H

class Teacher: public Worker{
protected:
    int Professions;
    char **nameProfessions;

public:
    Teacher(char **name= nullptr,int P=0,long ID=0,float num1=0,char *name1= nullptr):Worker(name1,ID,num1),Professions(P){
        nameProfessions=new char *[Professions];
        for(int i=0; i<Professions; ++i){
            nameProfessions[i]=new char[strlen(name[i])+1];
            strcpy(nameProfessions[i],name[i]);
        }

    }
    ~Teacher(){
        for(int i=0; i<Professions; ++i){
            delete[]nameProfessions[i];
        }
        delete[]nameProfessions;

    }
    void print()const{
        cout<<"name: ";
        cout<<getName()<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Seniority: "<<seniority<<endl;
        cout<<"salary: "<<get_salary()<<endl;
        cout<<endl;

    }
    float get_salary()const{
        float num1;
        num1=5000+(seniority*500)+(Professions*300);
        return num1;
    }
    int numProfessions()const{
        return Professions;
    }
    char *getSubject(int j){
        return nameProfessions[j];
    }


};



#endif //UNTITLED57_TEACHER_H
