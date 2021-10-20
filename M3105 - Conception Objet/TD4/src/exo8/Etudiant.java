package exo8;

import java.util.Comparator;

public class Etudiant {
    int id;
    String Nom;
    String Prenom;
    public static Comparator<Etudiant> IdComparator() {
        return new Comparator<Etudiant>() {
            @Override
            public int compare(Etudiant o1, Etudiant o2) {
                return o1.getId() - o2.getId();
            }
        };
    };

    public static Comparator<Etudiant> NomComparator() {
        return new Comparator<Etudiant>() {
            @Override
            public int compare(Etudiant o1, Etudiant o2) {
                return o1.getNom().compareTo(o2.getNom());
            }
        };
    };

    public Etudiant(int id, String Nom, String Prenom)
    {
        this.id = id;
        this.Nom = Nom;
        this.Prenom = Prenom;
    }

    public int getId() { return id; }

    public String getNom() { return Nom; }
}
