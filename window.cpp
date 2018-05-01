#include "glwidget.h"
#include "window.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

Window::Window()
{
    setWindowTitle(tr("2D Painting on OpenGL Widgets"));
    GLWidget *openGL = new GLWidget(&helper, this);
    QLabel *openGLLabel = new QLabel(tr("OpenGL"));
    openGLLabel->setAlignment(Qt::AlignHCenter);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(openGL, 0, 1);
    layout->addWidget(openGLLabel, 1, 1);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, openGL, &GLWidget::animate);
    timer->start(50);
}
