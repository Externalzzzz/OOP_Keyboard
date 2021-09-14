#ifndef TABLE_H
#define TABLE_H

#include <QObject>
#include <QtWidgets>
#include <QTableWidget>
#include <QMouseEvent>
/*!
 * \brief The Table class - Класс для реализации DragAndDrop
 */
class Table : public QTableWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Table - Конструктор класса таблицы
     * \param parent - указание на родительский класс
     */
    Table(QWidget * parent = nullptr);
private:
    /*!
     * \brief mousePressEvent - Метод для реализации DragAndDrop(Клик)
     * \param event - указание события
     */
    void mousePressEvent  (QMouseEvent * event);
    /*!
     * \brief mouseMoveEvent - Метод для реализации DragAndDrop(Перенос)
     * \param event - указание события
     */

    void mouseMoveEvent   (QMouseEvent * event);

    /*!
     * \brief m_dragStart - Переменная, хранящая координаты точки начала Drag & Drop
     */
    QPoint m_dragStart;
};

#endif // TABLE_H


