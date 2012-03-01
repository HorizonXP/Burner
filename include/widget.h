#ifndef WIDGET_H
#define WIDGET_H

class Burner;

#include <QFrame>

class Widget : public QFrame
{
    Q_OBJECT

    public:
        Widget(QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent *event);

    public:
        QWidget *m_parent;
        Burner *snap;

};

#endif
