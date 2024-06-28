#pragma once


#include "robber.hpp"


class Bank
{
public:
	Bank();
	~Bank();
	bool giveCredit(int n, Human& human) {
		if (human.CoinTransaction(n) == true) {
			for (int x = 0; x < n; x++) {
				coins.popBack();
			}
		}
		else {
			std::cout << "You died" << std::endl;
			human.life = false;
		}
		return true;
	}
	bool bringCredit(int n, Human& human) {
		if (human.CoinTransaction(-n)) {
			for (int x = 0; x < n; x++) {
				Coin* coin = new Coin;
				coin->znach = 5;
				coins.PushBack(coin);
			}
		}
	}

private:
	List <Coin*> coins;
};

Bank::Bank()
{
	for (int x = 0; x < 10000; x++) {
		Coin* coin = new Coin;
		coin->znach = 5;
		coins.PushBack(coin);
	}
}

Bank::~Bank()
{
}