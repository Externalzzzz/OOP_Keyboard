
#include "QFont"\

#include "diagram.h"
#include "ui_diagram.h"
/*!
 * \brief Diagram:: - Diagram Конструктор класса Диаграмма
 * \param parent - указатель на родительский класс
 */
Diagram::Diagram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diagram)
{
    ui->setupUi(this);

    x[0] = 50;
    x[1] = 55;
    x[2] = 79;
    x[3] = 87;
    x[4] = 104;
    x[5] = 110;
    x[6] = 113;

    y[0] = 700;
    y[1] = 740;
    y[2] = 6889;
    y[3] = 2397;
    y[4] = 3704;
    y[5] = 14500;
    y[6] = 7960;

}
/*!
 * \brief Diagram::~Diagram Деструктор класса Диаграмма
 */
Diagram::~Diagram()
{
    delete ui;
}

/*!
 * \brief Diagram::showDiagram - Вывод диграммы на экран
 */
void Diagram::showDiagram()
{
    QFont newfont("Courier",15,QFont::Bold);

    QLineSeries *series = new QLineSeries();
    series->setPen(QPen(QBrush(QColor(Qt::green)),6));

    for (int i = 0; i<N; i++)
    {
        series->append(x[i], y[i]);
    }

    int max = 0;
    for (int i = 0; i < 7; i++)
        max = (y[i] > max)? y[i] : max;

    QChart *chart = new QChart();

    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitleFont(newfont);
    chart->setBackgroundBrush(QBrush(QColor(0,0,0,255)));
    chart->setTitle(tr("Diagram about keyboards"));
    chart->setTitleBrush(QBrush(QColor(Qt::green)));


    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(50, 150);
    axisX->setTickCount(7);
    axisX->setLabelsColor(QColor(Qt::red));
    axisX->setLabelFormat("%.d");
    axisX->setGridLineColor(QColor(Qt::red));
    axisX->setTitleText(tr("Keys"));
    axisX->setTitleFont(newfont);
    axisX->setTitleBrush(QBrush(QColor(Qt::green)));

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 16000);
    axisY->setTickCount(7);
    axisY->setLabelFormat("%.d");
    axisY->setLabelsColor(QColor(Qt::red));
    axisY->setShadesVisible(true);
    axisY->setGridLineColor(QColor(Qt::red));
    axisY->setTitleFont(newfont);
    axisY->setTitleText(tr("Price"));
    axisY->setTitleBrush(QBrush(QColor(Qt::green)));

    QChartView *chartView = new QChartView(chart);
    chartView->chart()->setAxisX(axisX, series);
    chartView->chart()->setAxisY(axisY, series);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->gridLayout->addWidget(chartView);
}


