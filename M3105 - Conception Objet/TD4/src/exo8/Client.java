package exo8;

public class Client {
    public static void main(String[] args) {
        Promotion promotion = new Promotion();

        promotion.addEtudiant(new Etudiant(1, "Haspekian", "Yvan"));
        promotion.addEtudiant(new Etudiant(0, "Jean-Alfred", "Richelieu"));
        promotion.addEtudiant(new Etudiant(12, "Billy", "Maxime"));
        promotion.addEtudiant(new Etudiant(69, "MDJ", "Martin"));
        promotion.addEtudiant(new Etudiant(42, "Margaillan", "Kylian"));

        for (Etudiant etu : promotion.triParNom()) {
            System.out.println(etu.getNom());
        }

        for (Etudiant etu : promotion.triParId()) {
            System.out.println(etu.getId());
        }
    }
}
