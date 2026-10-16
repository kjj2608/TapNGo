#ifndef TAPNGO_PAYMENT_H
#define TAPNGO_PAYMENT_H

#include <string>

class Payment {
public:
    virtual ~Payment() = default;
    virtual bool processPayment(double amount, const std::string& paymentToken) = 0;
    virtual std::string getMethodName() const = 0;
};

#endif
