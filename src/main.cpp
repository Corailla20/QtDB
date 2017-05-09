#include <iostream>
#include <string>
#include "Model/DBIntecractor.h"

int main() {

    DBIntecractor::getInstance()->InsertDefaultData("../data/data.sql");


}
