#include "widget.h"
#include "Burner.h"
#include <QPainter>
#include <QFrame>
#include <QHBoxLayout>
#include <QTextStream>

QString num[] = { "75", "150", "225", "300", "375", "450", "525", "600", "675" };
int asize = sizeof(num)/sizeof(num[1]);

Widget::Widget(QWidget *parent)
    : QFrame(parent)
{
    m_parent = parent;
    setFrameShape(QFrame::StyledPanel);
    setMinimumHeight(30);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QColor("#d4d4d4"));

    int width = size().width();

    Burner *burner = (Burner *) m_parent;
    int cur_width = burner->getCurrentWidth();

    int step = (int) qRound(width / 10.0);

    int till = (int) ((width / 750.0) * cur_width);
    int full = (int) ((width / 750.0) * 700);

    if (cur_width >= 700)
    {
        painter.setPen(QColor(255, 255, 184));
        painter.setBrush(QColor(255, 255, 184));
        painter.drawRect(0, 0, full, 30);
        painter.setPen(QColor(255, 175, 175));
        painter.setBrush(QColor(255, 175, 175));
        painter.drawRect(full, 0, till-full, 30);

    }
    else
    {
        painter.setPen(QColor(255, 255, 184));
        painter.setBrush(QColor(255, 255, 184));
        painter.drawRect(0, 0, till, 30);
    }

    painter.setPen(QColor(90, 80, 60));
    for (int i=1; i <= asize; i++)
    {
        painter.drawLine(i*step, 0, i*step, 6);
        QFont newFont = font();
        newFont.setPointSize(7);
        setFont(newFont);

        QFontMetrics metrics(font());

        int w = metrics.width(num[i-1]);
        painter.drawText(i*step-w/2, 19, num[i-1]);
    }

    QFrame::paintEvent(event);
}
