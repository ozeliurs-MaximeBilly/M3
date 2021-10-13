package fr.univamu.iut.exo2;

public class Circuit extends Composant {

    private List<Composant> mesComposants

    public Circuit(){
        mesComposants = new ArrayList<>;
    }

    public Acceder(){
        return mesComposants;
    }

    public AjouterComposant(Composant comp){
        mesComposants.add(comp)
    }

    public SupprimmerComposant(Composant comp){
        for (Iterator<String> iter = mesComposants.listIterator(); iter.hasNext(); ) {
            Composant a = iter.next();
            if (comp.equals(a)) {
                iter.remove();
            }
        }
    }

    public Executer(){
        for (Composant comp : mesComposants) {
            comp.Executer();
        }
    }
}