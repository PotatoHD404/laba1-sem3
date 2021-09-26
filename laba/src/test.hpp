//
// Created by kmv026 on 23.09.2021.
//

#ifndef LABA3_TEST_HPP
#define LABA3_TEST_HPP

//#include <memory>
//using namespace std;
class Base {
public:
    int a;

    explicit Base(int a = 2) : a(a) {}
};

class Derived : public Base {
public:
    Derived(): Base(){

    }
//    Derived* Copy(){
//        return this();
//    }
//    Base method()  {
//        return nullptr;
//    }
};
//
//void test(){
//    auto a = new Delivered();
//    shared_ptr<Delivered> b = a->method();
//
//}
#endif //LABA3_TEST_HPP
