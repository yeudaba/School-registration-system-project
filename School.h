//
// Created by יהודה on 04/09/2023.
//
#include "Tutor.h"
#include "Temp.h"
#include "Deputy.h"
#include "Manager.h"
#include "Secretary.h"

#ifndef UNTITLED57_SCHOOL_H
#define UNTITLED57_SCHOOL_H

class School{
private:
    int NumPeople;
    Worker **arr;
    bool Man;

public:
    School(){
        NumPeople=0;
        arr= nullptr;
        Man= false;
    }

    ~School(){
        for(int i=0; i < NumPeople; ++i){
            delete arr[i];
        }
        delete[] arr;
    }

    void addEmployee() {
        char type;
        cout << "Choose type of worker:" << endl
             << "A. Teacher" << endl
             << "B. Temp" << endl
             << "C. Tutor" << endl
             << "D. Deputy" << endl
             << "E. Manager" << endl
             << "F. Secretary" << endl;
        cin >> type;

        char name[11];
        char name1[10];
        long postalCode;
        float seniority;
        int numOfSubjects;
        char** subjectNames = nullptr;
        float weeklyHours;
        char classTaught[3];
        bool postalCodeExists = false;
        bool classExists = false;

        switch (toupper(type)) {
            case 'A':
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter postal code: ";
                cin >> postalCode;
                cout << "Enter seniority: ";
                cin >> seniority;
                cout << "Enter number of subjects taught: ";
                cin >> numOfSubjects;
                subjectNames = new char*[numOfSubjects];
                for (int i = 0; i < numOfSubjects; i++) {
                    cout << "Enter name of subject " << i + 1 << ": ";
                    cin >> name1;
                    subjectNames[i] = new char[strlen(name1) + 1];
                    strcpy(subjectNames[i], name1);
                }


                for(int i = 0; i < NumPeople; ++i) {
                    if(arr[i]->GetID() == postalCode) {
                        postalCodeExists = true;
                        break;
                    }
                }

                if(postalCodeExists) {
                    cout << "The entered postal code already exists!" << endl;
                    break;
                }
                else{
                    Worker **temp = new Worker *[NumPeople+1];
                    for(int i = 0; i < NumPeople; ++i) {
                        temp[i] = arr[i];
                    }
                    temp[NumPeople] = new Teacher(subjectNames, numOfSubjects, postalCode, seniority, name);
                    delete[] arr;
                    arr = temp;
                    NumPeople++;
                    for(int i = 0; i < numOfSubjects; ++i){
                        delete[] subjectNames[i];
                    }
                    delete[] subjectNames;
                    cout << "Teacher added successfully!" << endl;
                }

                break;

            case 'B':
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter postal code: ";
                cin >> postalCode;
                cout << "Enter seniority: ";
                cin >> seniority;
                cout << "Enter number of subjects taught: ";
                cin >> numOfSubjects;
                subjectNames = new char*[numOfSubjects];
                for (int i = 0; i < numOfSubjects; i++) {
                    cout << "Enter name of subject " << i + 1 << ": ";
                    cin >> name1;
                    subjectNames[i] = new char[strlen(name1) + 1];
                    strcpy(subjectNames[i], name1);
                }
                cout << "Enter weekly hours taught: ";
                cin >> weeklyHours;


                for(int i = 0; i < NumPeople; ++i) {
                    if(arr[i]->GetID() == postalCode) {
                        postalCodeExists = true;
                        break;
                    }
                }

                if(postalCodeExists) {
                    cout << "The entered postal code already exists!" << endl;
                    break;
                }
                else{
                    Worker **temp = new Worker *[NumPeople+1];
                    for(int i = 0; i < NumPeople; ++i) {
                        temp[i] = arr[i];
                    }
                    temp[NumPeople] = new Temp(weeklyHours, subjectNames, numOfSubjects, postalCode, seniority, name);
                    delete[] arr;
                    arr = temp;
                    NumPeople++;
                    for(int i = 0; i < numOfSubjects; ++i) {
                        delete[] subjectNames[i];
                    }
                    delete[] subjectNames;
                    cout << "Temp added successfully!" << endl;
                }

                break;

            case 'C':
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter postal code: ";
                cin >> postalCode;
                cout << "Enter seniority: ";
                cin >> seniority;
                cout << "Enter number of subjects taught: ";
                cin >> numOfSubjects;
                subjectNames = new char*[numOfSubjects];
                for (int i = 0; i < numOfSubjects; i++) {
                    cout << "Enter name of subject " << i + 1 << ": ";
                    cin >> name1;
                    subjectNames[i] = new char[strlen(name1) + 1];
                    strcpy(subjectNames[i], name1);
                }
                cout << "Enter class taught: ";
                cin >> classTaught;

                for(int i = 0; i < NumPeople; ++i) {
                    Tutor* tempTutor = dynamic_cast<Tutor*>(arr[i]);
                    if(tempTutor != nullptr && strcmp(tempTutor->GetClass(), classTaught) == 0) {
                        classExists = true;
                        break;
                    }
                }

                if(classExists) {
                    cout << "A tutor for the same class already exists in the school!" << endl;
                    break;
                }
                else{
                    Worker **temp = new Worker *[NumPeople+1];
                    for(int i = 0; i < NumPeople; ++i) {
                        temp[i] = arr[i];
                    }
                    temp[NumPeople] = new Tutor(classTaught, subjectNames, numOfSubjects, postalCode, seniority, name);
                    delete[] arr;
                    arr = temp;
                    NumPeople++;
                    for(int i = 0; i < numOfSubjects; ++i) {
                        delete[] subjectNames[i];
                    }
                    delete[] subjectNames;
                    cout << "Tutor added successfully!" << endl;
                }

                break;

            case 'D':
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter postal code: ";
                cin >> postalCode;
                cout << "Enter seniority: ";
                cin >> seniority;
                cout << "Enter number of subjects taught: ";
                cin >> numOfSubjects;
                subjectNames = new char*[numOfSubjects];
                for (int i = 0; i < numOfSubjects; i++) {
                    cout << "Enter name of subject " << i + 1 << ": ";
                    cin >> name1;
                    subjectNames[i] = new char[strlen(name1) + 1];
                    strcpy(subjectNames[i], name1);
                }
                cout << "Enter class taught: ";
                cin >> classTaught;


                for(int i = 0; i < NumPeople; ++i) {
                    Deputy* tempDeputy = dynamic_cast<Deputy*>(arr[i]);
                    if(tempDeputy != nullptr && strcmp(tempDeputy->GetClass(), classTaught) == 0) {
                        classExists = true;
                        break;
                    }
                }

                if(classExists) {
                    cout << "A deputy for the same class already exists in the school!" << endl;
                    break;
                }
                else{
                    Worker **temp = new Worker *[NumPeople+1];
                    for(int i = 0; i < NumPeople; ++i) {
                        temp[i] = arr[i];
                    }
                    temp[NumPeople] = new Deputy(classTaught, subjectNames, numOfSubjects, postalCode, seniority, name);
                    delete[] arr;
                    arr = temp;
                    NumPeople++;
                    for(int i = 0; i < numOfSubjects; ++i) {
                        delete[] subjectNames[i];
                    }
                    delete[] subjectNames;
                    cout << "Deputy added successfully!" << endl;
                }

                break;

            case 'E':
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter postal code: ";
                cin >> postalCode;
                cout << "Enter seniority: ";
                cin >> seniority;
                if (!Man || arr == nullptr) {
                    Worker **temp = new Worker *[NumPeople+1];
                    for(int i = 0; i < NumPeople; ++i) {
                        temp[i] = arr[i];
                    }
                    temp[NumPeople] = new Manager(0, name, postalCode, seniority);
                    delete[] arr;
                    arr = temp;
                    NumPeople++;
                    Man = true;
                    cout << "Manager added as Principal successfully!" << endl;
                }
                else {
                    cout << "A Principal already exists in the school!" << endl;
                }
                break;

            case 'F':
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter postal code: ";
                cin >> postalCode;
                cout << "Enter seniority: ";
                cin >> seniority;
                cout << "Enter overtime worked: ";
                cin >> weeklyHours;


                for(int i = 0; i < NumPeople; ++i) {
                    if(arr[i]->GetID() == postalCode) {
                        postalCodeExists = true;
                        break;
                    }
                }

                if(postalCodeExists) {
                    cout << "The entered postal code already exists!" << endl;
                    break;
                }
                else{
                    Worker **temp = new Worker *[NumPeople+1];
                    for(int i = 0; i < NumPeople; ++i) {
                        temp[i] = arr[i];
                    }
                    temp[NumPeople] = new Secretary(name, postalCode, seniority, weeklyHours);
                    delete[] arr;
                    arr = temp;
                    NumPeople++;
                    cout << "Secretary added successfully!" << endl;
                }

                break;

            default:
                break;
        }
    }

