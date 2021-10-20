package exo1;

public class TypeComp {
    private Comp[] comparateurs;

    TypeComp (Comp[] comparateurs) {
        this.comparateurs = comparateurs;
    }

    public void comparer(String texte, String[] corpus, int thr) {
        for (Comp comp : comparateurs) {
            for (String strc : corpus) {
                if (comp.comparer(strc,texte)<= thr && comp.comparer(strc,texte)>= -thr) {
                    System.out.println ("PLAGIAT");
                    return;
                }
            }
        }
    }
}