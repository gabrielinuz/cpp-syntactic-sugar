#include "../include/SyntacticSugar.hpp"
#include <iostream>
#include <string>
#include <memory>

interface IService 
{
    abstract_method(void, call);
};

class TestService implements IService
{
    public:
        override_method(void, call)
        {
            // std::cout << "TestService Called" << std::endl;
            print("TestService called.", endline);
        }
};

// Herencia de clase concreta/abstracta
abstract_class BaseLogger
{
    public:
        abstract_method(void, log, const std::string& msg);
        concrete_method(void, baseMethod)
        {
            // std::cout << "Base method called." << std::endl;
            print("Base method called.", endline);
        }
};

class FileLogger extends BaseLogger 
{
    public:
        override_method(void, log, const std::string& msg)
        {
            // std::cout << "[FILE] " << msg << std::endl;
            printline("[FILE] ", msg);
        }
};

void testUniqueLogger(unique(BaseLogger) logger)
{
    logger->log("A unique log file...");
}

void testSharedLogger(shared(BaseLogger) logger)
{
    logger->log("A shared log file...");
}

int main()
{
    // Tipado polimórfico explícito (opcional pero didáctico)
    // shared_ref<IService> service = new_shared(TestService);
    shared(IService) service = new_shared(TestService);
    service->call();

    // unique_ref<BaseLogger> logger = new_unique(FileLogger);
    unique(BaseLogger) logger = new_unique(FileLogger);
    logger->log("A log file...");
    logger->baseMethod();

    // testUniqueLogger(logger);//ESTO NO SE DEBERÍA PODER HACER
    
    // shared_ref<BaseLogger> slogger = new_shared(FileLogger);
    shared(BaseLogger) slogger = new_shared(FileLogger);
    testSharedLogger(slogger);

    return 0;
}