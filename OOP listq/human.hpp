#pragma once
#include "coin.hpp"
#include "list.hpp"
#include "iostream"

class Human
{
public:
	Human() {};
	~Human() {};
	bool CoinTransaction(int num) {
		if (-num > coins.crutch) { return false; }
		if (num > 0) {
			for (int x = 0; x < num; x++) {
				Coin* coin = new Coin;
				coin->znach = 5;
				coins.PushBack(coin);
			}
		}
		else {
			for (int x = 0; x > num; x--) {
				coins.popBack();
			}
		}
		return true;
	}
	bool life = true;
	void PrintCoins() {
		std::cout << coins.crutch << std::endl;
	}
private:
	List <Coin*> coins;
};