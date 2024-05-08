#ifndef UNIVERSALPAINTER_H
#define UNIVERSALPAINTER_H

#include "qnanoquickitempainter.h"

class UniversalPainter
{
public:
    UniversalPainter();
    UniversalPainter(QNanoPainter *painter);


    // *** Frame settings ***

    float devicePixelRatio();


    // *** Frame controls ***

    void beginFrame(float width, float height);
    void beginFrameAt(float x, float y, float width, float height);
    void endFrame();


    // *** Render styles ***

    void setStrokeStyle(const QNanoColor &color);
    void setFillStyle(const QNanoColor &color);
    void setStrokeStyle(const QColor &color);
    void setFillStyle(const QColor &color);
    void setLineWidth(float width);


    //  *** Paths ***

    void beginPath();
    void closePath();
    void moveTo(int x, int y);
    void moveTo(qint64 x, qint64 y);
    void moveTo(float x, float y);
    void moveTo(const QPointF &point);
    void lineTo(int x, int y);
    void lineTo(qint64 x, qint64 y);
    void lineTo(float x, float y);
    void lineTo(const QPointF &point);

    void fill();
    void stroke();


    // *** Direct drawing ***

    void fillRect(float x, float y, float width, float height);
    void fillRect(const QRectF &rect);


    // *** Other ***

    void setAntialias(float antialias);


    // *** Painter ***

    void setPainter(QNanoPainter *painter);
    QNanoPainter *painter();


private:
    QNanoPainter* _painter = nullptr;

    QStack<QPointF> _frames;
    QPointF _currentOffset = QPointF(0, 0);
};

#endif // UNIVERSALPAINTER_H
