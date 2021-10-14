public class CompCS implements Comp {
    public boolean comparer(String texte, String[] corpus, int thr) {
        for(String str:corpus) {
            if (texte.compareTo(str) < thr && texte.compareTo(str) < -thr){
                return true;
            }
        }
        return false;
    }
}