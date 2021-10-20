package exo1;

public class Client {
    public static void main(String[] args) {

        String[] corpus = {
                "Rerum necessitatibus autem deleniti non dolor. Vel qui vitae qui corporis modi unde harum. Officiis aut odit modi voluptatem dolore ut. Quia in accusantium maxime deserunt laborum sint.",
                "Dolorem rerum ab blanditiis quia. Accusamus cum ut necessitatibus incidunt hic. Fugit quasi quaerat rerum distinctio id. Officiis et illum quo.",
                "Fugit tempore voluptatem illum dolorem similique ea velit culpa. Aut officiis modi dolor rem harum aperiam fugiat. Reprehenderit aspernatur ex harum est. Qui inventore voluptates qui eveniet dignissimos blanditiis totam quo. Asperiores architecto officiis sint sequi facilis. Aut repudiandae qui quo.",
                "Voluptatem laborum voluptatem reprehenderit omnis sapiente officia. Ducimus qui deleniti eum tempora velit cum. Possimus ducimus labore quibusdam cum. Sit est consequatur ipsa.",
                "Laudantium eius consequatur at voluptas. Atque voluptatem nihil eum ullam voluptatem. Voluptatem voluptatem architecto fuga ipsum quis at. Labore dolor voluptatibus ab esse id eius libero eius."
        };

        Comp[] comparaisons = {new CompCS(), new CompCIS()};
        TypeComp contexteCourant = new TypeComp(comparaisons);

        contexteCourant.comparer("Fugit tempore voluptatem illum dolorem similique", corpus, 200);
    }
}
