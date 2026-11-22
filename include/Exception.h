#ifndef EXCEPTION_H
#define EXCEPTION_H

#include<stdexcept>
#include<string>

class close_file_exception : public std::exception {
    private:
        std::string message;
    public:
        close_file_exception(std::string msg): message(msg) {}
        const char* what() const noexcept override {
            return message.c_str();
        }
};

#endif
