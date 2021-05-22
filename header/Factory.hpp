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
#include <cmath>

using namespace std;

class Factory {
    public:
        Factory(){}
        Base* parse(char** input, int length){
            if (length <= 1 || length % 2 != 0){    //If the length of the arg is odd then we want to output an error msg
                cout << "ERORR: Invalid input" << endl;
                return nullptr;
            }

            stack<Base*> OperandStack;              //make two seperate stacks, one for operands and one for operators
            stack<string> OperatorStack;
            double temp;
            
            for(int i = length -1 ; i >= 1; i--){
                if(isdigit(*input[i])){             //Checks if the string is a digit value at i
                temp = stod(input[i]);
                OperandStack.push(new Op(temp));    //Push that num to the operand stack
                }

                else {
                    OperatorStack.push(input[i]);   //else push the operator to the operator stack
                }
            }
        }
};

#endif