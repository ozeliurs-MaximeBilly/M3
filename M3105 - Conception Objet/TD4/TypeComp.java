public class TypeComp {
    private Comp comparateur;

    public boolean comparer(String texte, String[] corpus, int thr) {
        return comparateur.comparer(texte, corpus, thr);
    }

    public void changerComp(Comp comparateur) {
        this.comparateur = comparateur;
    }

    public Comp retournerComp() {
        return comparateur;
    }
}