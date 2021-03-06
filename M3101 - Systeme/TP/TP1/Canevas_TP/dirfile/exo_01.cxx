/**
 *
 * @File : exo_01.cxx, Fichiers
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : la mise en place du main()
 *             et de la bibliotheque libSys
 *             fonction Stat() 
 *
 **/

#include <string>
#include <exception>

#include <sys/stat.h> // struct stat
#include "string.h"

#include "CExc.h"

#include "nsSysteme.h"  // Stat()

using namespace nsSysteme; // Stat()
using namespace std;
int main (int argc, char * argv []) {
  try {
  // a ecrire le corps de l'exercice 1
  }
  catch (const CExc & Exc) {
    cerr << Exc << endl;
    return errno;
  }
  catch (const exception & Exc) {
    cerr << "Exception : " << Exc.what () << endl;
    return 1;
  }
  catch (...) {
     cerr << "Exception inconnue recue dans la fonction main()" << endl;
     return 1;
  }
 }// main()

