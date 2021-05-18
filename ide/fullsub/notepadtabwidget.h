#ifndef NOTEPADTABWIDGET_H
#define NOTEPADTABWIDGET_H

#include <QTabWidget>

class NotePadTabWidget : public QTabWidget
{
public:
    NotePadTabWidget(QWidget *parent);
    QSize sizeHint() const;
};

#endif // NOTEPADTABWIDGET_H
