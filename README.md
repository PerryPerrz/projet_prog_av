Projet Roguelite (Le donjon de Pupuce)
Thème Medieval-Fantasy

Règles du jeu :

    - Jeu composé de salles générées procéduralement s'enchainant et contenant des monstres à vaincre.
    - Le personnage avance de salle en salle en éliminant tous les monstres présents dans les salles, une fois arrivé à la dernière salle, il doit vaincre le dragon "Pupuce" pour finir le jeu.
    - Le personnage paut améliorer ses statistiques quand il vainc le boss, ses bonus sont sauvegardés pour la prochaine fois.
 
Commandes :

    - Le personnage avance avec 'z','q','s','d' ou les flèches directionnelles.
    - Le personnage attaque avec le clic gauche de la souris.
    - Le personnage attaque dans la direction du curseur de la souris.
    - La touche "echap" mets en pause le jeu.
    - Appuyer sur la croix permet de quitter le jeu.
    - Les commandes spécifiques sont écrites lors des écrans de chargement.

Personnage :

    - Le joueur possède une épée, de ce fait, il peut combattre uniquement en combat rapporché (Idée : Plusieurs types d'attaques représentés par des armes (fusil, épée, ...). Le joueur choisit son arme au début d'une partie.)
    - Le joueur débloque un bonus au choix en finissant une partie. Ces bonus sont cummulable jusqu'a un certain seuil. (ce qui, en théorie, rends la prochaine partie moins difficile.

Ennemis : 

    - Il y a 3 types de monstres et 1 boss :

    - Le slime :

        - Il se déplace constamment vers le joueur à une allure lente.
        - Il fait peu de dégats et possède un nombre moyen de point de vie. (5 points de dégats pour 100 points de vie)

    - Le Thwomp (la tête violette): 

        - Il se déplace verticalement à une vitesse élevée. (il rebondit sur les murs)
        - Il fait beaucoup de dégats mais à peu de point de vie.

    - Le Thados (la tourelle)

        - C'est une tourelle immobile qui tire des projectiles assez rapidement faisant un nombre moyen de dégats.
        - Ses projectiles ont une portée définie.
        - La tourelle à un nombre de point de vie plutôt élevée. (180 points de vie)

    - Pupuce :

    - Le boss de l'étage, c'est une dragonne.
    - Elle se déplace plutôt rapidement, possède beaucoup de point de vie et crache des flammes !
    - Faites attention, sa peau est robuste !
    - Pupuce étant un dragon, elle est bien plus forte qu'un être humain, pour lui infliger des dégats, il faut surtout viser le ventre et le dos ! 

     - Les monstres sont différents selon la salle où ils apparaissent (Plus on avance dans le jeu, plus la difficulté augmente)
     - Il y a une monstre spécifique par étage.

Les bonus : 

De base, la sauvegarde est nulle : aucun bonus ne sont attribués au début du jeu.
Si vous voulez tester les bonus, il vous suffit d'ouvrir le fichier sauvegarde.txt et de vous rajouter des bonus.
De ce fait, le jeu sera plus facile à terminer.

Compiler le jeu : 

Il vous suffit d'executer le Makefile préalablement remplit par nos soins : dans le terminal, il faut compiler les fichiers nécessaires à notre jeu en éxecutant la commande "make". Une fois le fichier éxecutable créer, il suffit de l'exécuter en rentrant la commande "./main" dans le terminal. Les indications et les régles du jeu suivront, bonne chance ! 

Idées non réalisées par manque de temps / trop compliqué à implémenter : 

- Objets :
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
    
- Eventualité d'un mode coopération à 2 joueurs

- Plusieurs étages avec des boss différents, monstres différents, récompenses différentes...

- Des pièges (sur le sol)

- Différentes armes pour le joueur.
