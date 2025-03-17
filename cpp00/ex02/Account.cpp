#include "Account.hpp"

#include <iostream> //cout cin...
#include <ctime>
#include <iomanip> //setw()

//! comment declarer var static deja ???????????

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
  
//! hein ???????????????????????????????????????????
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) 
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) 
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) 
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) 
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) 
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits //!
              << ";withdrawals:" << this->_nbWithdrawals //!
              << std::endl;
}

void Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    this->_nbDeposits++;
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << this->_amount - deposit
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << this->_amount; 
    if (checkAmount() > withdrawal)
    {
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal 
                  << ";amount:" << this->_amount 
                  << ";nb_withdrawals:" << this->_nbWithdrawals 
                  << std::endl;
        return (true);
    }
    std::cout << ";withdrawal:" << "refused" << std::endl;
    return (false);
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void Account::_displayTimestamp(void) 
{
    time_t now = time(NULL);
    struct tm* time = localtime(&now);

    std::cout << "["
              << (time->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (time->tm_mon + 1) //setfill permet de rajouter des 0 si le chiffre est inferieur a 10 (//setw(2))
              << std::setw(2) << std::setfill('0') << time->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << time->tm_hour
              << std::setw(2) << std::setfill('0') << time->tm_min
              << std::setw(2) << std::setfill('0') << time->tm_sec
              << "] ";
}

// refused...... etc