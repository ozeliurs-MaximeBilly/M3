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
  struct stat sb;
  try {
    stat(argv[1], &sb);
    printf("Type de Fichier:\n");
    printf("\tFichier : %s\n", ((bool)S_ISREG(sb.st_mode)) ? "Oui" : "Non");
    printf("\tRépertoire : %s\n", (S_ISDIR(sb.st_mode)) ? "Oui" : "Non");
    printf("\tLien Symbolique : %s\n", (S_ISLNK(sb.st_mode)) ? "Oui" : "Non");
    printf("\tPériphérique : %s\n", (S_ISCHR(sb.st_mode)) ? "Oui" : "Non");
    printf("\tFIFO : %s\n", (S_ISFIFO(sb.st_mode)) ? "Oui" : "Non");
    printf("\tSocket : %s\n", (S_ISSOCK(sb.st_mode)) ? "Oui" : "Non");
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

