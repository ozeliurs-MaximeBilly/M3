package exo8;

import java.util.ArrayList;

public class TriId implements Tri {
    public static ArrayList<Etudiant> trier(ArrayList<Etudiant> etudiants) {
        etudiants.sort(Etudiant.IdComparator());
        return etudiants;
    }
}
