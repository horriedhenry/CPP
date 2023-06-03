#include <iostream>
using namespace std;
// source : [https://www.javatpoint.com/cpp-inheritance]
// # Hybrid Inheritance.
// Look source for Hybrid Inheritance image

class A {
protected:
    int a = 1;
public:
    void Afun() {
        cout<<"Afun()"<<endl;
    }
    void get_a() {
        cout<<"a : "<<a<<endl;
    }
};

class B : public A{
protected:
    int b = 2;
public:
    void Bfun() {
        cout<<"Bfun()"<<endl;
    }
    void get_b() {
        cout<<"b : "<<b<<endl;
    }
};

class C : public B{
protected:
    int c = 3;
public:
    void Cfun() {
        cout<<"Cfun()"<<endl;
    }
    void get_c() {
        cout<<"c : "<<c<<endl;
    }
};

class D : public C{
protected:
    int d = 4;
public:
    void Dfun() {
        cout<<"Dfun()"<<endl;
    }
    void get_d() {
        cout<<"d : "<<d<<endl;
    }
    void mul() {
        cout<<"mul() is in D class :"<<endl;
        cout<<"a * b * c * d = "<<a*b*c*d<<endl;
    }
};

int main (int argc, char *argv[]) {
    D d;
    d.Afun();
    d.Bfun();
    d.Cfun();
    d.Dfun();
    d.get_a();
    d.get_b();
    d.get_c();
    d.get_d();
    d.mul();
    return 0;
}
