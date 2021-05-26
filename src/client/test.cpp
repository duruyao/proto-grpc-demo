//
// Created by duruyao on 2021/5/26.
//

#include <iostream>
#include <fstream>
#include <string>

#include "addressbook.pb.h"

using tutorial::Person;
using tutorial::PhoneType;
using tutorial::PhoneNumber;
using tutorial::AddressBook;

void ListPeople(const AddressBook &address_book) {
    for (int i = 0; i < address_book.people_size(); i++) {
        const Person &person = address_book.people(i);

        std::cout << "Person ID: " << person.id() << endl;
        std::cout << "Name: " << person.name() << endl;
        if (person.has_email()) {
            std::cout << "E-mail address: " << person.email() << endl;
        }

        for (int j = 0; j < person.phones_size(); j++) {
            const Person::PhoneNumber &phone_number = person.phones(j);

            switch (phone_number.type()) {
                case Person::MOBILE:
                    std::cout << "  Mobile phone #: ";
                    break;
                case Person::HOME:
                    std::cout << "  Home phone #: ";
                    break;
                case Person::WORK:
                    std::cout << "  Work phone #: ";
                    break;
            }
            cout << phone_number.number() << endl;
        }
    }
}