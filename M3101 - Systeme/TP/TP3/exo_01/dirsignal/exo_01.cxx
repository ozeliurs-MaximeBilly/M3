#include <string.h>
#include <exception>
#include <iostream>

#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set

#include "nsSysteme.h"
#include "CExc.h"


namespace {
  int Derout(int signum){
    std::cout << "Signal " << signum << " recu = " << strsignal(signum) << "." << std::endl;
  }
}

using namespace nsSysteme;
using namespace std;

int main(int argc, char * argv [])
{
  try {

    Signal(2, Derout);

    raise(SIGINT);

///code
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
