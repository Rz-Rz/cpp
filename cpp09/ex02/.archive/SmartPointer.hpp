#ifndef SMARTPOINTER_HPP
#define SMARTPOINTER_HPP

#include "ReferenceCounter.hpp"
#include <iostream>

template <typename T> class SmartPointer
{
  private: 
    T*    pData;       // pointer
    ReferenceCounter* reference; // Reference count

  public:
    SmartPointer() : pData(0), reference(0) 
    {
      // Create a new reference 
      reference = new ReferenceCounter();
      // Increment the reference count
      reference->AddRef();
    }

    SmartPointer(T* pValue) : pData(pValue), reference(0)
    {
      // Create a new reference 
      reference = new ReferenceCounter();
      // Increment the reference count
      reference->AddRef();
    }

    SmartPointer(const SmartPointer<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
      // Copy constructor
      // Copy the data and reference pointer
      // and increment the reference count
      reference->AddRef();
    }

    ~SmartPointer()
    {
      // Destructor
      // Decrement the reference count
      // if reference become zero delete the data
      if(reference->Release() == 0)
      {
        delete pData;
        delete reference;
      }
    }

    T& operator*()
    {
      return *pData;
    }

    T* operator->() const 
    {
      return pData;
    }

    T* get() const 
    {
      return pData;
    }

    int referenceCount() const
    {
      return reference->getCount();
    }

    SmartPointer<T>& operator = (const SmartPointer<T>& sp)
    {
      // Assignment operator
      if (this != &sp) // Avoid self assignment
      {
        // Decrement the old reference count
        // if reference become zero delete the old data
        if(reference->Release() == 0)
        {
          delete pData;
          delete reference;
        }

        // Copy the data and reference pointer
        // and increment the reference count
        pData = sp.pData;
        reference = sp.reference;
        reference->AddRef();
      }
      return *this;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SmartPointer<T>& sp) {
    os << *(sp.operator->());
    return os;
}

#endif
