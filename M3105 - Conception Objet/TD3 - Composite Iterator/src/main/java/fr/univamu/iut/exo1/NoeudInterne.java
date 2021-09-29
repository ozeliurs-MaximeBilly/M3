public class NoeudInterne extends Expression {

    private char operateurBinaire;
    private Expression premierOp, secondOp;

    public NoeudInterne(char operateurBinaire, Expression premierOp, Expression secondOp) {
        this.operateurBinaire = operateurBinaire;
        this.premierOp = premierOp;
        this.secondOp = secondOp;
    }

    public double calculerValeur() {
        if (operateurBinaire == '+') {
            return premierOp.calculerValeur() + secondOp.calculerValeur();
        } else if (operateurBinaire == '-') {
            return premierOp.calculerValeur() - secondOp.calculerValeur();
        } else if (operateurBinaire == '*') {
            return premierOp.calculerValeur() * secondOp.calculerValeur();
        } else if (operateurBinaire == '/') {
            return premierOp.calculerValeur() / secondOp.calculerValeur();
        } else if (operateurBinaire == '%') {
            return premierOp.calculerValeur() % secondOp.calculerValeur();
        }
        return 0.0d;
    }

}