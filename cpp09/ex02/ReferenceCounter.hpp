#ifndef   REFERENCE_COUNTER_HPP
#define   REFERENCE_COUNTER_HPP

class ReferenceCounter
{
  private: 
    int count;
  
  public:
    ReferenceCounter() : count(0)
    {
    }

    void AddRef()
    {
      // Increment the reference count
      count++;
    }

    int getCount() const
    {
      // Return the reference count.
      return count;
    }
    
    int Release()
    {
      // Decrement the reference count and
      // return the reference count.
      return --count;
    }
};
#endif
