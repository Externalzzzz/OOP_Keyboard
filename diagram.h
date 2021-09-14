#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QDialog>
#include <QList>
#include <QDebug>
#include <QVector>
#include <QtCharts>
#include <QValueAxis>

#include <QSplineSeries>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>

#include <QLineSeries>

#include <windows.h>
#include <keyboard.h>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Diagram;
}
/*!
 * \brief The Diagram class - класс Диаграмма
 */
class Diagram : public QDialog
{
    Q_OBJECT

public:

    /*!
     * \brief showDiagram - метод вывода диаграммы на экран
     */
    void showDiagram();

    explicit Diagram(QWidget *parent = nullptr);
    ~Diagram();

private:
    Ui::Diagram *ui;

    const int N = 7;

    int x[7];

    int y[7];
};

#endif // DIAGRAM_H
