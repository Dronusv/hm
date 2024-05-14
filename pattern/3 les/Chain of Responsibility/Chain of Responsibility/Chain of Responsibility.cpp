

#include <iostream>
#include <fstream>
#include <exception>

enum class Type {Warning,Eror,FatalEror,Unknow};
class LogMessage {
public:
    LogMessage(Type type, const std::string& message) : _type(type), _message(message) {};

    Type type() const {
        return _type;
    };

     std::string message() const {
        return _message;
    };
private:
    Type _type;
    std::string _message;
};


class MessageHandler {
public:
    virtual MessageHandler& setNextHandler(MessageHandler* handler)=0;
    virtual void handleRequest(LogMessage LM) {};
};

class FatalErrorHandler : public MessageHandler {
private:
    MessageHandler* nextHandler;
public:
    MessageHandler& setNextHandler(MessageHandler* handler) {
        nextHandler = handler;
        return *nextHandler;
     }
     void handleRequest(LogMessage LM) override
     {
         if (LM.type() == Type::FatalEror) {
             throw LM.message();
         }
         else if (nextHandler != nullptr) {
             nextHandler->handleRequest(LM);
         }
     }
};

class  ErrorHandler : public MessageHandler {
private:
    MessageHandler* nextHandler;
public:
    MessageHandler& setNextHandler(MessageHandler* handler) {
        nextHandler = handler;
        return *nextHandler;
    }
    void handleRequest(LogMessage LM) override
    {
        if (LM.type() == Type::Eror) {
            std::ofstream out;
            out.open("Log.txt");
            if (out.is_open())
            {
                out << LM.message() << std::endl;
            }
            out.close();
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(LM);
        }
    }
};

class  WarningHandler : public MessageHandler {
private:
    MessageHandler* nextHandler;
public:
    MessageHandler& setNextHandler(MessageHandler* handler) {
        nextHandler = handler;
        return *nextHandler;
    }
    void handleRequest(LogMessage LM) override
    {
        if (LM.type() == Type::Warning) {
            std::cout << LM.message();
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(LM);
        }
    }
};
class  UnknowHandler : public MessageHandler {
private:
    MessageHandler* nextHandler;
public:
    MessageHandler& setNextHandler(MessageHandler* handler) {
        nextHandler = handler;
        return *nextHandler;
    }
    void handleRequest(LogMessage LM) override
    {
        if (LM.type() == Type::Unknow) {
            throw LM.message();
        }
        else if (nextHandler != nullptr) {
            nextHandler->handleRequest(LM);
        }
    }
};
int main()
{
    try{
         LogMessage LMW(Type::Warning, "War");
         LogMessage LME(Type::Eror, "Error");
         LogMessage LMFE(Type::FatalEror, "Fatal error");
         LogMessage LMU(Type::Unknow, "Unknow");

         FatalErrorHandler FEM;
         ErrorHandler EH;
         WarningHandler WH;
         UnknowHandler UH;
         FEM.setNextHandler(&EH).setNextHandler(&WH).setNextHandler(&UH);
         
         FEM.handleRequest(LMU);
    }
    catch (const std::string &ex) {
        std::cout << ex;
    }
}

