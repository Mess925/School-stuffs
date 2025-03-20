/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:29:54 by hthant            #+#    #+#             */
/*   Updated: 2025/03/20 14:19:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts() {return _nbAccounts;};
int	Account::getTotalAmount(){ return _totalAmount;};
int	Account::getNbDeposits() {return _totalNbDeposits;};
int	Account::getNbWithdrawals(){return _totalNbWithdrawals;};
void Account::_displayTimestamp()
{
    
}
void Account::displayAccountsInfos( void ) 
{
    
};