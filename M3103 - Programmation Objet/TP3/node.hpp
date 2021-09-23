#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

using namespace std;

template <typename T>
class CNode
{
private:
    T m_Data;
    shared_ptr<CNode> m_Next;
public:
    //constructor
    CNode (const T &  val = T(), const shared_ptr<CNode> & ptr = nullptr);
    //destructor
    ~CNode ();

    //getter / setter
    const T &GetData () const;
    const shared_ptr<CNode> & GetNextNode () const;
    void SetData (const T & val);
    void SetNextNode (const shared_ptr<CNode>&);
};


template <typename T>
CNode<T>::CNode (const T & val, const shared_ptr<CNode> & ptr ) : m_Data (val), m_Next (ptr)
{
}

template <typename T>
CNode<T>::~CNode ()
{
}

template <typename T>
const T & CNode<T>::GetData () const
{
    return m_Data;
}

template <typename T>
const shared_ptr<CNode<T>> & CNode<T>::GetNextNode () const
{
    return m_Next;
}


template <typename T>
void CNode<T>::SetData (const T & val)
{
    m_Data = val;
}

template <typename T>
void CNode<T>::SetNextNode (const shared_ptr<CNode> & ANode)
{
    m_Next = ANode;
}

#endif // NODE_HPP
