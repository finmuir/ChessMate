#ifndef LABELCLICK_H
#define LABELCLICK_H

#include <QLabel>
#include <QMouseEvent>

class Labelclick : public QLabel
{
    Q_OBJECT

public:
    explicit Labelclick(QWidget* parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // LABELCLICK_H
