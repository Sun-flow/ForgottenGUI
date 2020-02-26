#include "xmlreader.h"

XMLReader::XMLReader(QObject *parent) : QObject(parent)
{

    QString path = qApp->applicationDirPath() + "/bin/XMLChar.xml";

    XMLFile = new QFile(path);

    if(XMLFile->open(QIODevice::ReadOnly)){
        if(domDoc.setContent(XMLFile)){
            QDomElement elem = domDoc.documentElement();
            //this->getData(elem);
        }
    }
}

XMLReader::XMLReader(Character *inChar)
{

    QString path = qApp->applicationDirPath() + "/bin/XMLChar.xml";

    XMLFile = new QFile(path);

    if(XMLFile->open(QIODevice::ReadOnly)){
        if(domDoc.setContent(XMLFile)){
            QDomElement elem = domDoc.documentElement();
            this->loadCharacter(elem, inChar);
        }
    }
}

void XMLReader::loadCharacter(const QDomNode &DNode, Character *character){
    QDomNode domNode = DNode.firstChild();
    while(!domNode.isNull()){
        if(domNode.isElement()){
            QDomElement domElement = domNode.toElement();
            if(domElement.tagName() == "Player"){
                character->setPlayerName(domElement.attribute("Name"));
            }
            else if(domElement.tagName() == "Char"){
                character->setCharName(domElement.attribute("Name"));
            }
            else if(domElement.tagName() == "Stats"){
                QDomNode statsNode = DNode.firstChildElement();
                QDomElement statsElement = statsNode.toElement();


                //!TODO: Maybe finish?????
                //Functions fine as is, but I like this structure better even if it's more complex
                //!Learning Opportunity!


                /*while(!statsElement.isNull()){
                    qDebug() << "Stats not null";
                    if(statsElement.tagName() == "Stat"){
                        qDebug() << "Stat found: " << statsElement.attribute("Name");
                        character->setStat(statsElement.attribute("Name").toInt(), statsElement.attribute("Val").toInt());
                    }
                    statsNode = statsElement.nextSibling();
                }*/
            }
            else if(domElement.tagName() == "Stat"){
                character->setStat(domElement.attribute("Name").toInt(), domElement.attribute("Val").toInt());
            }
            else if(domElement.tagName() == "Tendencies"){
            }
            else if(domElement.tagName() == "Tend"){
                character->addTend(domElement.attribute("Name"));
            }
            else if(domElement.tagName() == "Memory"){
                character->setMemories(domElement.text());
            }
            else{
                qDebug() << "You missed?" << domElement.tagName() << ": " << domElement.text();
            }
        }
        loadCharacter(domNode, character);
        domNode = domNode.nextSibling();
    }
}

void XMLReader::getData(const QDomNode &DNode){
    QDomNode domNode = DNode.firstChild();
    while(!domNode.isNull()){
        if(domNode.isElement()){
            QDomElement domElement = domNode.toElement();
            if(domElement.tagName() == "Char"){
                qDebug() << "Name: " << domElement.attribute("Name", "");
            }
            else if(domElement.tagName() == "Stats"){

            }
            else if(domElement.tagName() == "Stat"){
                qDebug() << domElement.attribute("Name", "") << ": " << domElement.attribute("Val", "");
            }
            else if(domElement.tagName() == "Tends"){
                qDebug() << "Tendencies:";
            }
            else if(domElement.tagName() == "Tend"){
                qDebug() << "\t" << domElement.attribute("Name", "");
            }
            else{
                qDebug() << "\t" << domElement.tagName() << ": " << domElement.text();
            }
        }
        getData(domNode);
        domNode = domNode.nextSibling();
    }
}
