#include "universalchart.h"

UniversalChart::UniversalChart(QQuickItem *parent) : QNanoQuickItem(parent)
{
    setMouseEventsEnabled(true);
    setMouseHoverEventsEnabled(true);

    timer->setInterval(16);
    timer->start();
}

QNanoQuickItemPainter *UniversalChart::createItemPainter() const
{
    UniversalChartPainter* nanoPainter = new UniversalChartPainter();

    const_cast<UniversalChart*>(this)->_universalChartPainter = nanoPainter;
    const_cast<UniversalChart*>(this)->_painter.setPainter(_universalChartPainter->painter());
    const_cast<UniversalChart*>(this)->setInitialized(true);

    QObject::connect(timer.get(), &QTimer::timeout, [&]()
    {
        _universalChartPainter->refresh();
        const_cast<UniversalChart*>(this)->draw();
    });

    return nanoPainter;
}

qint32 UniversalChart::plotAreaLeftMargin() const
{
    return _plotAreaLeftMargin;
}
void UniversalChart::setPlotAreaLeftMargin(qint32 newPlotAreaLeftMargin)
{
    if (_plotAreaLeftMargin == newPlotAreaLeftMargin)
        return;
    _plotAreaLeftMargin = newPlotAreaLeftMargin;
    emit plotAreaLeftMarginChanged();
}
qint32 UniversalChart::plotAreaTopMargin() const
{
    return _plotAreaTopMargin;
}
void UniversalChart::setPlotAreaTopMargin(qint32 newPlotAreaTopMargin)
{
    if (_plotAreaTopMargin == newPlotAreaTopMargin)
        return;
    _plotAreaTopMargin = newPlotAreaTopMargin;
    emit plotAreaTopMarginChanged();
}
qint32 UniversalChart::plotAreaRightMargin() const
{
    return _plotAreaRightMargin;
}
void UniversalChart::setPlotAreaRightMargin(qint32 newPlotAreaRightMargin)
{
    if (_plotAreaRightMargin == newPlotAreaRightMargin)
        return;
    _plotAreaRightMargin = newPlotAreaRightMargin;
    emit plotAreaRightMarginChanged();
}
qint32 UniversalChart::plotAreaBottomMargin() const
{
    return _plotAreaBottomMargin;
}
void UniversalChart::setPlotAreaBottomMargin(qint32 newPlotAreaBottomMargin)
{
    if (_plotAreaBottomMargin == newPlotAreaBottomMargin)
        return;
    _plotAreaBottomMargin = newPlotAreaBottomMargin;
    emit plotAreaBottomMarginChanged();
}

void UniversalChart::mouseMoveEvent(QMouseEvent *event)
{

}
void UniversalChart::mousePressEvent(QMouseEvent *event)
{

}
void UniversalChart::mouseReleaseEvent(QMouseEvent *event)
{

}
void UniversalChart::wheelEvent(QWheelEvent *event)
{

}

void UniversalChart::hoverMoveEvent(QHoverEvent *event)
{

}

void UniversalChart::draw()
{

}

bool UniversalChart::initialized() const
{
    return _initialized;
}
void UniversalChart::setInitialized(bool newInitialized)
{
    if (_initialized == newInitialized)
        return;
    _initialized = newInitialized;

    emit initializedChanged();
}
