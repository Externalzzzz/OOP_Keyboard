#ifndef KEYBOARD_H
#define KEYBOARD_H


#include <QString>
/*!
 * \brief The keyboard class - основной класс Клавиатур
*/

class keyboard

{
public:
    keyboard();
private:
    /*!
     * \brief ID - ID модели
     */
    int ID;
    /*!
     * \brief Brand - Бренд
     */
    QString Brand;
    /*!
     * \brief Model - Модель
     */
    QString Model;
    /*!
     * \brief Keys - Количество клавиш
     */
    int Keys;
    /*!
     * \brief Type - Тип клавишей
     */
    QString Type;
    /*!
     * \brief Price - Цена клавиатуры
     */
    int Price;
    /*!
     * \brief Light - Тип подсветки
     */
    QString Light;
    /*!
     * \brief Connect - Тип подключения
     */
    QString Connect;
public:
    /*!
     * \brief keyboard - конструктор класса
     */
    keyboard(const int, const QString, const QString, const int, const QString,const int, const QString, const QString);
    /*!
      * ~keyboard(); - деструктор класса
      */
    ~keyboard();
                                        /*! int get_ID()const; взятие значения переменных(ID)*/
    int get_ID()const;                  /*! QString get_Brand()const; взятие значения переменных(Бренд)*/
    QString get_Brand()const;           /*! QString get_Model()const; взятие значения переменных(Модель)*/
    QString get_Model()const;           /*! int get_Keys()const; взятие значения переменных(Кол-во клавиш)*/
    int get_Keys()const;                /*! QString get_Type()const; взятие значения переменных(Тип клавиш)*/
    QString get_Type()const;            /*!  int get_Price()const;  взятие значения переменных(Цена)*/
    int get_Price()const;               /*! QString get_Light()const; взятие значения переменных(Тип подсветки)*/
    QString get_Light()const;           /*! QString get_Connect()const; взятие значения переменных(Тип подключения)*/
    QString get_Connect()const;
                                        /*! int get_ID()const; задающие значения параметров(ID)*/
    void set_ID(int varID);             /*! void set_Brand(QString varBrand); задающие значения параметров(Бренд)*/
    void set_Brand(QString varBrand);   /*! void set_Model(QString varModel); задающие значения параметров(Модель)*/
    void set_Model(QString varModel);   /*! void set_Keys(int varKeys); задающие значения параметров(Кол-во клавиш)*/
    void set_Keys(int varKeys);         /*! void set_Type(QString varType); задающие значения параметров(Тип клавиш)*/
    void set_Type(QString varType);     /*! void set_Price(int varPrice);  задающие значения параметров(Цена)*/
    void set_Price(int varPrice);       /*! void set_Light(QString varLight); задающие значения параметров(Тип подсветки)*/
    void set_Light(QString varLight);   /*!  void set_Connect(QString varConnect);  задающие значения параметров(Тип подключения)*/
    void set_Connect(QString varConnect);
};

#endif // KEYBOARD_H
