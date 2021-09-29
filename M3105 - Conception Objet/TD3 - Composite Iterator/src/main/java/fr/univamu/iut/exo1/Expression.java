public abstract class Expression {

    private char operateurBinaire;
    private Expression premierOp, secondOp;

    /**
     * @return
     */
    public abstract double calculerValeur();
}