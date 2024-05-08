#include "universalpainter.h"

UniversalPainter::UniversalPainter()
{

}
UniversalPainter::UniversalPainter(QNanoPainter *painter)
{
    setPainter(painter);
}

// *** Frame settings ***


float UniversalPainter::devicePixelRatio()
{
    return _painter->devicePixelRatio();
}


// *** Frame controls ***

void UniversalPainter::beginFrame(float width, float height)
{
    _currentOffset = QPointF(0,0);
    _frames.push(_currentOffset);
    _painter->beginFrame(width * _painter->devicePixelRatio(), height * _painter->devicePixelRatio());
}
void UniversalPainter::beginFrameAt(float x, float y, float width, float height)
{
    _currentOffset = QPointF(-x, -y);
    _frames.push(_currentOffset);
    _painter->beginFrameAt(x, y, width * _painter->devicePixelRatio(), height * _painter->devicePixelRatio());
}
void UniversalPainter::endFrame()
{
    _currentOffset = _frames.pop();
    _painter->endFrame();
}


// *** Render styles ***

void UniversalPainter::setStrokeStyle(const QNanoColor &color)
{
    _painter->setStrokeStyle(color);
}
void UniversalPainter::setFillStyle(const QNanoColor &color)
{
    _painter->setFillStyle(color);
}
void UniversalPainter::setStrokeStyle(const QColor &color)
{
    setStrokeStyle(QNanoColor(color.red(), color.green(), color.blue(), color.alpha()));
}
void UniversalPainter::setFillStyle(const QColor &color)
{
    setFillStyle(QNanoColor(color.red(), color.green(), color.blue(), color.alpha()));
}

void UniversalPainter::setLineWidth(float width)
{
    _painter->setLineWidth(width);
}



//  *** Paths ***

void UniversalPainter::beginPath()
{
    _painter->beginPath();
}
void UniversalPainter::closePath()
{
    _painter->closePath();
}

void UniversalPainter::moveTo(int x, int y)
{
    moveTo(static_cast<float>(x), static_cast<float>(y));
}

void UniversalPainter::moveTo(qint64 x, qint64 y)
{
    moveTo(static_cast<float>(x), static_cast<float>(y));
}
void UniversalPainter::moveTo(float x, float y)
{
    _painter->moveTo(x + _currentOffset.x(), y + _currentOffset.y());
}
void UniversalPainter::moveTo(const QPointF &point)
{
    moveTo(static_cast<float>(point.x()), static_cast<float>(point.y()));
}

void UniversalPainter::lineTo(int x, int y)
{
    lineTo(static_cast<float>(x), static_cast<float>(y));
}

void UniversalPainter::lineTo(qint64 x, qint64 y)
{
    lineTo(static_cast<float>(x), static_cast<float>(y));
}
void UniversalPainter::lineTo(float x, float y)
{
    _painter->lineTo(x + _currentOffset.x(), y + _currentOffset.y());
}
void UniversalPainter::lineTo(const QPointF &point)
{
    lineTo(static_cast<float>(point.x()), static_cast<float>(point.y()));
}

void UniversalPainter::fill()
{
    _painter->fill();
}
void UniversalPainter::stroke()
{
    _painter->stroke();
}


// *** Direct drawing ***

void UniversalPainter::fillRect(float x, float y, float width, float height)
{
    _painter->fillRect(x + _currentOffset.x(), y + _currentOffset.y(), width, height);
}
void UniversalPainter::fillRect(const QRectF &rect)
{
    fillRect(static_cast<float>(rect.x()),
             static_cast<float>(rect.y()),
             static_cast<float>(rect.width()),
             static_cast<float>(rect.height()));
}


// *** Other ***

void UniversalPainter::setAntialias(float antialias)
{
    _painter->setAntialias(antialias);
}


// *** Painter ***

void UniversalPainter::setPainter(QNanoPainter *painter)
{
    _painter = painter;
}
QNanoPainter *UniversalPainter::painter()
{
    return _painter;
}
