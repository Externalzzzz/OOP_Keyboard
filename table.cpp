
#include <QMimeData>
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QApplication>
#include <QMouseEvent>


#include "table.h"

/*!
 * \brief Table::Table Конструктор класса Таблица
 * \param parent
 */
Table::Table(QWidget * parent) : QTableWidget(parent)
{

}
/*!
 * \brief Table::mousePressEvent  Нажатие на строку
 * \param event Указатель на событие
 */
void Table::mousePressEvent(QMouseEvent *event)
{
    QTableWidget::mousePressEvent(event);
    m_dragStart = event->pos();
}
/*!
 * \brief Table::mouseMoveEvent Перемещение мыши
 * \param event Указатель на событие
 */
void Table::mouseMoveEvent(QMouseEvent *event)
{


     if ((event->buttons() & Qt::LeftButton) && QApplication::startDragDistance() <= (event->pos() - m_dragStart).manhattanLength())
     {

        QModelIndex id = indexAt(event->pos());
        if(id.isValid())
        {
            setDragDropMode(QAbstractItemView::DragDrop);
            QString _id         = model()->index(id.row(), 0).data().toString() + ";";
            QString _brand      = model()->index(id.row(), 1).data().toString() + ";";
            QString _model      = model()->index(id.row(), 2).data().toString() + ";";
            QString _keys       = model()->index(id.row(), 3).data().toString() + ";";
            QString _type       = model()->index(id.row(), 4).data().toString() + ";";
            QString _price      = model()->index(id.row(), 5).data().toString() + ";";
            QString _light      = model()->index(id.row(), 6).data().toString() + ";";
            QString _connect    = model()->index(id.row(), 7).data().toString() + ";";

            QString pass = _id + _brand + _model + _keys + _type + _price + _light + _connect;
            QDrag * drag = new QDrag(this);
            QMimeData * mimeData = new QMimeData();
            mimeData->setText(pass);
            drag->setMimeData(mimeData);
            drag->exec();
            this->setDropIndicatorShown(true);
            this->setAcceptDrops(true);
        }
        else
            setDragDropMode(QAbstractItemView::NoDragDrop);
    }
}
