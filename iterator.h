#ifndef ITERATOR_H
#define ITERATOR_H

template<class T, class classSource>
class iterator{
    friend class Source;
    T* current;
    iterator(T* curr): current(curr){}
public:
    iterator(): current(0){}
    T& operator*() const {return *current;}
    iterator& operator++() {++current; return *this;}
    iterator& operator++(int){
        iterator old = *this; ++current; return old;
    }
    bool operator==(iterator it) const{
        return current == it.current;
    }
    bool operator!=(iterator it) const{
        return current != it.current;
    }
};

#endif // ITERATOR_H
