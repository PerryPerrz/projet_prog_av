Projet Roguelite (Nom du jeu à définir)
Thème Medieval-Fantasy

Règles du jeu :

    - Jeu composé de salles générée procéduralement s'enchainant et contenant des monstres à vaincre.
    - Le personnage avance de salle en salle en éliminant tous les monstres présents dans les salles, une fois arrivé à la dernière salle, il doit vaincre le dragon "pupuce" pour finir le jeu.
    - Le personnage paut améliorer ses statistiques quand il bat le boss, ces bonus sont sauvegardés pour la prochaine fois.
 

Commandes :

    - Le personnage avance avec 'z','q','s','d' ou les flèches directionnelles.
    - Le personnage attaque avec le clic gauche de la souris.
    - Le personnage attaque dans la direction du curseur de la souris.
    - La touche "echap" mets en pause le jeu
    - Appuyer sur la croix  permet de quitter le jeu

Personnage :

    - Plusieurs types d'attaques représentés par des armes (fusil, épée, ...). Le joueur choisit son arme au début d'une partie.
    - Le joueur débloque les différents type d'armes et certains bonus en faisant des parties.

Objets :

    - Bonus (2 types) : 

        - Bonus Actif :

            - Le personnage ne peux tenir qu'un seul bonus actif à la fois.
            - Une fois activé, il ne peux être réactivé avant une certaine durée.
            - Effet possible : augmentation des statistiques de base du personnage pour une durée limitée.
            - Effet possible : execution d'une attaque puissante

        - Bonus passif :

            - Il n'y a pas de limite au nombre de bonus passif que le personnage peut tenir.
            - Les effets sont activés au moment où le bonus est ramassé et restent actif pendant toute la durée de la partie.

    - Consommables :

        - Potions :

            - Les potions apportent des bonus immédiats 
            - Effet possible : augmentation ou diminution des statistiques de base du personnage pour toute la durée de la partie.
            - Effet possible : changement de statut positif ou néfaste pour une courte durée (plus rapide, poison, ...).

        - Clés :

            - Les clés apparaissent une fois par étage et permettent d'accèder à la salle du Boss.
            - Les clés apparaissent quand le joueur finit une certaine salle déterminée aléatoirement au début de l'étage.

Ennemis : 

    - Utilsation du pathfinding pour se diriger vers le joueur
    - Monstres différents selon la salle et l'étage où ils apparaissent
    - Présence de Boss qui sont des monstres spéciaux apparaissant à des endroits fixes et qui sont bien plus fort que des monstres normaux
    - Apparition de monstres d'élites peu fréquente (monstres normaux ayant des statistiques plus grandes)


Mechaniques spéciales :

    - Possibilité de flotter et donc d'éviter les trous ou pièges du sol (joueur et monstres)
    - Eventualité d'un mode coopération à 2 joueurs