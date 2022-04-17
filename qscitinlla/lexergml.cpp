#include "lexergml.h"

LexerGML::LexerGML(QObject *parent) : QsciLexerCPP(parent)
{

}

/* 重写keywords, 加入自己的关键字 */
const char *LexerGML::keywords(int set) const
{
    if (set == 2) {
        return "self str";
    }

    return QsciLexerCPP::keywords(set);
}
