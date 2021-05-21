#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "../header/Add.hpp"
#include "../header/base.hpp"
#include "../header/Div.hpp"
#include "../header/Mult.hpp"
#include "../header/op.hpp"
#include "../header/Pow.hpp"
#include "../header/Sub.hpp"
#include "../header/Random.hpp"

#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>

using namespace std;

class Factory {
    public:
        Factory(){}
        Base* parse(char** input, int length){
            if (length <= 1 || length % 2 != 0){
                return nullptr;
            }
};

#endif