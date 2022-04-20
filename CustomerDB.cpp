/*
 * Copy the contents of header.txt (filled out) and paste here
 */
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    for(int i=0; i<this->length; i++) {
        if (data[i].name == name) {
            return this->data[i];
        }
    }
    if(this->capacity==this->length) {
        this->capacity=this->capacity * 2;
        Customer* newData = new Customer[this->capacity];
        for(int j=0; j<this->length; j++){
            newData[j].name=data[j].name;
            newData[j].bottles=data[j].bottles;
            newData[j].rattles=data[j].rattles;
            newData[j].diapers=data[j].diapers;
        }
        //length++;
        newData[length].name=name;
        delete[]data;
        data=newData;
        length++;
        return data[length-1];
    }
    else{
        data[length].name=name;
        length++;
        return data[length-1];
    }


}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here

    for(int i=0;this->length>i;i++){
        if(data[i].name==name){
            return true;
        }
    }
    return false;
}

