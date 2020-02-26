#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QString>
#include <QDebug>

class Character : public QObject
{
    Q_OBJECT
public:

    enum StatNames {Str, Dex, Int, Wis, Con};

    explicit Character(QObject *parent = nullptr);

    explicit Character(QString inPlayerName, QString inCharName, QString inPronouns, std::vector< int >inStatArray);

    void setPlayerName(QString inName);

    void setCharName(QString inName);

    void setStats(std::vector<int> inStats);

    void setStat(int whichStat, int statVal);

    void addTend(QString inTend);

    void printCharInfo();
    void printPlayerName();
    void printCharName();
    void printStats();
    void printTends();

    QString getMemories();
    void setMemories(QString inMem);

signals:

private:
    QString playerName;
    QString charName;
    QString charPronouns;
    std::vector< QString > charTendencies;
    QString charMemories;

    int stats[5];

    struct nature{
        QString name;
        int value;
    };

    struct naturePairs{
        nature first;
        nature second;
    };

    naturePairs nature[7];
};

#endif // CHARACTER_H
