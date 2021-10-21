##Station météo

On veut faire une station météo sur un raspberry (fictif), qui récupère des données issues de différents capteurs (température, humidité dans l’air…) et qui affiche ces données sur différents écrans de la maison : PC, Montre connectée…
Pour cela, on implémente un petit programme codé en Java qui s’occupe de récupérer les données capteurs, puis de les afficher.

###Exo1 :
Dans un premier temps, on s’occupera de récupérer les données capteurs.
Faire un programme qui récupère les données des capteurs sur la station météo puis les afficher dans la console (ex : toutes les 10 secondes dans une boucle infinie).
→ Le code sera peut-être directement donné comme base de départ pour la suite

###Exo2 :
On va maintenant brancher trois écrans externes à la station météo. La station météo devra être capable de gérer trois écrans au lieu d’un seul comme précédemment. Ils afficheront (en mode console) les mêmes informations que dans l’exercice précédent. La station météo devra envoyer les données aux écrans lorsqu’au moins un des capteurs enverra une nouvelle valeur. Sinon, pas besoin de mettre à jour les écrans (économie d’énergie).

Les écrans seront de types différents afin qu’ils aient chacun une façon distincte d’afficher les informations (ex : ConsoleDisplay, KitchenDisplay, SmartphoneDisplay). Le bon sens voudrait qu’ils respectent le même contrat (interface ou classe abstraite  « Display » commune) :
Des variables internes correspondant aux informations capteurs (temperature, humidity, pressure)
Une fonction «update» pour mettre à jour ces variables internes
Une fonction « print » pour afficher le contenu de ces écrans

Implémenter le code correspondant.
Questions : Quels sont les défauts de cette implémentation ?
→ Classe WeatherStation figée à 3 écrans (« hardcodé »). Ajout ou suppression d’un écran = modification de la classe.

###Exo 3 :
Le but du jeu est de pouvoir avoir plus de libertés sur le nombre d’écrans à connecter à la station météo, sans avoir à changer le code de celle-ci.
Voici donc nos nouvelles spécifications :
On veut pouvoir ajouter ou enlever des écrans à la station météo au moment de l’exécution de l’application
La station météo doit notifier tous les écrans qui se sont connectés à elle dès lors (et uniquement dès lors) qu’une donnée capteur a changé

Faire le diagramme de classe de l’ensemble de l’application.
Implémenter le code.

###Exo 4 :
Maintenant que les écrans sont mis à jour en même temps que la station météo, on va rendre notre station météo un peu plus utile en connectant les systèmes de régulation de la température ou de la ventilation de la maison. Selon les équipements de votre logement on peut imaginer les appareils suivants : Chauffage, Climatisation, Ventilation… qui prendraient des décisions en fonction de la météo.
Refaire le diagramme de classes établi précédemment en prenant en compte ces nouveaux appareils.
Indice : plusieurs interfaces pourront être nécessaires, penser au principe de responsabilité unique.
Implémenter le code avec au moins un appareil, par exemple le chauffage : il devra agir en fonction d’une donnée capteur, par exemple s’allumer ou s’éteindre en fonction d’un seuil de température (on représentera ça simplement dans l’affichage console).
