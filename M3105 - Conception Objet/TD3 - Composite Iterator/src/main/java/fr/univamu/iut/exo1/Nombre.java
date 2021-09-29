public class Nombre extends Expression {

    private int valeur;

    /**
     * Default constructor
     */
    public Nombre(int valeur) {
        this.valeur = valeur;
    }


    /**
     * @return valeur
     */
    public double calculerValeur() {
        return valeur;
    }

}