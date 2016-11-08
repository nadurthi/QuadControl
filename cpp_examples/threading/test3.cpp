#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>


class BankAccount2 {
    boost::mutex mtx_;
    int balance_;
public:
	BankAccount2(void){
		balance_=5000;	
	}
    int Deposit(int amount) {
        mtx_.lock();
        balance_ += amount;
        mtx_.unlock();
        return balance_;

    }
    int Withdraw(int amount) {
        mtx_.lock();
        balance_ -= amount;
        mtx_.unlock();
        return balance_;

    }
    int GetBalance() {
        mtx_.lock();
        int b = balance_;
        mtx_.unlock();
        return b;
    }
};


class BankAccount {
    int balance_;
public:
	BankAccount(void){
	balance_=5000;	
	}
    int Deposit(int amount) {
        balance_ += amount;
        return balance_;
    }
    int Withdraw(int amount) {
        balance_ -= amount;
        return balance_;
    }
    int GetBalance() {
        int b = balance_;
        return b;
    }
};


BankAccount2 JoesAccount;

void bankAgent()
{
    for (int i =10; i>0; --i) {
        //...
        JoesAccount.Deposit(500);
        std::cout<<"deposit"<<"\n";
        //...
    }
}

void Joe() {
    for (int i =10; i>0; --i) {
        //...
        int myPocket = JoesAccount.Withdraw(100);
        std::cout << myPocket << std::endl;
        std::cout<<"withdraw"<<"\n";
        //...
    }
}

int main() {
    //...
    std::cout<< JoesAccount.GetBalance()<<"\n\n";
    boost::thread thread2(Joe); // start concurrent execution of Joe
    boost::thread thread1(bankAgent); // start concurrent execution of bankAgent
    thread2.join();
    thread1.join();
    return 0;
}