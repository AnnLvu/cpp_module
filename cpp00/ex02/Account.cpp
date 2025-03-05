/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   Account.cpp										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: alvutina <alvutina@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/24 13:58:43 by alvutina		  #+#	#+#			 */
/*   Updated: 2024/10/24 14:48:24 by alvutina		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Initialize static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Get number of accounts
int Account::getNbAccounts()
{
	return _nbAccounts;
}

// Get total amount
int Account::getTotalAmount()
{
	return _totalAmount;
}

// Get number of deposits
int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

// Get number of withdrawals
int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

// Display timestamp
void Account::_displayTimestamp()
{
	time_t currentTime = time(0);
	tm *localTimeStruct = localtime(&currentTime);
	std::cout << "[" << 1900 + localTimeStruct->tm_year
			  << std::setfill('0') << std::setw(2) << 1 + localTimeStruct->tm_mon
			  << std::setw(2) << localTimeStruct->tm_mday
			  << "_" << std::setw(2) << localTimeStruct->tm_hour
			  << std::setw(2) << localTimeStruct->tm_min
			  << std::setw(2) << localTimeStruct->tm_sec << "] ";
}

// Display account information
void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Constructor
// Initializes a new Account instance with a given initial deposit.
// Increments the total account count and updates the total amount.
// Sets the initial deposit and initializes the deposit and withdrawal counters.
// Displays the account index and initial amount upon creation.
Account::Account(int initial_deposit) : _amount(initial_deposit), _accountIndex(_nbAccounts), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

// Destructor
// Decreases the total number of accounts and updates the total amount when the account is closed.
// Calls the function to display the timestamp and outputs the index and amount of the account upon closure.
Account::~Account()
{
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount -= _amount;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Make deposit
// Updates the account balance by adding the deposit amount.
// Increments the number of deposits for this account and the total deposits across all accounts.
// Displays the account index, previous amount, deposit amount, new balance, and total deposits for the account.
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	int oldBalance = _amount; // Store previous amount
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";p_amount:" << oldBalance
			  << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Withdraws a specified amount from the account.
// 1. Displays the current timestamp.
// 2. Stores the previous balance in 'oldBalance' before withdrawal.
// 3. Checks if the requested withdrawal exceeds the current balance:
//	- If it does, it outputs a message indicating the withdrawal is refused and returns false.
// 4. If the withdrawal is valid, it deducts the withdrawal amount from the current balance,
//	updates the number of withdrawals for this account and the total withdrawals,
//	and decreases the total amount in the bank.
// 5. Outputs the account index, previous balance, withdrawal amount, new balance,
//	and the number of withdrawals for the account.
// 6. Returns true to indicate a successful withdrawal.
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	int oldBalance = _amount; // Store previous amount
	if (withdrawal > _amount)
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << oldBalance
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex << ";p_amount:" << oldBalance
			  << ";withdrawal:" << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

// Check amount
int Account::checkAmount() const
{
	return _amount > 0;
}

// Display status
void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
