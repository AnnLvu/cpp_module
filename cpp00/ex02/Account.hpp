// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t; // Create a type alias for convenience

	// Static methods to get information about all accounts
	static int	getNbAccounts( void ); // Returns the number of accounts
	static int	getTotalAmount( void ); // Returns the total amount across all accounts
	static int	getNbDeposits( void ); // Returns the total number of deposits
	static int	getNbWithdrawals( void ); // Returns the total number of withdrawals
	static void	displayAccountsInfos( void ); // Displays information about all accounts

	// Constructor and destructor
	Account( int initial_deposit );
	~Account( void );

	// Methods for account operations
	void	makeDeposit( int deposit ); // Method to make a deposit
	bool	makeWithdrawal( int withdrawal ); // Method to withdraw funds
	int		checkAmount( void ) const; // Method to check the amount in the account
	void	displayStatus( void ) const; // Method to display the account status


private:

	// Static variables to hold information about all accounts
	static int	_nbAccounts; // Number of accounts
	static int	_totalAmount; // Total amount across all accounts
	static int	_totalNbDeposits; // Total number of deposits
	static int	_totalNbWithdrawals; // Total number of withdrawals

	// Private method to display a timestamp
	static void	_displayTimestamp( void );

	// Instance variables to hold information about a specific account
	int				_accountIndex; // Index of the account
	int				_amount; // Current amount in the account
	int				_nbDeposits; // Number of deposits in the account
	int				_nbWithdrawals; // Number of withdrawals from the account

	Account( void ); // Private constructor to prevent creating accounts without an initial deposit

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
