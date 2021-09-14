#ifndef COMBOBOX_H
#define COMBOBOX_H


#include <QItemDelegate>
#include <QSpinBox>
#include <QApplication>
#include <QComboBox>
/*!
 * \brief The CellsComboBox1 class - Выпадающее меню выбора производителя
 */
class CellsComboBox1 : public QItemDelegate
{
public:

    CellsComboBox1(QWidget *parent = nullptr);

    ~CellsComboBox1();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};
/*!
 * \brief The CellsComboBox3 class - Поле с прокруткой значений для количества клавиш
 */
class CellsComboBox3 : public QItemDelegate
{
public:

    CellsComboBox3(QWidget *parent = nullptr);

    ~CellsComboBox3();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

/*!
 * \brief The CellsComboBox4 class - Выпадающее меню выбора типа клавиш
 */
class CellsComboBox4 : public QItemDelegate
{
public:

    CellsComboBox4(QWidget *parent = nullptr);

    ~CellsComboBox4();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};
/*!
 * \brief The CellsComboBox6 class - Выпадающее меню выбора типа подсветки
 */
class CellsComboBox6 : public QItemDelegate
{
public:

    CellsComboBox6(QWidget *parent = nullptr);

    ~CellsComboBox6();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  };
/*!
 * \brief The CellsComboBox5 class - Выпадающее меню цены
 */
class CellsComboBox5 : public QItemDelegate
{
public:

    CellsComboBox5(QWidget *parent = nullptr);

    ~CellsComboBox5();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  };
/*!
 * \brief The CellsComboBox7 class - Выпадающее меню для типа подключения
 */
class CellsComboBox7 : public QItemDelegate
{
public:

    CellsComboBox7(QWidget *parent = nullptr);

    ~CellsComboBox7();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
  };

#endif // COMBOBOX_H
