/*!
 *@file     iterator.h
 *@author   Ngo Sy Toan
 * @date    June 2017
 * @brief   The template of iterator
 */

#ifndef ITERATOR_H
#define ITERATOR_H


template<class T>
class Iterator{
    /*!
     * \brief current: table of class T
     */
    T** current;
protected:
    /*!
     * \brief Iterator: constructor of iterator
     * \param curr: pointer to an position of the table of T
     */
    Iterator (T** curr): current(curr){}
public:
    /*!
     * \brief Iterator: constructor by default
     */
    Iterator(): current(0){}
    /*!
     * \brief operator *: get the pointer of current element
     * \return pointer of type T
     */
    T* operator*() const {return *current;}
    /*!
     * \brief operator ++: pre-increment iterator
     * \return iterator&
     */
    Iterator& operator++() {++current; return *this;}
    /*!
     * \brief operator ++(int): post-increment iterator
     * \return iterator&
     */
    Iterator& operator++(int){
        Iterator old = *this; ++current; return old;
    }
    /*!
     * \brief operator --: pre-decrement iterator
     * \return iterator&
     */
    Iterator& operator--() {--current; return *this;}
    /*!
     * \brief operator --: post-decrement iterator
     * \return iterator&
     */
    Iterator& operator--(int){
        Iterator old = *this; --current; return old;
    }
    /*!
     * \brief operator ==: comparaison of iterator
     * \return true if same position
     */
    bool operator==(Iterator it) const{
        return current == it.current;
    }
    /*!
     * \brief operator !=: comparaison of iterator
     * \return true if not same position
     */
    bool operator!=(Iterator it) const{
        return current != it.current;
    }
};

#endif // ITERATOR_H
