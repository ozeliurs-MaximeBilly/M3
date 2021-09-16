#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include <iostream>

template <typename T>
class CList
{
private:
    CNode<T>* m_Head;
    CNode<T>* m_Tail;
public:
    CList (){
        m_Head = nullptr;
        m_Tail = nullptr;
    }

    ~CList (){
        delete m_Head;
    }

    //ajout en tête de liste CNode (T Data, CNode* Next){
    void push_front (const T & val){
        if (m_Head == nullptr) {
            m_Head = new CNode<T>(val, m_Head);
            m_Tail = m_Head;
            return;
        }
        m_Head = new CNode<T>(val, m_Head);
    }

    //affichage
    void Show () const {
        for (CNode<T>* Current(this->m_Head); Current; Current = Current->GetNextNode()){
            std::cout << Current->GetData() << std::endl;
        }
    }

    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const {
        for (CNode<T>* Current(this->m_Head); Current; Current = Current->GetNextNode()){
            if (Current->GetData() == val) {
                return Current;
            }
        }
        return nullptr;
    }

    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* FindParent (CNode<T>* Maillon) const {
        // Trouver le parent de Maillon
        CNode<T> *CurrentParent = nullptr;
        for (CNode<T> *Current(this->m_Head); Current; Current = Current->GetNextNode()) {
            if (Maillon == Current) {
                return CurrentParent;
            }
            CurrentParent = Current;
        }
    }

    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>* Maillon){
        // Maillon -- Nouveau -- B
        // Nouveau pointe vers B
        CNode<T>* Nouveau = new CNode<T>(val, Maillon->GetNextNode());

        // Maillon pointe vers Nouveau
        Maillon->SetNextNode(Nouveau);
    }

    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>* Maillon){
        // Trouver le parent de Maillon
        CNode<T>* CurrentParent = nullptr;
        for (CNode<T>* Current(this->m_Head); Current; Current = Current->GetNextNode()){
            if (Maillon == Current) {
                CNode<T>* Parent = CurrentParent;
                Parent->SetNextNode(Current->GetNextNode());
            }
            CurrentParent = Current;
        }
        delete Maillon;
    }

    //ajout d'une valeur a la fin de la liste
    void push_back (const T & val){
        CNode<T>* temp = m_Tail;
        m_Tail = new CNode<T>(val, nullptr);
        temp->SetNextNode(m_Tail);
    }
};

#endif // LIST_HPP
