#include "character.h"

Character::Character(QObject *parent) : QObject(parent)
{
    setPlayerName("");
    setCharName("");
    setStats({0,0,0,0,0,0});
}

Character::Character(std::string inPlayerName, std::string inCharName, std::string inPronouns, std::vector< int >inStatsArray){
    setPlayerName(inPlayerName);
    setCharName(inCharName);
    charPronouns = inPronouns;
    setStats(inStatsArray);
    //constructPairs();
}

void Character::setPlayerName(std::string inName){
    playerName = inName;
}

void Character::setCharName(std::string inName){
    charName = inName;
}

void Character::setStats(std::vector< int > inStats){
    int i = 0;
    while(!inStats.empty()){ //use array size later
        stats[i] = inStats.back();
        inStats.pop_back();
        i++;
    }
}
