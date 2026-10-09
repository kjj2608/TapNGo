#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
protected:
    double amount;

public:
    Payment(double amount);

    virtual bool processPayment() = 0;
    virtual bool verify() = 0;

    double getAmount() const;

    virtual ~Payment() = default;
};

#endif