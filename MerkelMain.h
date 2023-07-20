#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
public:
    MerkelMain();
    /** call this to start the sim*/
    void init();

private:
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterOffer();
    void enterBid();
    void printWallet();
    void nextTimeFrame();
    int getUserOption();
    void processUseroption(int userOption);

    OrderBook orderBook{"20200317.csv"};
};