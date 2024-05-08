#ifndef UNIVERSALCHARTPAINTER_H
#define UNIVERSALCHARTPAINTER_H

#include "qnanoquickitempainter.h"

class UniversalChartPainter : public QNanoQuickItemPainter
{
public:
    UniversalChartPainter();
    ~UniversalChartPainter() override;

    void paint(QNanoPainter *painter) override;
    void refresh();
};

#endif // UNIVERSALCHARTPAINTER_H
