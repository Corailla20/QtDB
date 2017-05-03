#include <iostream>
#include <string>
#include "Model/DBIntecractor.h"

int main() {

    DBIntecractor::getInstance()->InsertDefaultData("../data/data.sql");

    if (!DBInteractor::getInstance()) {
        std::cout << "error" << std::endl;
        return 1;
    }
    else {
        std::cout << "ok" << std::endl;
       return 0;
    }
}
