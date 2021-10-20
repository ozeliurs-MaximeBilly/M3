package exo1;

public class CompCIS implements Comp {
    public int comparer(String texte, String corpus) {
        if (texte.compareTo(corpus) < 0) {
            return -texte.compareToIgnoreCase(corpus);
        }
        return texte.compareToIgnoreCase(corpus);
    }
}