#include <iostream>
#include <string>
#include <vector>

#include "OrderBookEntry.h"

int main()
{

    // double price = 2576.5858;
    // double amount = 0.0002705;
    // std::string timestamp{};
    // std::string product{};
    // orderBookType orderBook = orderBookType::ask;

    std::vector<OrderBookEntry> orders;
    // std::vector<double> amounts;
    // std::vector<std::string> timestamps;
    // std::vector<std::string> products;
    // std::vector<OrderBookType> orderTypes;

    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUseroption(userOption);
    // }

    // OrderBookEntry order1{1000, 0.002705, "time", "pdt", OrderBookType::bid};

    orders.push_back({1000, 0.002705, "time", "pdt", OrderBookType::bid});
    orders.push_back({2000, 0.002705, "time", "pdt", OrderBookType::ask});

    for (OrderBookEntry &order : orders)
    {
        std::cout << "Price is " << order.price << std::endl;
    }

    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "Price is " << orders[i].price << std::endl;
    }

    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "Price is " << orders.at(i).price << std::endl;
    }

    return 0;
}