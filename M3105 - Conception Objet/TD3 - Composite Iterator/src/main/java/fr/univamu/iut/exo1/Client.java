public class Client {
    public static void main(String[] args) {
        Nombre nb1 = new Nombre(2);
        Nombre nb2 = new Nombre(3);
        Nombre nb3 = new Nombre(5);
        NoeudInterne op1 = new NoeudInterne('-', nb1, nb2);
        NoeudInterne op2 = new NoeudInterne('*', op1, nb3);

        double result = op2.calculerValeur();

        System.out.println(result);
    }
}
