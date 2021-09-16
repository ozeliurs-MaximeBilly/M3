#include <iostream>
#include "Node.hpp"
#include "list.hpp"

using namespace std;

void ListeSimple (void)
{
    std::cout << "ListeSimple : \n\n";

    CNode<int>* Tete = nullptr;

    // Le dernier element cree est toujours le premier de la liste


    for (unsigned i (0); i < 5; ) {
        Tete = new CNode<int> (i++, Tete);
        std::cout << Tete << endl;
    }

    for (CNode<int>* Ptr (Tete); Ptr; Ptr = Ptr->GetNextNode ())
        std::cout << Ptr->GetData() << "; ";

    std::cout << '\n';

    // Dans cette version, le destructeur de C1Link detruit son
    //   suivant donc la destruction de la liste est recursive

    delete Tete;

}// ListeSimple ()

void ListeSimpleV2 ()
{
    cout << "ListeSimpleV2 : \n\n";

    CList<int> AList;

    // Le dernier element cree est toujours le premier de la liste

    for (unsigned i (0); i < 5; )
    {
        AList.push_front (i++);
    }

    AList.push_back(12);

    AList.Show ();

    AList.Delete(AList.Find(12));

    AList.Show ();

    AList.push_back(12);

    AList.Show();

}

int main(){
    //ListeSimple();
    ListeSimpleV2();
    return 0;
}
