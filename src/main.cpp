#include <iostream>
#include <string>
#include "Model/DBInteractor.h"


int main()
{
    DBInteractor::getInstance()->InsertDefaultData("../data/data.sql");
}
