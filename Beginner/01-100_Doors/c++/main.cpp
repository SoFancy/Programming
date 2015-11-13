#include <iostream>
#include <algorithm>

int main() {
    // Fill an array with 100 closed doors (false)
    bool doors[100];
    std::fill_n(doors, 100, false); 
    
    // For every multiplier
    for(int i = 1; i < 100; i++) {
        // Toggle every i'th door
        for(int j = i; j < 100; j += i) {
            doors[j] = !doors[j];
        }
    }

    // Print which doors are open
    for(int i = 0; i < sizeof(doors); i++) {
        if (doors[i]) {
            std::cout << "Door " << i << " open." << std::endl;
        }
    }

    return 0;
}
