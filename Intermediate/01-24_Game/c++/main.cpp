#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <typeinfo>

const std::string validOps = "/*+-";
const std::string validNums = "0123456789";

/* 
 * Verify that the equation follows our rules
 */
bool verify(std::string& eq, const std::vector<int>& given) {
    // Remove all spaces before verification
    eq.erase(std::remove(eq.begin(), eq.end(), ' '), eq.end());

    // Rules:
    // 1. Expression must contain only the allowed characters (validOps and validNums)
    // 2. Expression must contain only the given numbers
    // 3. Expression must contain only single digit numbers

    return true;
}

/* 
 * Evaluates the value of an expression, made to be fairly "general purpose",
 * but relies on the validNums and validOps given by the program.
 * (Lacks support for brackets)
 */ 
float eval(std::string& eq) {
    std::vector<std::string> split;

    // Iterate through the whole string, seperating the equation
    // into a string vector
    std::string builder;
    std::string::const_iterator ci;
    for(ci=eq.begin(); ci!=eq.end()+1; ci++) {
        // Current char is a number
        if (validNums.find(*ci) != std::string::npos)
            builder += *ci;
        // Current char is an operator
        else {  
            split.push_back(builder);
            if (validOps.find(*ci) != std::string::npos) { 
                split.push_back(std::string(1, *ci));
                builder = "";
            }
        } 
    }

    // Iterate through each operator (so they're done in the right order)
    std::string::const_iterator s_it;
    std::vector<std::string>::iterator v_it;
    for (s_it=validOps.begin(); s_it!=validOps.end(); ++s_it) {
        // Iterate through the split string, find the current operator
        std::string op(1,*s_it);
        for (v_it=split.begin(); v_it!=split.end(); ++v_it) { 
            // If the operators match
            if (*v_it == op) {
                // Grab the right values (as float) 
                float x, y, result;
                x = std::stof(*(v_it - 1));
                y = std::stof(*(v_it + 1)); 

                // Check the operator and calculate a result
                switch(*s_it) {
                    case '/': 
                        result = x / y;
                        break;
                    case '*': 
                        result = x * y;
                        break;
                    case '+': 
                        result = x + y;
                        break;
                    case '-': 
                        result = x - y;
                        break;
                    default:
                        throw 1;
                } 

                // Insert the result where the first value was stored
                split.insert(v_it-1, std::to_string(result));

                // Erase the 3 strings we used for the operation,
                // effectively replacing them with the result
                split.erase(v_it, v_it+3);
                
                // Make sure the iterator points to the result.
                // The program may have reached the end of the vector, and then
                // the pointer would end up pointing outside the vector bounds
                v_it = v_it-1;
            }
        }
    }

    // The final result is the only value remaining
    float fin;
    fin = std::stof(split[0]); 

    return fin;
}

int main() {
    std::string test = "10.5*2";
    //bool ver =      verify(test);
    float result =  eval(test);
/*
    if (ver) {
        std::cout << test << " = " << result << std::endl;
    } else {
        std::cout << "could not verify string" << std::endl;
    }*/
}
