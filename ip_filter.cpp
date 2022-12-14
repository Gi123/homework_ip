#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream> // подключаем файлы

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));

        return r;
}
auto converStringToInt(std::vector<std::string> vectoS){
    std::vector<int> ints;
    std::transform(vectoS.begin(), vectoS.end(), std::back_inserter(ints),
        [&](std::string s) {
            return stoi(s);
        });
    return ints;
}
int main(int argc, char const *argv[])
{
    try
    {
        std::vector<std::vector<int>> ip_pool;
        //std::ifstream file("C:\\Project\\homework_ip\\ip_filter.tsv");
        for(std::string line; std::getline(std::cin, line);)
        //for(std::string line; std::getline(file, line);)
        {
            //if(line == "exit")
            //    break;
            std::vector<std::string> v = split(line, '\t');
            std::cout << v.at(0) << std::endl;

            ip_pool.push_back(converStringToInt(split(v.at(0), '.')));
        }
        std::sort(ip_pool.begin(), ip_pool.end(), 
            [](auto param1, auto param2) {
                return param1[0] == param2[0] ? param1[1] == param2[1]
                ? param1[2] == param2[2]
                ? param1[3] > param2[3]
                : param1[2] > param2[2]
                : param1[1] > param2[1]
                : param1[0] > param2[0];
            });
        auto tempVec = std::unique(ip_pool.begin(), ip_pool.end());
        ip_pool.erase(tempVec,ip_pool.end());

        // TODO reverse lexicographically sort
        //std::sort(ip_pool.cbegin(), ip_pool.cend(), myCmp);
        for(std::vector<std::vector<int> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            for(std::vector<int>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";
                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)
        std::for_each(ip_pool.begin(), ip_pool.end(),
            [](auto param) {
                if(param[0] == 1) {
                    for(int i = 0; i < param.size(); i++) {
                        std::cout << param[i];
                        if(i != param.size() - 1)
                            std::cout << ".";
                        else
                            std::cout << std::endl;
                    }
                }
            });
        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        std::for_each(ip_pool.begin(), ip_pool.end(),
            [](auto param) {
                if(param[0] == 46 && param[1] == 70) {
                    for(int i = 0; i < param.size(); i++) {
                        std::cout << param[i];
                        if(i != param.size() - 1)
                            std::cout << ".";
                        else
                            std::cout << std::endl;
                    }
                }
            });

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46

        std::for_each(ip_pool.begin(), ip_pool.end(),
            [](auto param) {
                if(param[0] == 46 || param[1] == 46 || param[2] == 46 || param[3] == 46) {
                    for(int i = 0; i < param.size(); i++) {
                        std::cout << param[i];
                        if(i != param.size() - 1)
                            std::cout << ".";
                        else
                            std::cout << std::endl;
                    }
                }
            });
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
