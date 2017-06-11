#ifndef ITERATOR_H
#define ITERATOR_H

template<class T>
class Iterator{  // erreur : voir "template friend" ? : http://en.cppreference.com/w/cpp/language/friend
    T** current;//https://cboard.cprogramming.com/cplusplus-programming/53097-declare-template-class-friend.html
protected:
    Iterator (T** curr): current(curr){}
public:
    Iterator(): current(0){}
    T& operator*() const {return *current;}
    Iterator& operator++() {++current; return *this;}
    Iterator& operator++(int){
        Iterator old = *this; ++current; return old;
    }
    bool operator==(Iterator it) const{
        return current == it.current;
    }
    bool operator!=(Iterator it) const{
        return current != it.current;
    }
};

#endif // ITERATOR_H
