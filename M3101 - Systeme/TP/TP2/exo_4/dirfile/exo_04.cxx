#include <string>
#include <exception>

#include <sys/stat.h> // struct stat
#include <fcntl.h>
#include "string.h"
#include <unistd.h>

#include "CExc.h"

#include "nsSysteme.h"  // Stat() Open Close Read Write

using namespace nsSysteme; // Stat()
using namespace std;

int main (int argc, char * argv []) {
  try {
    struct stat sb;
    nsSysteme::Stat("./donnees.fic", &sb);

    unsigned char tampon[100];
    int src = Open("./donnees.fic", O_RDONLY);
    Read(src, tampon, sizeof(char));
    cout << tampon[0] << endl;

    Read(src, tampon, sizeof(char));
    int len = int(tampon[0]);
    cout << len << endl;

    Read(src, tampon, 3+len);
    for(int i = 0; i < 3+len ; ++i) {
      cout << tampon[i];
    }
    cout << endl;

    while (Read(src, tampon, 1)) {
      cout << tampon[0];
    }
    cout << endl;

    cout << "Je fais qqch" << endl;

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
