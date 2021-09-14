#ifndef Sorting_H
#define Sorting_H

#include <QDialog>
#include <QString>

#include "keyboard.h"

namespace Ui {
class Sorting;
}
/*!
 * \brief The Sorting class - Класс для сортировки данных в таблице
 */
class Sorting : public QDialog
{
    Q_OBJECT

public:
    explicit Sorting(QWidget *parent = nullptr);
    ~Sorting();
    /*!
     * \brief Brand - Бренд
     */
    int Brand;
    /*!
     * \brief Light - Тип подсветки
     */
    int Light;
    /*!
     * \brief Connect - Тип подключения
     */
    int Connect;

    bool checkOK(keyboard *ptrkeyboard);

private slots:
    /*!
     * \brief on_buttonBox_accepted - Подтверждение выбранных параметров
     */
    void on_buttonBox_accepted();

private:
    Ui::Sorting *ui;
    /*!
     * \brief BrandOK - логическая перемена для подбора бренда
     */
    bool BrandOK;       //переменная, показывающая, подошел ли бренд
    /*!
     * \brief LightOK - логическая перемена для подбора типа подсветки
     */
    bool LightOK;      //переменная, показывающая, подошел ли тип подсветки
    /*!
     * \brief ConnectOK - - логическая перемена для подбора типа подключения
     */
    bool ConnectOK;    //переменная, показывающая, подошел ли тип подключения
    /*!
     * \brief OK - - логическая перемена обобщающая предыдущие
     */

    bool OK;        //общая переменная для
};

#endif // Sorting_H
