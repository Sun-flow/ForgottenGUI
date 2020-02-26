#ifndef XMLREADER_H
#define XMLREADER_H

#include <QObject>
#include <QtXml/QtXml>
#include <QtXml/QXmlSimpleReader>
#include <QtXml/QXmlDefaultHandler>
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include "character.h"

class XMLReader : public QObject
{
    Q_OBJECT
public:
    explicit XMLReader(QObject *parent = nullptr);

    explicit XMLReader(Character *inChar);

    void getData(const QDomNode &DNode);

    void loadCharacter(const QDomNode &DNode, Character *character);

signals:

private:

     QXmlSimpleReader xmlReader;

     QDomDocument domDoc;
     QFile *XMLFile;

};

#endif // XMLREADER_H
