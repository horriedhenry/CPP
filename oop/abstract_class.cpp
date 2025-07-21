#include <iostream>

class PaymentMethod {
public:
    virtual void pay(double amount) = 0;

    virtual ~PaymentMethod() = default;
};

class CreditCard : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " using credit card\n";
    }
};

class Upi : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " via UPI\n";
    }
};

class Cash : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Paid " << amount << " in cash\n";
    }
};

int main ()
{
    PaymentMethod* payment;

    CreditCard c;
    payment = &c;
    payment->pay(300);
    // you don't need to call delete for `c` object as it will be deleted
    // when it goes out of scope

    // or 
    payment = new Upi();
    payment->pay(400);
    delete payment;

    payment = new Cash();
    payment->pay(500);
    delete payment;
    return 0;
}
