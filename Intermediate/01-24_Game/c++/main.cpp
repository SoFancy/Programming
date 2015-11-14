#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

std::string ops = "+-/*";
std::string allowed = "0123456789";

float eval(std::string eq) {
    std::vector<int>    numbers;
    std::vector<char>   operators;

    // Loop through the whole string
    std::string::const_iterator ci;
    for(ci=eq.begin(); ci!=eq.end(); ci++) {
        if(allowed.find(*ci) == std::string::npos) {
            // If we find an operator, push it to the operators vector
            // Otherwise, it's not an allowed character, so an exception is thrown.
            if(ops.find(*ci) == std::string::npos) 
                throw 1;
            else {
                operators.push_back(*ci);      
            }
        }
        else {
            
        }
    }
    return 0.0f;
}

int main() {
    
}
