#include <iostream>
#include <vector>
#include <string>

// Print the lyrics
void printLyricsAt(int& beers) {
    // Bottle or bottles?
    std::string s = (beers == 1) ? " bottle " : " bottles ";

    std::cout << beers << s << "of beer on the wall,\n";
    std::cout << beers << s << "of beer!\n";
    std::cout << "Take one down, pass it around!\n";

    // The next bottle, of course
    int next = *(&beers-1);
    s = (next == 1) ? " bottle " : " bottles ";

    std::cout << next << s << "of beer on the wall!\n\n";
}

int main() {
    std::vector<int> bottles;

    // Fill em up
    for(int i = 0; i <= 99; ++i)
        bottles.push_back(i);

    // Iterate through all the bottles
    std::vector<int>::reverse_iterator rit;
    for(rit=bottles.rbegin(); (rit+1)!=bottles.rend(); ++rit) {
        printLyricsAt(*rit);
    }

    return 0;
}
