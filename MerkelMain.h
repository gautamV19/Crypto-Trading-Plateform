#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
public:
    MerkelMain();
    /** call this to start the sim*/
    void init();

private:
    void loadOrderBook();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void nextTimeFrame();
    int getUserOption();
    void processUseroption(int userOption);

    std::vector<OrderBookEntry> orders;
};