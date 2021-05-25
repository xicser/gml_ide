#include "createprojectdialog.h"
#include "ui_createprojectdialog.h"

#include <QFileDialog>
#include <QWidgetAction>

CreateProjectDialog::CreateProjectDialog() :
    QWidget(nullptr),
    ui(new Ui::CreateProjectDialog)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(tr(":resource/notepad.png")));
    setWindowTitle("Create project...");
    setWindowFlags(this->windowFlags() &~ Qt::WindowMaximizeButtonHint);
    setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    //添加路径选择按钮
    QPushButton *choosePathBtn = new QPushButton(ui->proPathLineEdit);
    choosePathBtn->setText("...");
    choosePathBtn->setCursor(Qt::ArrowCursor);
    QWidgetAction *action = new QWidgetAction(ui->proPathLineEdit);
    action->setDefaultWidget(choosePathBtn);
    ui->proPathLineEdit->addAction(action, QLineEdit::TrailingPosition);

    connect(choosePathBtn, &QPushButton::clicked, this, &CreateProjectDialog::slotChoosePathBtnClicked);
    connect(ui->confirmBtn, &QPushButton::clicked, this, &CreateProjectDialog::slotConfirmBtnClicked);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &CreateProjectDialog::slotCancelBtnClicked);
}

CreateProjectDialog::~CreateProjectDialog()
{
    delete ui;
}

/* 获取工程文件路径 */
QString CreateProjectDialog::getProjectFilePath(void)
{
    return this->proPath;
}

/* 获取工程文件名称 */
QString CreateProjectDialog::getProjectFileName(void)
{
    return this->proName;
}

/* 选择路径按钮按下 */
void CreateProjectDialog::slotChoosePathBtnClicked()
{
    QString gproPath = QFileDialog::getExistingDirectory(this, "Select path...", ".");
    if (gproPath.isEmpty() == false) {
        ui->proPathLineEdit->setText(gproPath);
    }
}

/* 确定按钮按下 */
void CreateProjectDialog::slotConfirmBtnClicked()
{
    this->proName = ui->proNameLineEdit->text();
    this->proPath = ui->proPathLineEdit->text();
    this->hide();
    emit signalConfirmBtnClicked();
}

/* 取消按钮按下 */
void CreateProjectDialog::slotCancelBtnClicked()
{
    this->proName.clear();
    this->proPath.clear();
    this->hide();
}
