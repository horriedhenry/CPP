#include <iostream>
#include <string>

class Logger {
public:
    Logger() { 
        std::cout << "\nLogger initialized.\n";
    }
    void log(const std::string& msg) {
        std::cout << "LOG: " << msg << "\n";
    }
    ~Logger() { 
        std::cout << "\nLogger destructor called.\n";
    }
};

class MobileApplication {
public:
    // declared here 
    static Logger appLogger; // only initialized once
    std::string objName;

    MobileApplication(const std::string& objName)
    {
        this->objName = objName;
        std::cout << "\nMobileApplication Constructor called\n";
    }

    void doSomething() {
        std::cout << "\nCurrent objName : " << this->objName << '\n';
        appLogger.log("Doing something important.");
    }

    ~MobileApplication()
    {
        std::cout << "\nMobileApplication Destructor called for objName : " << this->objName << '\n';
    }
};

class DesktopApplication {
public:
    Logger appLogger;
    std::string objName;

    DesktopApplication(const std::string& objName)
    {
        this->objName = objName;
        std::cout << "\nMobileApplication Constructor called\n";
    }

    void doSomething() {
        std::cout << "\nCurrent objName : " << this->objName << '\n';
        appLogger.log("Doing something important.");
    }
    ~DesktopApplication()
    {
        std::cout << "\nDesktopApplication Destructor called for objName : " << this->objName << "\n";
    }
};

// defined or instantiated in global scope
Logger MobileApplication::appLogger; // appLogger is instantiated here once

int main() {
    // even if we create multiple objects the appLogger is initialized once (in global scope)
    MobileApplication app1("app1"), app2("app2");
    app1.doSomething();
    app2.doSomething();

    /*DesktopApplication dapp1("dapp1");*/
    /*dapp1.doSomething();*/
    /**/
    /*DesktopApplication dapp2("dapp2");*/
    /*dapp2.doSomething();*/
    return 0;
}
