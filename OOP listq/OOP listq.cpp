#include "Bank.hpp"
#include "robber.hpp"

int main()
{
    Bank bank;
    Human human, human1;
    Robber rob;
    bank.giveCredit(1, human);
    human.PrintCoins();
    rob.gopStop(human);
    bank.giveCredit(1, human1);
    human1.PrintCoins();
    rob.SwapBeet("shoot");
    rob.gopStop(human1);

   
}