#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

class BankAccount4 : public basic_lockable_adapter<mutex>
{
    int balance_;
public:
    int Deposit(int amount) {
        boost::lock_guard<BankAccount> guard(*this);
        balance_ += amount;
        return balance_;
    }
    int Withdraw(int amount) {
        boost::lock_guard<BankAccount> guard(*this);
        balance_ -= amount;
        return balance_;
    }
    int GetBalance() {
        boost::lock_guard<BankAccount> guard(*this);
        return balance_;
    }
};

class BankAccount4 : public basic_lockable_adapter<recursive_mutex>
{
    int balance_;
public:
    int Deposit(int amount) {
        boost::lock_guard<BankAccount> guard(*this);
        balance_ += amount;
        return balance_;
    }
    int Withdraw(int amount) {
        boost::lock_guard<BankAccount> guard(*this);
        balance_ -= amount;
        return balance_;
    }
    int GetBalance() {
        boost::lock_guard<BankAccount> guard(*this);
        return balance_;
    }
};

void ATMWithdrawal(BankAccount4 & acct, int sum) {
    boost::lock_guard<BankAccount4> guard(acct);
    acct.Withdraw(sum);
    acct.Withdraw(2);
}


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

class BankAccount3 {
    boost::mutex mtx_; // explicit mutex declaration 
    int balance_;
public:
    int Deposit(int amount) {
        boost::lock_guard<boost::mutex> guard(mtx_);
        balance_ += amount;
        return balance_;
    }
    int Withdraw(int amount) {
        boost::lock_guard<boost::mutex> guard(mtx_);
        balance_ -= amount;
        return balance_;
    }
    int GetBalance() {
        boost::lock_guard<boost::mutex> guard(mtx_);
        return balance_;
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