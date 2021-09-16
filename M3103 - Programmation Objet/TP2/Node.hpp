#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class CNode
{
private:
    T m_Data;
    CNode* m_Next;
public:
    //constructor
    CNode (T Data, CNode* Next){
        m_Data = Data;
        m_Next = Next;
    };
    //destructor
    ~CNode (){
        std::cout << m_Data << std::endl;
        delete m_Next;
    }

    void SetNextNode(CNode* Next){
        m_Next = Next;
    }

    CNode* GetNextNode() {
        return m_Next;
    }

    void SetData(T Data){
        m_Data = Data;
    }

    T GetData() {
        return m_Data;
    }
};

#endif // NODE_HPP
