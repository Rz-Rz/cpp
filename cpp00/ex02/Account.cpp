#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits" << _totalNbDeposits << ";withdrawals" << _totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount;" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit << ";amount:" << (_amount + deposit)
		<< ";nb_deposits:" << (_nbDeposits + 1) << std::endl;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return false;
	}

	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:" << withdrawal << ";amount:" << (_amount - withdrawal)
		<< ";nb_withdrawals:" << (_nbWithdrawals + 1) << std::endl;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int Account::checkAmount() const {
    return _amount;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900) << std::setw(2) << std::setfill('0')
              << (now->tm_mon + 1) << std::setw(2) << std::setfill('0') << now->tm_mday
              << "_" << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}
