#include "Merchant.h"
Merchant::Merchant() : Card("Merchant") {}

void Merchant::applyEncounter(Player &player) {
//    printf("MerchantCard::applyEncounter\n");
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int choice = -1;
    int cost = 0;
    // ask player to choose a number between 0 and 2
    std::cin >> choice;
    while (choice < 0 || choice > 2) {
        printInvalidInput();
        std::cin >> choice;
    }

    switch (choice) {
        case 0:
//            cost = 0;
//            printMerchantSummary(std::cout, player.getName(), choice, cost);
            break;
        case 1:
            if(player.pay(5)){
                player.heal(1);
                cost = 5;
                printMerchantSummary(std::cout, player.getName(), choice, cost);
            }else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        case 2:
            if(player.pay(10)){
                player.buff(1);
                cost = 10;
                printMerchantSummary(std::cout, player.getName(), choice, cost);
            }else{
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        default:
            break;
    }



}
