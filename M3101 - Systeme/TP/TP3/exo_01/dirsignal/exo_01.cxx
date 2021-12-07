#include <string.h>
#include <exception>
#include <iostream>

#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set

#include "nsSysteme.h"
#include "CExc.h"


namespace {
  void Derout(int signum){
    std::cout << "Signal " << signum << " recu = " << strsignal(signum) << "." << std::endl;
  }
}

using namespace nsSysteme;
using namespace std;

int main(int argc, char * argv [])
{
  try {
    for(int i = 1; i<63 ; ++i) {
        Signal(i, Derout);
    }

  for(int i = 1; i<63 ; ++i) {
      if (i!=9 && i!=18 && i!=19){
        raise(i);
      }
  }


    return 0;
  }
  catch (const CExc & Exc) {
        cerr <<Exc<< endl;
        return errno;
  }
  catch (const exception & Exc) {
        cerr << "Exception : " << Exc.what () << endl;
        return 1;
  }
  catch (...) {
        cerr << "Exception inconnue recue dans la fonction main()"
             << endl;
        return 1;
  }


}  //  main()
