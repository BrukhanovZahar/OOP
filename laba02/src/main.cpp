#include "../include/five_array.h"
#include <iostream>

int main() {
    try {
        Five five1;
        std::cout << "five1: " << five1 << std::endl;

        Five five2(5, '4');
        std::cout << "five2: " << five2 << std::endl;

        Five five3(4);
        std::cout << "five3: " << five3 << std::endl;

        Five five4 = {'2', '3', '1'};
        std::cout << "five4: " << five4 << std::endl;

        Five five5("33331");
        std::cout << "five5: " << five5 << std::endl;

        Five five6 = five2;
        std::cout << "five6: " << five6 << std::endl;

        Five five7 = std::move(five3);
        std::cout << "five7: " << five7 << std::endl;

        Five five8 = five7 + five2;
        std::cout << "Five8 (Five7 + Five2): " << five8 << std::endl;

        Five five9 = five2 + five7;
        std::cout << "Five9 (Five2 + Five7): " << five9 << std::endl;

        Five five10 = five7 + five7;
        std::cout << "Five10 (Five7 + Five7): " << five10 << std::endl;

        Five five11 = five2 - five7;
        std::cout << "Five11 (Five2 - Five7): " << five11 << std::endl;

        Five five12 = five2 - five5;
        std::cout << "Five12 (Five2 - Five5): " << five12 << std::endl;

        std::cout << (five5 > five6) << std::endl;
        std::cout << (five5 < five6) << std::endl;
        std::cout << (five5 == five6) << std::endl;
        std::cout << (five5 == five5) << std::endl;

        five5.serialize("test.txt");
        std::cout << "five5: " << five5 << std::endl;

        five1.deserialize("test.txt");
        std::cout << "five1: " << five1 << std::endl;

        Five five13 = Five::createBuilder().size(2).build();
        std::cout << "five13: " << five13 << std::endl;

        Five five14 = Five::createBuilder().size(3).addValue('2').build();
        std::cout << "five14: " << five14 << std::endl;

        Five::Builder builder;
        Five five15 = builder.size(4).addValue('1').addValue('2').addValue('3').addValue('4').build();
        std::cout << "five15: " << five15 << std::endl;

    } catch (std::exception &ex) {
        std::cerr << "exception:" << ex.what() << std::endl;
    }
    return 0;
}