#include "glwidget.h"
#include "helper.h"

#include <QPainter>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Simple_cartesian.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef CGAL::Simple_cartesian<double> SKernel;

GLWidget::GLWidget(Helper *helper, QWidget *parent)
    : QOpenGLWidget(parent), helper(helper)
{
    setFixedSize(600, 600);
    setAutoFillBackground(false);
}

void GLWidget::animate()
{
    update();
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    typedef Kernel::Point_2 Point;
    Point p(12., 12.);
    Point q(24.0, 24.0);
    Point r(.5, .5);
    double dx = 1e-15;
    const int N = 100;
    painter.setPen(Qt::NoPen);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double x = dx*(i - N / 2);
            double y = dx*(j - N / 2);
            Point a(r.x() + x, r.y() + y);
            switch (CGAL::orientation(a, p, q)) {
            case CGAL::LEFT_TURN:
                painter.setBrush(Qt::blue);
                break;
            case CGAL::RIGHT_TURN:
                painter.setBrush(Qt::red);
                break;
            case CGAL::COLLINEAR:
                painter.setBrush(Qt::yellow);
                break;
            }
            painter.drawRect(i * 6, j * 6, 6, 6);
        }
    }
    painter.end();
}
