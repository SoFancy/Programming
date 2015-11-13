#include <iostream>
#include <vector>
#include <string>

void printBeer(int& beers) {
    std::string s = (beers == 1) ? " bottle " : " bottles ";

    std::cout << beers << s << "of beer on the wall,\n";
    std::cout << beers << s << "of beer!\n";
    std::cout << "Take one down, pass it around!\n";

    int next = *(&beers-1);
    s = (next == 1) ? " bottle " : " bottles ";

    std::cout << next << s << "of beer on the wall\n\n";
}

int main() {
    std::vector<int> bottles;

    // Fill it up backwards!
    for(int i = 0; i != 99; i++)
        bottles.push_back(i);

    std::vector<int>::reverse_iterator rit;
    for(rit=bottles.rbegin(); (rit+1)!=bottles.rend(); ++rit) {
        printBeer(*rit);
    }

    return 0;
}
