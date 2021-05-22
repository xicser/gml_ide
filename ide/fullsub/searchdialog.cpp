#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QDebug>

SearchDialog::SearchDialog(NotePadTab *notePadTabActive) :
    QWidget(nullptr), ui(new Ui::SearchDialog), notePadTabActive(notePadTabActive)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(tr(":resource/notepad.png")));
    setWindowTitle(tr("Find"));
    setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);

    ui->findCombo->setCurrentIndex(-1);
    ui->replaceCombo->setCurrentIndex(-1);

    connect(ui->findNextButton, &QToolButton::clicked, this, &SearchDialog::slotSearchForward);
    connect(ui->findPreviousButton, &QToolButton::clicked, this, &SearchDialog::slotSearchBackward);
    connect(ui->replaceBtn, &QToolButton::clicked, this, &SearchDialog::slotReplace);
    connect(ui->replaceAllBtn, &QToolButton::clicked, this, &SearchDialog::slotReplaceAll);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

//向前查找
void SearchDialog::slotSearchForward()
{
    QString textToSearch = ui->findCombo->currentText();
    bool regularExp, caseSensitive, matchWholeWord, wrap;
    regularExp = ui->regExpCheck->isChecked();
    caseSensitive = ui->matchCaseCheck->isChecked();
    matchWholeWord = ui->matchWholeWordCheck->isChecked();
    wrap = ui->wrapAroundCheck->isChecked();
    bool forward;
    if (ui->forwardRBtn->isChecked() == true) {
        forward = true;
    } else {
        forward = false;
    }
    int line, index;
    notePadTabActive->getCursorPosition(&line, &index);
    notePadTabActive->findFirst(textToSearch, regularExp, caseSensitive, matchWholeWord, wrap, forward, line, index, true, false);
}

//向后查找
void SearchDialog::slotSearchBackward()
{
    QString textToSearch = ui->findCombo->currentText();
    bool regularExp, caseSensitive, matchWholeWord, wrap;
    regularExp = ui->regExpCheck->isChecked();
    caseSensitive = ui->matchCaseCheck->isChecked();
    matchWholeWord = ui->matchWholeWordCheck->isChecked();
    wrap = ui->wrapAroundCheck->isChecked();
    bool forward;
    if (ui->forwardRBtn->isChecked() == true) {
        forward = false;
    } else {
        forward = true;
    }
    int line, index;
    notePadTabActive->getCursorPosition(&line, &index);
    notePadTabActive->findFirst(textToSearch, regularExp, caseSensitive, matchWholeWord, wrap, forward, line, index, true, false);
}

/* 替换 */
void SearchDialog::slotReplace()
{

}

/* 替换所有 */
void SearchDialog::slotReplaceAll()
{

}
