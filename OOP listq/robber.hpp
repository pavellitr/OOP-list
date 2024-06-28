#pragma once

#include "human.hpp"

class Beat
{
public: virtual void beet(Human& human) = 0;
};

class BeatKnife :public Beat {
public:
	void beet(Human& human) override {
		human.life = false;
		std::cout << "You was stabbed" << std::endl;
	}
};
class BeatShoot : public Beat {
public:
	void beet(Human& human) override {
		human.life = false;
		std::cout << "You was shooted" << std::endl;
	}
};

class BeetContext {
private:
	Beat* strategy;

public:
	void setStrategy(Beat* strategy)
	{
		this->strategy = strategy;
	}

	void executeStrategy(Human& human)
	{
		strategy->beet(human);
	}
};

class Robber
{
public:
	BeatKnife knife;
	BeatShoot shoot;
	BeetContext beet;
	Robber() { beet.setStrategy(&knife); };
	~Robber() {};

	void gopStop(Human& human) {
		int n, k;
		n = 10;
		k = 20;
		int l = rand() % (k - n + 1) + n;
		if (human.CoinTransaction(-l)) {
			for (int x = 0; x < l; x++) {
				Coin* coin = new Coin;
				coin->znach = 5;
				coins.PushBack(coin);
			}
		}
		else {
			beet.executeStrategy(human);
		}
	}
	void SwapBeet(std::string s) {
		if (s == "knife") {
			beet.setStrategy(&knife);
		}
		else {
			beet.setStrategy(&shoot);
		}
	}
private:
	List <Coin*> coins;
};