    void Menu(){
        bool keepRunning = true;
        while (keepRunning) {
            cout << "Choose an option:" << endl
                 << "1. Add worker" << endl
                 << "2. Print workers" << endl
                 << "3. Print by profession" << endl
                 << "4. Print tutors" << endl
                 << "5. Print management" << endl
                 << "6. Exit" << endl;
            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    this->addEmployee();
                    break;
                case 2:
                    this->printWorker();
                    break;
                case 3:
                    this->print_Profession();
                    break;
                case 4:
                    this->printTutors();
                    break;
                case 5:
                    this->printManagement();
                    break;
                case 6:
                    keepRunning = false;
                    break;
                default:
                    cout << "Invalid input!" << endl;
                    break;
            }
        }
    }

    void printWorker(){
        if(NumPeople == 0){
            cout << "There are no employees." << endl;
            return;
        }
        for(int i = 0; i < NumPeople; ++i){
            arr[i]->print();
        }
    }

    void print_Profession(){
        char profession[11];
        bool foundMatch = false;
        cout << "Enter a profession: ";
        cin >> profession;
        for (int i = 0; i < NumPeople; i++) {
            Teacher* t = dynamic_cast<Teacher*>(arr[i]);
            if (t) {
                for (int j = 0; j < t->numProfessions(); j++) {
                    if (strcmp(t->getSubject(j), profession) == 0) {
                        cout << t->getName() << endl;
                        foundMatch = true;
                    }
                }
            }
        }
        if (!foundMatch) {
            cout << "No teachers found who can teach this profession." << endl;
        }
    }

    void printTutors(){
        bool foundMatch = false;
        for (int i = 0; i < NumPeople; i++) {
            Tutor* e = dynamic_cast<Tutor*>(arr[i]);
            if (e) {
                cout << e->getName() << " - Class: " << e->GetClass() << endl;
                foundMatch = true;
            }
        }
        if (!foundMatch) {
            cout << "No educators found in the school." << endl;
        }
    }

    void printManagement() {
        Manager* m = nullptr;
        Deputy* d = nullptr;
        for (int i = 0; i < NumPeople; i++) {
            Manager* tempM = dynamic_cast<Manager*>(arr[i]);
            if (tempM) {
                m = tempM;
            }
            Deputy* tempD = dynamic_cast<Deputy*>(arr[i]);
            if (tempD) {
                if(strcmp(tempD->GetClass(), "101") == 0) {
                    d = tempD;
                }
            }
        }
        if (m) {
            cout << "Manager: " << m->getName() << endl;
        }
        else {
            cout << "No Manager found in the school." << endl;
        }
        if (d) {
            cout << "Principal: " << d->getName() << endl;
        }
        else if (Man) {
            cout << "No Deputy Director found for Class 101." << endl;
        }
    }
};

#endif //UNTITLED57_SCHOOL_H
