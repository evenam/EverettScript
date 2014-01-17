//
//  Singleton.h
//  evaluate
//
//  Created by Everett Moser on 1/3/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef evaluate_Singleton_h
#define evaluate_Singleton_h

template <class T>
class Singleton
{
protected:
    static T *_singletonRef;
    
public:
    virtual ~Singleton()
    {
    }
    
    inline static T* getRef() // grab it
    {
        if (!_singletonRef)
            _singletonRef = new T;
        
        return _singletonRef;
    }
    
    static void deleteRef() // release it
    {
        if(_singletonRef)
        {
            delete _singletonRef;
            _singletonRef = NULL;
        }
    }
};

template <class T>
    T* Singleton<T>::_singletonRef = NULL;

#endif
