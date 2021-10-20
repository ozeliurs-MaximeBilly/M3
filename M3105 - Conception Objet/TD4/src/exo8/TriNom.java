package exo8;

import java.util.ArrayList;

public class TriNom implements Tri {
    public static ArrayList<Etudiant> trier(ArrayList<Etudiant> etudiants) {
        etudiants.sort(Etudiant.NomComparator());
        return etudiants;
    }
}
