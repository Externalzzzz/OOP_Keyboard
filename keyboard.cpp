#include "keyboard.h"
/*!
 * \brief keyboard::keyboard - Первый(Пустой) конструктор класса клавиатуры
 */
keyboard::keyboard()
{

}

/*!
 * \brief keyboard::keyboard - Конструктор класса Клавиатуры с параметрами
 * \param id -id
 * \param brand - Бренд
 * \param model - Модель
 * \param keys - Кол-во клавиш
 * \param type - Тип клавиш
 * \param price - Цена
 * \param light - Тип подсветки
 * \param connect - Тип подключения
 */
keyboard::keyboard(const int id, const QString brand , const QString model , const int keys , const QString type , const int price , const QString light , const QString connect)
{
ID = id;
Brand = brand;
Model = model;
Keys = keys;
Type = type;
Price = price;
Light = light;
Connect = connect;
}
/*!
 * \brief keyboard::~keyboard - деструктор класса клавиатуры
 */
keyboard::~keyboard()
{

}

/*!
 * \brief keyboard::get_ID -взятие значения переменных(ID)
 * \return Возвращает нужный ID
 */
int keyboard::get_ID() const
{
    return ID;
}
/*!
 * \brief keyboard::get_Brand - взятие значения переменных(Бренд)
 * \return Возвращает нужный Бренд
 */
QString keyboard::get_Brand() const
{
    return Brand;
}
/*!
 * \brief keyboard::get_Model - взятие значения переменных(Модель)
 * \return Возвращает нужную Модель
 */
QString keyboard::get_Model() const
{
    return Model;
}
/*!
 * \brief keyboard::get_Keys - взятие значения переменных(Кол-во клавиш)
 * \return Возвращает количество клавиш (keys)
 */
int keyboard::get_Keys() const
{
    return Keys;
}
/*!
 * \brief keyboard::get_Type - взятие значения переменных(Тип клавиш)
 * \return Возвращает тип клавиш(механические или мембранные)
 */
QString keyboard::get_Type() const
{
    return Type;
}
/*!
 * \brief keyboard::get_Price - взятие значения переменных(Цена)
 * \return Возвращает цену клавиатуры
 */
int keyboard::get_Price() const
{
    return Price;
}
/*!
 * \brief keyboard::get_Light - взятие значения переменных(Тип подсветки)
 * \return Возвращает тип подсветки клавиатуры
 */
QString keyboard::get_Light() const
{
    return Light;
}
/*!
 * \brief keyboard::get_Connect - взятие значения переменных(Тип подключения)
 * \return Возвращает тип подключения клавиатуры
 */
QString keyboard::get_Connect() const
{
    return Connect;
}
/*!
 * \brief keyboard::set_ID - задающие значения параметров(ID)
 * \param varID ID
 */
void keyboard::set_ID(int varID)
{
    ID = varID;
}
/*!
 * \brief keyboard::set_Brand - задающие значения параметров(Бренд)
 * \param varBrand Бренд
 */
void keyboard::set_Brand(QString varBrand)
{
    Brand = varBrand;
}
/*!
 * \brief keyboard::set_Model - задающие значения параметров(Модель)
 * \param varModel Модель
 */
void keyboard::set_Model(QString varModel)
{
    Model = varModel;
}
/*!
 * \brief keyboard::set_Keys - задающие значения параметров(Кол-во клавиш)
 * \param varKeys Количество клавиш клавиатуры
 */
void keyboard::set_Keys(int varKeys)
{
    Keys = varKeys;
}
/*!
 * \brief keyboard::set_Type - задающие значения параметров(Тип клавиш)
 * \param varType Тип клавиш
 */
void keyboard::set_Type(QString varType)
{
    Type = varType;
}
/*!
 * \brief keyboard::set_Price - задающие значения параметров(Цена)
 * \param varPrice Цена клавиатуры
 */
void keyboard::set_Price(int varPrice)
{
   Price = varPrice;
}
/*!
 * \brief keyboard::set_Light - задающие значения параметров(Тип подсветки)
 * \param varLight Тип подсветки клавиш у клавиатуры
 */
void keyboard::set_Light(QString varLight)
{
    Light = varLight;
}
/*!
 * \brief keyboard::set_Connect - задающие значения параметров(Тип подключения)
 * \param varConnect Тип подключения клавиатуры
 */
void keyboard::set_Connect(QString varConnect)
{
    Connect = varConnect;
}
