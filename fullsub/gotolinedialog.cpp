#include "gotolinedialog.h"
#include "ui_gotolinedialog.h"
#include <QDebug>

GotolineDialog::GotolineDialog(NotePadTab *notePadTabActive) :
    QWidget(nullptr), ui(new Ui::GotolineDialog), notePadTabActive(notePadTabActive)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(tr(":resource/notepad.png")));
    setWindowTitle(tr("Go To Line..."));
    setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);
    setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    connect(ui->goBtn, &QPushButton::clicked, this, &GotolineDialog::slotGoBtnClicked);
}

GotolineDialog::~GotolineDialog()
{
    delete ui;
}

/* go按钮按下 */
void GotolineDialog::slotGoBtnClicked()
{
    int lineMax = notePadTabActive->lines();
    int lineToGo = ui->lineSpinBox->value();

    if (lineToGo < 1) {
        return;
    }

    if (lineToGo > lineMax) {
        notePadTabActive->setCursorPosition(lineMax - 1, 0);
    } else {
        notePadTabActive->setCursorPosition(lineToGo - 1, 0);
    }

    emit signalGoToLineDone();
}
