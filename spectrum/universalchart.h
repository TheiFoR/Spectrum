#ifndef UNIVERSALCHART_H
#define UNIVERSALCHART_H

#include "qnanoquickitem.h"
#include "qnanoquickitempainter.h"
#include "painter/universalpainter.h"
#include "painter/universalchartpainter.h"

class UniversalChart : public QNanoQuickItem
{
    Q_OBJECT

public:
    UniversalChart(QQuickItem *parent = nullptr);

    QNanoQuickItemPainter *createItemPainter() const override;

    qint32 plotAreaLeftMargin() const;
    void setPlotAreaLeftMargin(qint32 newPlotAreaLeftMargin);
    qint32 plotAreaTopMargin() const;
    void setPlotAreaTopMargin(qint32 newPlotAreaTopMargin);
    qint32 plotAreaRightMargin() const;
    void setPlotAreaRightMargin(qint32 newPlotAreaRightMargin);
    qint32 plotAreaBottomMargin() const;
    void setPlotAreaBottomMargin(qint32 newPlotAreaBottomMargin);

    bool initialized() const;
    void setInitialized(bool newInitialized);

signals:
    void plotAreaLeftMarginChanged();
    void plotAreaTopMarginChanged();
    void plotAreaRightMarginChanged();
    void plotAreaBottomMarginChanged();

    void initializedChanged();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void hoverMoveEvent(QHoverEvent *event) override;

private:
    UniversalChartPainter* _universalChartPainter = nullptr;
    UniversalPainter _painter;

    std::unique_ptr<QTimer> timer { new QTimer(this) };

    bool _initialized = false;

    qint32 _plotAreaLeftMargin = 0;
    qint32 _plotAreaTopMargin = 0;
    qint32 _plotAreaRightMargin = 0;
    qint32 _plotAreaBottomMargin = 0;

    void draw();

    Q_PROPERTY(bool initialized READ initialized WRITE setInitialized NOTIFY initializedChanged FINAL)

    Q_PROPERTY(qint32 plotAreaLeftMargin READ plotAreaLeftMargin WRITE setPlotAreaLeftMargin NOTIFY plotAreaLeftMarginChanged FINAL)
    Q_PROPERTY(qint32 plotAreaTopMargin READ plotAreaTopMargin WRITE setPlotAreaTopMargin NOTIFY plotAreaTopMarginChanged FINAL)
    Q_PROPERTY(qint32 plotAreaRightMargin READ plotAreaRightMargin WRITE setPlotAreaRightMargin NOTIFY plotAreaRightMarginChanged FINAL)
    Q_PROPERTY(qint32 plotAreaBottomMargin READ plotAreaBottomMargin WRITE setPlotAreaBottomMargin NOTIFY plotAreaBottomMarginChanged FINAL)
};

#endif
