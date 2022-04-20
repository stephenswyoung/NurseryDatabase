// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Stephen Young
// ssy397
// Slip days used: <0>
// Fall 2021

#include <stdio.h>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"
#include <iostream>

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    // not done, your effort goes here
    UTString per;
    UTString item;
    readString(per);
    readString(item);
    UTString bottle="Bottles";
    UTString rattle="Rattles";
    UTString diaper="Diapers";
    if(item==bottle){
        int a;
        readNum(a);
        if (a==0){
            return;
        }
        if (a>num_bottles){
            std::cout << "Sorry " << per.c_str();
            std::cout <<", we only have " << num_bottles << " Bottles" << std::endl;
        }
        else {
            if(!(database.isMember(per))) {
                Customer newCustomer(per);
                database[per] = newCustomer;
            }
            database[per].bottles += a;
            num_bottles -= a;
        }
    }
    if(item==diaper){
        int b;
        readNum(b);
        if (b==0){
            return;
        }
        if(b>num_diapers){
            std::cout << "Sorry " << per.c_str();
            std::cout <<", we only have " << num_diapers << " Diapers" << std::endl;
        }
        else {
            if(!(database.isMember(per))) {
                Customer newCustomer(per);
                database[per] = newCustomer;
            }
            database[per].diapers += b;
            num_diapers -= b;
        }
    }
    if(item==rattle){
        int c;
        readNum(c);
        if (c==0){
            return;
        }
        if(c>num_rattles){
            std::cout << "Sorry " << per.c_str();
            std::cout <<", we only have " << num_rattles << " Rattles" << std::endl;
        }
        else {
            if(!(database.isMember(per))) {
                Customer newCustomer(per);
                database[per] = newCustomer;
            }
            database[per].rattles += c;
            num_rattles -= c;
        }
    }




}

void processSummarize() {
    int custCnt=0;
    // not done, your effort goes here
    //1. Print how many bottles, rattles, diapers print(globals)
    //2. How many customers in DB print(database.size)
    //3. String 1. DP 2. RT 3. BT
    //4. Created customer *c (to find who bought the most bottles)
    //5. c=findMax(bt);
    //5. if(c!=0) print c->name.str() and c->bottles
    //6. repeat for other 2
    UTString DP= "Diapers";
    UTString RT= "Rattles";
    UTString BT= "Bottles";
    Customer* c;
    std::cout << "There are " << num_bottles << " Bottles, "
    << num_diapers << " Diapers and " << num_rattles <<
    " Rattles in inventory" << std::endl;
    std::cout << "we have had a total of " << database.size() << " different customers" << std::endl;
    c= findMax(BT);
    if(c==0){
        std::cout << "no one has purchased any Bottles" << std::endl;
    }
    else{
        std::cout << c->name.c_str() << " has purchased the most Bottles (" << c->bottles <<")" << std::endl;
    }
    c= findMax(DP);
    if(c==0){
        std::cout << "no one has purchased any Diapers" << std::endl;
    }
    else{
        std::cout << c->name.c_str() << " has purchased the most Diapers (" << c->diapers <<")" << std::endl;
    }
    c= findMax(RT);
    if(c==0){
        std::cout << "no one has purchased any Rattles" << std::endl;
    }
    else{
        std::cout << c->name.c_str() << " has purchased the most Rattles (" << c->rattles <<")" << std::endl;
    }


}

void processInventory() {
    // not done, your effort goes here
    int a=0;
    int b=0;
    int c=0;
    UTString bottles="Bottles";
    UTString rattles="Rattles";
    UTString diapers="Diapers";
    UTString item;
    readString(item);
    if(item==bottles){
        readNum(a);
    }
    if(item==rattles){
        readNum(b);
    }
    if(item==diapers){
        readNum(c);
    }
    num_bottles+=a;
    num_rattles+=b;
    num_diapers+=c;
}
