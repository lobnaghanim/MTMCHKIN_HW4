#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Mtmchkin.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Exception.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>


using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;

void createTextFile(const string &filename, const string &input)
{
    std::ofstream file(filename);
    if(file){
        file << input;
    }
}

void deleteTextFile(const string &filename)
{
    std::remove(filename.c_str());
}

bool compareFiles(const string &filename1, const string &filename2)
{
    string line1,line2;
    fstream file1(filename1),file2(filename2);
    if( !file2){
        cerr<<"Error opening file 2"<<std::endl;
        return false;
    }
    if(!file1 ){
        cerr<<"Error opening file 1"<<std::endl;
        return false;
    }
    while(!file1.eof()){ //read file until you reach the end
        getline(file1,line1);
        getline(file2,line2);
        if(!(line1==line2))
        {
            return false;
        }
    }
    if(!file2.eof()){
        return false;
    }
    return true;
}

bool GeneralGameSimulationTest(const string &tempDeckFilename, string input, string deck, string expectedOutputFileName)
{
    //   init cin from file
    createTextFile(tempDeckFilename+".txt",deck);
    istringstream in(input);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());
    std::ofstream outfile(tempDeckFilename+"out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(outfile.rdbuf());
    Mtmchkin game(tempDeckFilename+".txt");
    while(!game.isGameOver() && game.getNumberOfRounds() < 100){
        game.playRound();
        game.printLeaderBoard();
    }

    bool res = compareFiles(tempDeckFilename+"out.txt", expectedOutputFileName);
    outfile.close();
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    deleteTextFile(tempDeckFilename+".txt");
    return res;
}

void run_test(std::function<bool()> test, std::string test_name)
{
    if(!test()){
        std::cout<< test_name <<" FAILED."<<std::endl;
        std::cout << std::endl;
        return;
    }
    std::cout<<test_name<<" SUCCEEDED."<<std::endl;
    std::cout << std::endl;

}
bool dragonDenTest()
{
    const string tmp_file("dragonDen_test");
    string input("2\nJimmy Healer\nPikachu Warrior");
    string deck("Dragon\nDragon\nDragon\nDragon\nDragon");
    string expectedOutputFilename("tests/dragonDen_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}
bool gremlinCaveTest()
{
    const string tmp_file("gremlinCave_test");
    string input("2\nItay Healer\nPikachu Ninja");
    string deck("Gremlin\nGremlin\nGremlin\nGremlin\nGremlin");
    string expectedOutputFilename("tests/gremlinCave_test_expected.txt");
    return GeneralGameSimulationTest(tmp_file, input, deck, expectedOutputFilename);
}
int main() {
    run_test(gremlinCaveTest,"Gremlin Cave simulation test");
    run_test(dragonDenTest,"Dragon Den simulation test");

    return 0;
}