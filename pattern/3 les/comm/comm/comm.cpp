

#include <iostream>
#include <fstream>
#include <vector>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class PrintCommand : public LogCommand {
public:
    void print(const std::string& message) {
        std::cout << message;
    }
};

class  FstrCommand:public LogCommand {
public:
    void print(const std::string& message) {
        std::ofstream out;
        out.open("File.txt");
        if (out.is_open())
        {
            out << message << std::endl;
        }
        out.close();
    }
};

void print(LogCommand& LC, const std::string& message) {
    LC.print(message);
}


class SomeClass;


class Observer {
public:
    
    Observer(SomeClass& sclass);
    
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    
protected:
    SomeClass& SC;

};



class SomeClass {
public:
    void warning(const std::string& message) const {
        for (Observer* observer : observers) {
            observer->onWarning(message);
        }
    };
    void error(const std::string& message) const {
        for (Observer* observer : observers) {
            observer->onError(message);
        }
    };
    void fatalError(const std::string& message) const {
        for (Observer* observer : observers) {
            observer->onFatalError(message);
        }
    };
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }
    void removeObserver(Observer* observer) {
        auto it = std::remove(observers.begin(), observers.end(), observer);
        observers.erase(it, observers.end());
    }
    
private:
    std::vector<Observer*> observers;
};

Observer::Observer(SomeClass& sclass) :SC(sclass) {
    SC.registerObserver(this);
}

class ObserverWarning :public Observer {
public:
    using Observer::Observer;
    void onWarning(const std::string& message) {
        std::cout << message;
    }
    ~ObserverWarning() {
        SC.removeObserver(this);
    }
};
class ObserverError :public Observer {
public:
    using Observer::Observer;
    void onError(const std::string& message) {
        std::fstream out;
        out.open("File.txt",std::ofstream::app);
        if (out.is_open())
        {
            out << message << "\n" << std::endl;
        }
        
    }
    ~ObserverError() {
        SC.removeObserver(this);
    }
};
class ObserverFatalError :public Observer {
public:
    using Observer::Observer;
    void onFatalError(const std::string& message) {
        std::cout << message;
        std::fstream out;
        out.open("File.txt", std::ofstream::app);
        if (out.is_open())
        {
            out << message<<"\n" << std::endl;
        }
       
    }
    ~ObserverFatalError() {
        SC.removeObserver(this);
    }
    
};



    
int main()
{
    std::cout << "Hello World!\n";
    SomeClass SC;   
    ObserverError ob(SC);
    ObserverWarning ow(SC);
    ObserverFatalError ofe(SC);
    SC.error("eror");
    SC.warning("warning");
    SC.fatalError("ATAL EROR");
    
    
}

