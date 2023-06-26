#include "Merchant.h"
Merchant::Merchant() : Card("Merchant") {}

bool isANumber(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}

void Merchant::applyEncounter(Player &player) {
//    printf("MerchantCard::applyEncounter\n");
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    
    string input;
    std::getline(std::cin, input);
    
    while(!isANumber(input) || stoi(input) < 0 || stoi(input) > 2){
        printInvalidInput();
        std::getline(std::cin, input);
    }
    
    int choice = stoi(input);
    int cost = 0;



    switch (choice) {
        case 0:
            cost = 0;
            printMerchantSummary(std::cout, player.getName(), choice, cost);
            break;
        case 1:
            if(player.pay(5)){
                player.heal(1);
                cost = 5;
                printMerchantSummary(std::cout, player.getName(), choice, cost);
            }else{
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), choice, 0);
            }
            break;
        case 2:
            if(player.pay(10)){
                player.buff(1);
                cost = 10;
                printMerchantSummary(std::cout, player.getName(), choice, cost);
            }else{
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), choice, 0);
            }
            break;
        default:
            break;
    }



}

void Merchant::print(ostream &os) const {
    return; // do nothing
}
