//
// Created by יהודה on 04/09/2023.
//

#include <iostream>
#include <cstring>

using namespace std;
#ifndef UNTITLED57_WORKER_H
#define UNTITLED57_WORKER_H


class Worker {
protected:
    char *name;
    long ID;
    float seniority;

public:
    Worker(char *name1= nullptr,long ID1=0,float num1=0){
        name=new char[strlen(name1)+1];
        strcpy(name,name1);
        ID=ID1;
        seniority=num1;
    }
    virtual void print() const=0;
    virtual float get_salary()const= 0;
    virtual ~Worker(){
        delete[]name;

    }
    long GetID()const{
        return ID;
    }
    char *getName()const{
        return name;
    }


};


#endif //UNTITLED57_WORKER_H
