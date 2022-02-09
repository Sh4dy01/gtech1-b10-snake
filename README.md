# Snake - Dragon Ball version

## Les règles sont simples :

- Le but étant de diriger notre dragon **Shenron** afin de récupérer les **7 boules de Cristal** (boules jaunes).
    Chaque boule récupérée est déposée dans votre **Collection**.

**MAIS ATTENTION !** A chaque **boule de Cristal** récupérée, une **boule Maléfique** apparaît (boule rouge).
    Ainsi, plus on récupère de **boule de Cristal**, plus il y a de **boule Maléfique** sur le terrain.
    A vous de les éviter sinon **GAME OVER**.

- Une fois les **7 boules de Cristal** récupérées, deux choix s'offrent à vous : 
    1. Continuer à récupérer les boules afin de faire monter votre **Score**.
    2. Récupérer la **boule Exit** (boule verte) et passer au **Level** suivant.

- A chaque **Level** passé, vos points gagnés par **boule de Cristal** récupérée double. Mais le nombre de **boule Maléfique** double aussi !

- Votre **Score** est mémorisé à chaque fin de partie **(Highscore)** et à chaque fois que vous récupérer une **boule Exit**.


## Pour lancer le jeu (Linux) :
1. Il vous faudra tout d'abord installer les librairies suivantes :
```
sudo apt-get update
sudo apt-get install make g++ libsdl2-dev libsdl-ttf2.0-dev
```

2. Puis lancer la commande :
```
make run
```

3. Utiliser les *flèches du clavier* pour vous diriger.

**A vous de jouer !**