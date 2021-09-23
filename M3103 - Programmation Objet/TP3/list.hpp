#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include "node.hpp"
#include <memory>

using namespace std;

template <typename T>
class CList
{
private:
    CNode<T>* m_fictionaHead;
    CNode<T>* m_realTail;

public:
    CList ();
    ~CList ();
    void push_front (const T & val);
    void Show () const;
    const shared_ptr<CNode<T>> & Find (const T & val) const;
    void Add (const T & val, const shared_ptr<CNode<T>> &);
    void Delete (const shared_ptr<CNode<T>> &);
    void push_back (const T & val);
    const shared_ptr<CNode<T>> & Begin () const;
    void AddAfter (const shared_ptr<CNode<T>> &, const T & val);
};

template <typename T>
const shared_ptr<CNode<T>> & CList<T>::Begin () const
{
    return m_fictionaHead;
}

template <typename T>
void CList<T>::AddAfter (const shared_ptr<CNode<T>> & ptr, const T & val)
{
    ptr -> SetNextNode (new CNode<T> (val, ptr-> GetNextNode()));
    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}

template <typename T>
void CList<T>::Add (const T & val, const shared_ptr<CNode<T>> & ptr)
{
    CNode<T>* ptrTmp = new CNode<T> (val, ptr -> GetNextNode ());
    ptr -> SetNextNode (ptrTmp);
    if (ptr == m_realTail) m_realTail = ptr->GetNextNode ();
}

template <typename T>
CList<T>::CList () : m_fictionaHead (new CNode<T> ()), m_realTail (m_fictionaHead) {};

template <typename T>
CList<T>::~CList () {
    delete m_fictionaHead;
}

template <typename T>
const shared_ptr<CNode<T>> & CList<T>::Find (const T & val) const
{
    CNode<T>* Ptr (m_fictionaHead->GetNextNode ());
    for (; Ptr != nullptr && Ptr -> GetData () != val ; Ptr = Ptr->GetNextNode ());

    return Ptr;
}



template <typename T>
void CList<T>::push_front (const T & val)
{
    m_fictionaHead->SetNextNode (new CNode<T> (val, m_fictionaHead->GetNextNode ()));
    if (m_realTail == m_fictionaHead) m_realTail = m_fictionaHead->GetNextNode ();
}

template <typename T>
void CList<T>::Show () const
{
    //for (CNodeInt* Ptr (m_Head); Ptr; ++*Ptr)
    for (CNode<T>* Ptr (m_fictionaHead -> GetNextNode()); Ptr; Ptr = Ptr->GetNextNode ())
            std::cout << Ptr->GetData() << "; ";
    std::cout << std::endl;
}

template <typename T>
void CList<T>::Delete (const shared_ptr<CNode<T>> & pDelete)
{
    CNode<T>* pFind (m_fictionaHead);
    for ( ; pFind -> GetNextNode () != pDelete ; pFind = pFind -> GetNextNode ());

    pFind -> SetNextNode (pDelete -> GetNextNode ());
    if (pDelete == m_realTail) m_realTail = pFind;
    pDelete -> SetNextNode (nullptr);

    delete pDelete;
}

template <typename T>
void CList<T>::push_back (const T & val)
{
    CNode<T>* pTmp = new CNode<T> (val, NULL);
    m_realTail -> SetNextNode (pTmp);
    m_realTail = pTmp;
}


#endif // LIST_HPP
