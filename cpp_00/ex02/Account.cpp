// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <string>
#include <iostream>
#include <ctime>

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	++_nbAccounts;
	_totalAmount += initial_deposit;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void ) { return _nbAccounts;}
int	Account::getTotalAmount( void ) { return _totalAmount;}
int	Account::getNbDeposits( void ) { return _totalNbDeposits;}
int	Account::getNbWithdrawals( void ) { return _totalNbWithdrawals;}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}
void	Account::makeDeposit( int deposit )
{
	if (deposit < 0)
		return;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << (_amount += deposit) << ";";
	std::cout << "nb_deposits:" << ++_nbDeposits << std::endl;
	++_totalNbDeposits;
	_totalAmount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
   	std::cout << withdrawal << ";";
	std::cout << "amount:" << (_amount -= withdrawal) << ";";
	std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	++_totalNbWithdrawals;
	_totalAmount -= withdrawal;
	return true;
}
int		Account::checkAmount( void ) const { return _amount;}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;

}
void	Account::_displayTimestamp( void )
{
	char	buf[24];
	std::time_t now = std::time(NULL);
	if (std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", std::localtime(&now)))
		std::cout << buf;
}
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
