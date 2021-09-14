#include "combobox.h"
/*!
 * \brief CellsComboBox1::CellsComboBox1 - Конструктор для Выбора бренда
 * \param parent - Указатель на родительский класс
 */
CellsComboBox1::CellsComboBox1(QWidget *parent):
    QItemDelegate(parent) //предосттавление доступа для изменения выбранного объекта(виджета)
{

}


/*!
 * \brief CellsComboBox1::~CellsComboBox1 - Деструктор выбора бренда
 */
CellsComboBox1::~CellsComboBox1()
{

}
/*!
 * \brief CellsComboBox1::createEditor - Создание выпадающего меню для брендов
 * \param parent - Указатель на родительский класс
 * \param option - Подробное описание для каждого поля
 * \param index - номер ответа
 * \return - Выбранный бренд
 */
QWidget *CellsComboBox1::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    editor->addItem("Tesoro");
    editor->addItem("Logitech");
    editor->addItem("HyperX");
    editor->addItem("Corsair");
    editor->addItem("QCyber");
    editor->addItem("HARPER");
    editor->addItem("OKLICK");
    editor->addItem("Cooler Master");
    editor->addItem("SteelSeries");
    editor->addItem("Defender");
    editor->addItem("Razer");
    editor->addItem("Apple");
    editor->addItem("A4Tech");
    (void)option;
    (void)index;
    return editor;
}
/*!
 * \brief CellsComboBox1::setEditorData - Добавление данных в меню брендов
 * \param editor - Указатель на выбранный элемент
 * \param index - Номер выбранного элемента
 */
void CellsComboBox1::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(comboBox->findText(index.data().toString()));
}
/*!
 * \brief CellsComboBox1::setModelData - Настройка модели меню брендов
 * \param editor - Указатель на выбранный элемент
 * \param model - Указатель на модель
 * \param index - Номер выбранного элемента
 */
void CellsComboBox1::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);

    QString value = comboBox->currentText();

    if (!value.isEmpty())
        model->setData(index, value, Qt::EditRole);
}
/*!
 * \brief CellsComboBox1::updateEditorGeometry - Обновление размеров ячейки
 * \param editor
 * \param option
 * \param index
 */
void CellsComboBox1::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void)index;
}


/*!
 * \brief CellsComboBox3::CellsComboBox3 - Конструктор для Количества клавиш
 * \param parent - Указатель на родительский класс
 */

CellsComboBox3::CellsComboBox3(QWidget *parent):
    QItemDelegate(parent)
{

}
/*!
 * \brief CellsComboBox3::~CellsComboBox3 - Деструктор для количества клавиш
 */
CellsComboBox3::~CellsComboBox3()
{

}
/*!
 * \brief CellsComboBox3::createEditor - Создание ячейки с возможностью измененися ее значений посредством "скролла"
 * \param parent - Указатель на родительский класс
 * \param option - Описание подробное для каждого поля
 * \param index - номер ответа
 * \return Выбранное количество клавиш
 */
QWidget *CellsComboBox3::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMaximum(300);
    editor->setMinimum(0);
    (void)option;
    (void)index;
    return editor;
}
/*!
 * \brief CellsComboBox3::setEditorData - Добавление данных в меню количества клавиш
 * \param editor - Поле изменения выбранного пункта(Количество клавишей)
 * \param index - Указатель на номер выбранного пункта(Количество клавишей)
 */
void CellsComboBox3::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.data().toInt();
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}
/*!
 * \brief CellsComboBox3::setModelData - Настройка модели меню количества клавиш
 * \param editor - Указатель на выбранный элемент
 * \param model - Указатель на модель
 * \param index  - Номер выбранного элемента
 */
void CellsComboBox3::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(editor);

    int value = spinBox->value();
    model->setData(index,value);
}
/*!
 * \brief CellsComboBox3::updateEditorGeometry - Обновление размеров ячейки
 * \param editor
 * \param option
 * \param index
 */
void CellsComboBox3::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void)index;
}
/*!
 * \brief CellsComboBox4::CellsComboBox4 - Конструктор для Типа клавиш
 * \param parent
 */
CellsComboBox4::CellsComboBox4(QWidget *parent):

    QItemDelegate(parent)
{

}
/*!
 * \brief CellsComboBox4::~CellsComboBox4 - Деструктор для Типа клавиш
 */
CellsComboBox4::~CellsComboBox4()
{

}

/*!
 * \brief CellsComboBox4::createEditor - Создание ячейки с возможностью измененися ее значений из выпадающего меню
 * \param parent - Указатель на родительский класс
 * \param option - Описание подробное для каждого поля
 * \param index - номер ответа
 * \return Выбранный тип клавишей
 */
QWidget *CellsComboBox4::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    editor->addItem("mechanical");
    editor->addItem("membran");
    (void)option;
    (void)index;
    return editor;
}
/*!
 * \brief CellsComboBox4::setEditorData - Добавление данных в меню Типа клавишей
 * \param editor - Поле изменения выбранного пункта(Тип клавишей)
 * \param index - Указатель на номер выбранного пункта(Тип клавишей)
 */
void CellsComboBox4::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(comboBox->findText(index.data().toString()));
}
/*!
 * \brief CellsComboBox4::setModelData - Настройка меню типа клавишей
 * \param editor - Указатель на выбранный элемент
 * \param model - Указатель на модель
 * \param index - Номер выбранного элемента
 */
