#include "notepadtab.h"
#include <QDebug>
#include <QFileInfo>
#include <QVBoxLayout>

NotePadTab::NotePadTab(QWidget *parent) : QsciScintilla(parent)
{
    editorInit();

}

NotePadTab::~NotePadTab()
{
    delete apis;
}

QSize NotePadTab::sizeHint() const
{
    return QSize(200, 200); /* 在这里定义dock的初始大小 */
}

/* 编辑器初始化 */
void NotePadTab::editorInit(void)
{
    //设置显示字体
    QFont font("Courier New", 12, QFont::Normal);
    this->setMarginsFont(font);

    //设置左侧行号栏宽度等
    QFontMetrics fontMetrics = QFontMetrics(font);
    this->setMarginWidth(0, fontMetrics.width("00000"));
    this->setMarginLineNumbers(0, true);
    this->setBraceMatching(QsciScintilla::SloppyBraceMatch);

    //设置tab的宽度
    this->setTabWidth(4);

    //设置括号等自动补全
    this->setAutoIndent(true);

    //光标所在行背景色
    this->setCaretLineVisible(true);
    this->setCaretLineBackgroundColor(QColor(217, 235, 249));

    //设置默认换行符
    //this->setEolMode(QsciScintilla::EolUnix);

    //代码提示
    //设置C++解析器
    textLexer = new QsciLexerCPP(this);
    this->setLexer(textLexer);
    apis = new QsciAPIs(textLexer);
    apis->add(QString("import")); //添加可提示的单词
    apis->prepare();
    this->setAutoCompletionSource(QsciScintilla::AcsAll);   //设置源, 自动补全所有地方出现的
    this->setAutoCompletionCaseSensitivity(true);           //设置自动补全大小写敏感
    this->setAutoCompletionThreshold(1);                    //设置每输入1个字符就会出现自动补全的提示

}


/* 设置编辑状态 */
void NotePadTab::setEditStatus(bool status)
{
    this->isEditing = status;
}

/* 获取编辑状态 */
bool NotePadTab::getEditStatus(void)
{
    return this->isEditing;
}

/* 设置文件路径 */
void NotePadTab::setFilePath(QString filePath)
{
    this->filePath = filePath;

    //获取文件名
    QFileInfo info(filePath);
    this->fileName = info.fileName();
}

/* 获取文件路径 */
QString NotePadTab::getFilePath(void)
{
    return this->filePath;
}

/* 获取文件名称 */
QString NotePadTab::getFileName(void)
{
    return this->fileName;
}

/* 设置编码格式 */
void NotePadTab::setEncoding(QString encoding)
{
    this->enCoding = encoding;
    //设置编码方式
    if (this->enCoding == "utf-8") {
        this->SendScintilla(QsciScintilla::SCI_SETCODEPAGE, QsciScintilla::SC_CP_UTF8);
    } else {

        this->SendScintilla(QsciScintilla::SCI_SETCODEPAGE, 936);
        this->SendScintilla(QsciScintilla::SCI_STYLESETCHARACTERSET,  QsciScintilla::SC_CHARSET_GB2312);

//        qDebug() << this->SendScintilla(QsciScintilla::SCI_GETCODEPAGE);
//        qDebug() << this->SendScintilla(QsciScintilla::SCI_STYLEGETCHARACTERSET);
    }
}

/* 获取编码格式 */
QString NotePadTab::getEncoding(void)
{
    return this->enCoding;
}

/* 设置显示字体 */
void NotePadTab::setLexerFont(QFont font)
{
    this->font = font;
    textLexer->setFont(this->font);
}

/* 设置显示字体 */
QFont NotePadTab::getLexerFont(void)
{
    return this->font;
}

/* 文本内容改变时, 调用该槽发送signalContentHasChanged信号 */
void NotePadTab::slotContentChanged(void)
{
    this->isEditing = true;
    emit signalContentHasChanged(this);
}
