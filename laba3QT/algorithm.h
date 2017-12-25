#pragma once

#include <string>
#include <vector>

class algorithm {
public:
    algorithm() = default;
    ~algorithm() = default;
    //
    std::string Execute(std::string aLine);
    std::string CheckData(std::string aLine);
private:
    int n_;
    std::string line_;
    std::string result_;
};
