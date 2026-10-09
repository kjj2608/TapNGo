class Payment {
    protected:
        double amount;

    public:
        Payment(double amount){
            amount = amount;
        }

        virtual bool processPayment() = 0;
        virtual bool verify() = 0;

        double getAmount() {
            return amount;
        }

        virtual ~Payment(){}
};