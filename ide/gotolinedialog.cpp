#include "gotolinedialog.h"
#include "ui_gotolinedialog.h"

GoToLineDialog::GoToLineDialog(QWidget *parent) :
    QWidget(parent), ui(new Ui::GoToLineDialog)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(tr(":images/notepad.png")));
    setWindowTitle(tr("Goto Line"));
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(gotoLine()));
}

//设置行号最大范围
void GoToLineDialog::setMaxLineNumber(int lineNumber)
{
    ui->spinBox->setMaximum(lineNumber);
}

//转到行
void GoToLineDialog::gotoLine()
{
    int lineNumber = ui->spinBox->value();
    emit gotoLine(lineNumber);
}

GoToLineDialog::~GoToLineDialog()
{
    delete ui;
}
