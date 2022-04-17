#ifndef LEXERGML_H
#define LEXERGML_H

#include <QObject>
#include <Qsci/qscilexercpp.h>

class LexerGML : public QsciLexerCPP
{
public:
    LexerGML(QObject *parent);

    //重写keywords, 加入自己的关键字
    const char *keywords(int set) const;
};

#endif // LEXERGML_H
