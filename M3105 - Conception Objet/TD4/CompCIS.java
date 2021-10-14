public class CompCIS implements Comp {    
    public boolean comparer(String texte, String[] corpus, int thr) {
        for(String str:corpus) {
            if (texte.compareToIgnoreCase(str) < thr && texte.compareToIgnoreCase(str) < -thr){
                return true;
            }
        }
        return false;
    }
}