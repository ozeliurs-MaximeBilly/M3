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

std::size_t donneTailleEnOctets(const std::string &comment,
                                const std::string &nomFichier) {
    struct stat S;
    if (comment == "char") {
      return 1;
    } else if (comment == "all") {
      nsSysteme::Stat(nomFichier.c_str(), &S);
      return S.st_size;
    } else if (comment == "block") {
      nsSysteme::Stat(nomFichier.c_str(), &S);
      return S.st_blksize;
    } else {
      return 0;
    }
}

using namespace nsSysteme; // Stat()
using namespace std;
int main (int argc, char * argv []) {
  if (argc != 4) {
    cerr << "Usage: " << argv[0] << " <option:all/char/block> " << " <nomDeFicherACopier> "
         << "<nomDeFichierDestination>\n";
    return(1);
  }
  try {
    int NbBytes = donneTailleEnOctets(argv[1], argv[2]);
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
  return 1;
}// main()
