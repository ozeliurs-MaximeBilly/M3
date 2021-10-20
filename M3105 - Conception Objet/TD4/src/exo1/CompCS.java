package exo1;

public class CompCS implements Comp {
    public int comparer(String texte, String corpus) {
        if (texte.compareTo(corpus) < 0) {
            return -texte.compareTo(corpus);
        }
        return texte.compareTo(corpus);
    }
}
