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
#include <fcntl.h>
#include "string.h"

#include "CExc.h"

#include "nsSysteme.h"  // Stat() Open Close Read Write

namespace {
  std::size_t donneTailleEnOctets(const std::string &comment, const std::string &nomFichier) {
    struct stat sb;
      nsSysteme::Stat(nomFichier.c_str(), &sb);
    
    if (comment == "char"){
      return 1;
    }

    if (comment == "all") {
      return sb.st_size;
    }

    if (comment == "block") {
      return sb.st_blksize;
    }
  }
}

using namespace nsSysteme; // Stat()
using namespace std;

int main (int argc, char * argv []) {
  
  if (argc != 4) {return -1;}
  //cout << argv[1] << argv[2] << argv[3] << endl;

  try {
    size_t NbBytes = donneTailleEnOctets(argv[1], argv[2]);

    //cout << NbBytes << endl;

    nsFctShell::FileCopy(argv[3], argv[2], NbBytes);
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
}

