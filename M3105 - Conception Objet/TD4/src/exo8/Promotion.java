package exo8;

import java.util.ArrayList;

public class Promotion {
    private ArrayList<Etudiant> etudiants;

    Promotion() {
        etudiants = new ArrayList<Etudiant>();
    }

    public void addEtudiant(Etudiant etu) {
        etudiants.add(etu);
    }

    public ArrayList<Etudiant> triParId() {
        return TriId.trier(this.etudiants);
    }

    public ArrayList<Etudiant> triParNom() {
        return TriNom.trier(this.etudiants);
    }
}
