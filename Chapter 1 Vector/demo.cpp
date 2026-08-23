#include <iostream>
#include <vector>

// using namespace std;

class myV {
    private:
    int mySize;
    int myNumber;

    public:
    myV(int size, int number):mySize(size), myNumber(number) {}

    void info() {
        std::cout << "I have " << mySize << " " << myNumber << " stored." << std::endl;
    }
};

int main() {
    std::vector<char> characters = {'a', 'b', 'c', 'd'};

    int i = 3;

    try {
        std::cout << characters.at(i);
    } catch(std::out_of_range) {
        std::cout << "Index: " << i << " is out of boundary." << std::endl;
    }

    

    // std::vector<int> hundreds(8, 100);

    // for(int e: hundreds) {
    //     std::cout << e << ", ";
    // }

    // std::cout << std::endl;

    // // myV myHundreds(8, 100);
    // // myHundreds.info();


    // hundreds.begin();
    

}

