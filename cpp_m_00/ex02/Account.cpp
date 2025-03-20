/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:29:54 by hthant            #+#    #+#             */
/*   Updated: 2025/03/20 20:03:32 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void){return _nbAccounts;};

int	Account::getTotalAmount(void){return _totalAmount;};

int	Account::getNbDeposits(void){return _totalNbDeposits;};

int	Account::getNbWithdrawals(void){return _totalNbWithdrawals;};

void Account::_displayTimestamp(void)
{
    std:: time_t currentTime = std:: time(0);
    std:: tm* nowTime = std:: localtime(&currentTime);

    std:: cout  << "[" 
                << nowTime->tm_year + 1900
                << nowTime->tm_mon + 1
                << nowTime->tm_mday << "_"
                << nowTime->tm_hour
                << nowTime->tm_min
                << nowTime->tm_sec
                << "]";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" <<_accountIndex
    << ";amount:"<<_amount
    << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" <<_accountIndex
    << ";amount:"<<_amount
    << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals 
              << std::endl;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}

void Account::makeDeposit( int deposit )
{
    int p_amount;

    p_amount = checkAmount();
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout <<"index:" << _accountIndex
              <<";p_amount:" << p_amount
              <<";deposit:" << deposit
              <<";amount:" <<_amount
              <<";nb_deposits:" <<_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout <<"index:" << _accountIndex
              <<";p_amount:" << _amount;
    if(_amount - withdrawal < 0)
    {
        std::cout <<";withdrawal:refused"<<std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout <<";withdrawal:"<<withdrawal
              <<";amount:"<<_amount
              <<";nb_withdrawals:"<<_nbWithdrawals
              << std::endl;
    return (true);
}

int Account::checkAmount( void ) const {return (_amount);}