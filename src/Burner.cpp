#include "Burner.h"
#include <QApplication>
#include <QPainter>
#include <QVBoxLayout>
#include <QFrame>
#include <QPushButton>

Burner::Burner( QWidget *parent ) : QFrame( parent )
{
    slider = new QSlider(Qt::Horizontal, this);
    slider->setMaximum(750);
    slider->setGeometry(50, 50, 800, 120);
    this->setStyleSheet(QString::fromUtf8(
    "QSlider::groove:horizontal { border: 1px solid #999999; height: 8px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */ background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4) } QSlider::handle:horizontal { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f); border: 1px solid #5c5c5c; width: 18px; margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */ border-radius: 3px; }"));

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(valueChanged(int)));

    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout();

    vbox->addStretch(1);

    widget = new Widget(this);
    hbox->addWidget(widget, 0);

    vbox->addLayout(hbox);

    setLayout(vbox);
}

void Burner::valueChanged(int val)
{
    cur_width = val;
    widget->repaint();
}

int Burner::getCurrentWidth()
{
    return cur_width;
}

