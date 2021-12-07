#include <string>
#include <fcntl.h>       // O_CREAT, open()
#include <sys/types.h>   // mode_t
#include <cstddef>       // size_t
#include "CExc.h"
#include "nsSysteme.h"

using namespace std;     // string

int nsSysteme::Open (const char * pathname, int flags, ::mode_t mode)
	// throw (CExc)
{
    int Res;
    if (!(flags & O_CREAT))
        throw CExc ("Open()",string (" fichier :") + pathname +
                       ". Un parametre de trop");
    if (-1 == (Res = ::open (pathname, flags, mode)))
        throw CExc ("open() ", string (" fichier :") + pathname);

    return Res;

} // Open()

int nsSysteme::Open (const char * pathname, int flags)
	// throw (CExc)
{
    int Res;
    if (flags & O_CREAT)
        throw CExc ("Open()",string (" fichier :") + pathname +
                    ". Il manque un parametre");
    if (-1 == (Res = ::open (pathname, flags)))
        throw CExc ("open() ", string (" fichier :") + pathname);

    return Res;

} // Open()


void nsFctShell::FileCopy (const char * const Destination, const char * const Source, const size_t NbBytes) {
  int src;
  // ouvre le fichier source en mode lecture à l'aide d'un appel système
  if ((src = nsSysteme::Open(Source, O_RDONLY)) == -1) { cout << "Erreur en lecture !!";} else {

    int dst;
    // ouvre le fichier destination en mode écriture, création et troncature l'aide d'un appel système
    if ((dst = nsSysteme::Open(Destination, O_WRONLY | O_CREAT, 0700)) == -1) { cout << "Erreur en ecriture !";} else {

      // réserve un tampon mémoire de NbBytes +1 octets
      unsigned char tampon[NbBytes+1];
      // tant qu'on peut lire du fichier source (i.e. l'appel système Read() n'est pas nul
      // lit (au plus) NbBytes octets dans le tampon
      while (nsSysteme::Write(dst, tampon, nsSysteme::Read(src, tampon, NbBytes))) {}
        cout << "success" << endl;
      // ferme enfin les deux fichiers l'aide d'appels système
      nsSysteme::Close(dst);
      nsSysteme::Close(src);
    }
  }
} // FileCopy()
