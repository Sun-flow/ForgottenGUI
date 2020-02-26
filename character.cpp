#include "character.h"

Character::Character(QObject *parent) : QObject(parent)
{
    setPlayerName("");
    setCharName("");
    setStats({0,0,0,0,0});
}

Character::Character(QString inPlayerName, QString inCharName, QString inPronouns, std::vector< int >inStatsArray){
    setPlayerName(inPlayerName);
    setCharName(inCharName);
    charPronouns = inPronouns;
    setStats(inStatsArray);
    //constructPairs();
}

void Character::setPlayerName(QString inName){
    playerName = inName;
}

void Character::setCharName(QString inName){
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

void Character::setStat(int whichStat, int statVal){
    stats[whichStat] = statVal;
}

void Character::addTend(QString inTend){
    charTendencies.push_back(inTend);
}

void Character::printCharInfo(){
    printPlayerName();
    printCharName();
    printStats();
    printTends();
}

void Character::printPlayerName(){
    qDebug() << "Player Name: " << playerName;
}

void Character::printCharName(){
    qDebug() << "Character Name: " << charName;

}

void Character::printStats(){
    qDebug() << "--------Stats--------";
    qDebug() << "| Str:          " << stats[0] << " |";
    qDebug() << "| Dex:          " << stats[1] << " |";
    qDebug() << "| Int:          " << stats[2] << " |";
    qDebug() << "| Wis:          " << stats[3] << " |";
    qDebug() << "| Con:          " << stats[4] << " |";
    qDebug() << "---------------------";
}

void Character::printTends(){
    qDebug() << "Tendencies:";
    for(QString tend : charTendencies){
        qDebug() << tend;
    }
}

QString Character::getMemories(){
    return charMemories;
}

void Character::setMemories(QString inMem){
    charMemories = inMem;
}
