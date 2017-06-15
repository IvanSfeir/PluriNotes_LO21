/*!
 *@file     exception.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The exception class
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <QString>

/*!
 * \brief The Exception class: class Exception
 */
class Exception{
public:
    /*!
     * \brief Exception: constructor of Exception class
     * \param message: error message
     */
    Exception(const QString& message):info(message){}
    /*!
     * \brief getInfo: get error message
     * \return QString
     */
    QString getInfo() const { return info; }
private:
    /*!
     * \brief info: error message
     */
    QString info;
};



#endif // NOTEEXCEPTION_H
