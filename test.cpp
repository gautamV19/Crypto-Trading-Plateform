#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::string> tokens;
    std::string s = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869";

    tokens = tokenise(s, ',');

    for (std::string &t : tokens)
    {
        std::cout << t << std::endl;
    }
    return 0;
}