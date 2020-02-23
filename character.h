#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

class Character : public QObject
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = nullptr);

    explicit Character(std::string inPlayerName, std::string inCharName, std::string inPronouns, std::vector< int >inStatArray);

signals:

private:
    std::string playerName;
    std::string charName;
    std::string charPronouns;

    int stats[6];

    struct nature{
        QString name;
        int value;
    };

    struct naturePairs{
        nature first;
        nature second;
    };

    naturePairs nature[7];

    void setPlayerName(std::string inName);

    void setCharName(std::string inName);

    void setStats(std::vector<int> inStats);

};

#endif // CHARACTER_H
