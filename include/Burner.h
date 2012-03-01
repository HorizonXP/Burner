#ifndef BURNER_H
#define BURNER_H

#include <QWidget>
#include <QSlider>
#include "widget.h"

class Burner : public QFrame
{
    Q_OBJECT

    public:
        Burner( QWidget *parent = 0 );

    public slots:
        void valueChanged(int);
        int getCurrentWidth();

    private:
        QSlider *slider;
        Widget *widget;
        int cur_width;
};

#endif
