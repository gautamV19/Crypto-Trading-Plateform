#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    loadOrderBook();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUseroption(input);
    }
}

void MerkelMain::loadOrderBook()
{

    orders.push_back({1000, 0.002705, "time", "pdt", OrderBookType::bid});
    orders.push_back({2000, 0.002705, "time", "pdt", OrderBookType::ask});

    // for (OrderBookEntry &order : orders)
    // {
    //     std::cout << "Price is " << order.price << std::endl;
    // }

    // for (unsigned int i = 0; i < orders.size(); ++i)
    // {
    //     std::cout << "Price is " << orders[i].price << std::endl;
    // }

    // for (unsigned int i = 0; i < orders.size(); ++i)
    // {
    //     std::cout << "Price is " << orders.at(i).price << std::endl;
    // }
}

void MerkelMain::printMenu()
{
    /**
     * print help
     * print exchange stats
     * make an offer
     * make a bid
     * print wallet
     * continue
     */

    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Make an offer" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;

    std::cout << "===========" << std::endl;
}

int MerkelMain::getUserOption()
{
    std::cout << "Type in 1-6" << std::endl;

    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;

    return userOption;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}
void MerkelMain::printMarketStats()
{

    std::cout << "Orderbook Contains :" << orders.size() << " entries." << std::endl;
}
void MerkelMain::enterOffer()
{
    std::cout << "Make an offer - enter the amount" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}
void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty." << std::endl;
}
void MerkelMain::nextTimeFrame()
{
    std::cout << "Going to next time frame." << std::endl;
}
void MerkelMain::processUseroption(int userOption)
{
    if (userOption == 0)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterOffer();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        nextTimeFrame();
    }
}