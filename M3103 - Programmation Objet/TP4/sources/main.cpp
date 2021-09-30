using namespace std;

#include "CRDTree.hpp"

int main() {
    CRDTree<int> test(1);
    test.add(5);
    test.add(3);
    test.add(6);
    test.show();
    std::cout << test.find(5) << "\n";
}