void CellsComboBox4::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);

    QString value = comboBox->currentText();

    if (!value.isEmpty())
        model->setData(index, value, Qt::EditRole);
}
/*!
 * \brief CellsComboBox4::updateEditorGeometry - Обновление размеров ячейки
 * \param editor
 * \param option
 * \param index
 */
void CellsComboBox4::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void)index;
}
/*!
 * \brief CellsComboBox5::CellsComboBox5 - Создание поля с изменяющимся значением поля
 * \param parent - Указатель на родительский класс
 */
CellsComboBox5::CellsComboBox5(QWidget *parent):
    QItemDelegate(parent)
{

}
/*!
 * \brief CellsComboBox5::~CellsComboBox5 - Деструктор для цены
 */
CellsComboBox5::~CellsComboBox5()
{

}
/*!
 * \brief CellsComboBox5::createEditor - Создание ячейки с возможностью измененися ее значений посредством скролла
 * \param parent - Указатель на родительский класс
 * \param option - Описание подробное для каждого поля
 * \param index - номер ответа
 * \return Выбранная цена
 */
QWidget *CellsComboBox5::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMaximum(25000);
    editor->setMinimum(0);
    (void)option;
    (void)index;
    return editor;
}
/*!
 * \brief CellsComboBox5::setEditorData - Добавление данных в меню выбора цены
 * \param editor - Поле изменения выбранного пункта(Цены)
 * \param index - Указатель на номер выбранного пункта(Количество клавишей)
 */
void CellsComboBox5::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.data().toInt();
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}
/*!
 * \brief CellsComboBox5::setModelData - Создание меню выбора цены
 * \param editor - Указатель на выбранный элемент
 * \param model - Указатель на модель
 * \param index - Номер выбранного элемента
 */
void CellsComboBox5::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(editor);

    int value = spinBox->value();
    model->setData(index,value);
}
/*!
 * \brief CellsComboBox5::updateEditorGeometry - Обновление размеров ячейки
 * \param editor
 * \param option
 * \param index
 */
void CellsComboBox5::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void)index;
}

/*!
 * \brief CellsComboBox7::CellsComboBox7 - Конструктор типа подключения
 * \param parent
 */

CellsComboBox7::CellsComboBox7(QWidget *parent):
    QItemDelegate(parent)
{

}
/*!
 * \brief CellsComboBox7::~CellsComboBox7 - Деструктор типа подключения
 */
CellsComboBox7::~CellsComboBox7()
{

}
/*!
 * \brief CellsComboBox6::CellsComboBox6 - Конструктор для подсветки клавиатуры
 * \param - parent Указатель на родительский класс
 */
CellsComboBox6::CellsComboBox6(QWidget *parent):
    QItemDelegate(parent)
{

}
/*!
 * \brief CellsComboBox6::~CellsComboBox6 - Деструктор для подсветки
 */
CellsComboBox6::~CellsComboBox6()
{

}
/*!
 * \brief CellsComboBox6::createEditor - Создание ячейки с возможностью измененися ее значений из выпадающего меню
 * \param parent - Указатель на родительский класс
 * \param option - Описание подробное для каждого поля
 * \param index - номер ответа
 * \return Выбранный тип подсветки
 */
QWidget *CellsComboBox6::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    QComboBox *editor = new QComboBox(parent);
    editor->addItem("RGB");
    editor->addItem("Mono");
    editor->addItem("Null");
    (void)option;
    (void)index;
    return editor;
}
/*!
 * \brief CellsComboBox6::setEditorData - Добавление данных в меню выбора типа подсветки
 * \param editor - Поле изменения выбранного пункта(Подсветки)
 * \param index - Указатель на номер выбранного пункта(Подсветки)
 */
void CellsComboBox6::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(comboBox->findText(index.data().toString()));
}
/*!
 * \brief CellsComboBox6::setModelData - Настройка меню выбора типа подсветки
 * \param editor - Указатель на выбранный элемент
 * \param model - Указатель на модель
 * \param index - Номер выбранного элемента
 */
void CellsComboBox6::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);

    QString value = comboBox->currentText();

    if (!value.isEmpty())
        model->setData(index, value, Qt::EditRole);
}
/*!
 * \brief CellsComboBox6::updateEditorGeometry - Обновление размеров ячейки
 * \param editor
 * \param option
 * \param index
 */
void CellsComboBox6::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void)index;
}

/*!
 * \brief CellsComboBox7::createEditor - Создание ячейки с возможностью измененися ее значений из выпадающего меню
 * \param parent - Указатель на родительский класс
 * \param option - Описание подробное для каждого поля
 * \param index - номер ответа
 * \return Выбранный тип подключения
 */

QWidget *CellsComboBox7::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    editor->addItem("BT");
    editor->addItem("USB");
    (void)option;
    (void)index;
    return editor;
}
/*!
 * \brief CellsComboBox7::setEditorData - Добавление данных в меню выбора типа подключенися
 * \param editor - Указатель на выбранный элемент
 * \param index - Номер выбранного элемента
 */
void CellsComboBox7::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(comboBox->findText(index.data().toString()));
}
/*!
 * \brief CellsComboBox7::setModelData - Настройка меню выбора подключенися
 * \param editor - Указатель на выбранный элемент
 * \param model - Указатель на модель
 * \param index - Номер выбранного элемента
 */
void CellsComboBox7::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);

    QString value = comboBox->currentText();

    if (!value.isEmpty())
        model->setData(index, value, Qt::EditRole);
}
/*!
 * \brief CellsComboBox7::updateEditorGeometry - Обновление размеров ячейки
 * \param editor
 * \param option
 * \param index
 */
void CellsComboBox7::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    (void)index;
}
