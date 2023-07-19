#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;

    signed int start, end = csvLine.size();
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    // std::cout << "Start: " << start << std::endl;

    do
    {
        end = csvLine.find_first_of(separator, start);
        // std::cout << "end: " << end << std::endl;

        if (start == csvLine.length() || start == end)
            break;

        if (end != 0)
            token = csvLine.substr(start, end - start);
        else
            token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);

        start = end + 1;

    } while (end > 0);

    return tokens;
}

int main()
{
    // std::vector<std::string> tokens;
    // std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

    // tokens = tokenise(s, ',');

    // for (std::string &t : tokens)
    // {
    //     std::cout << t << std::endl;
    // }

    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if (csvFile.is_open())
    {
        std::cout << "File Open" << std::endl;

        while (std::getline(csvFile, line))
        {
            std::cout << line << std::endl;
            tokens = tokenise(line, ',');
            if (tokens.size() != 5)
            {
                std::cout << "Bad line" << std::endl;
                continue;
            }
            // we have 5 tokens
            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);

                std::cout << price << ":" << amount << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "Bad float! " << tokens[3] << std::endl;
                std::cout << "Bad float! " << tokens[4] << std::endl;
                continue;
            }
        }
        csvFile.close();
    }
    else
    {
        std::cout << "Not Open" << std::endl;
    }
    return 0;
}