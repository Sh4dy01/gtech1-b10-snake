# Snake version Dragon Ball 

## Les règles sont simples :

- Le but est de diriger notre dragon **Shenron** afin de récupérer les **7 boules de Cristal** (boules jaunes).
    Chaque boule récupérée est déposée dans votre **Collection**.

**MAIS ATTENTION !**

À chaque **boule de Cristal** récupérée, une **boule Maléfique** apparaît (boule rouge).
Ainsi, plus on récupère de **boule de Cristal**, plus il y a de **boule maléfique** sur le terrain.

À vous de les éviter sinon **GAME OVER**.


- Une fois les **7 boules de Cristal** récupérées, deux choix s'offrent à vous : 
    - Continuer à récupérer les boules afin de faire monter votre **Score**.
    - Récupérer la **boule Exit** (boule verte) et passer au **niveau de difficulté** suivant.

- À chaque **niveau** passé, vos points gagnés par **boule de Cristal** récupérée double tout comme le nombre de **boule maléfique**.


## Pour lancer le jeu sous Linux :

1. Tout d'abord, vous devez avoir installer un système d'exploitation Linux sous Windows comme Debian via le Microsoft Store et créer un compte.
2. Ensuite, installer les librairies suivantes :
```
sudo apt-get update
sudo apt-get install make g++ git libsdl2-dev libsdl-ttf2.0-dev
```
3. Télécharger le jeu via GitHub :
```
git clone https://github.com/Sh4dy01/gtech1-b10-snake.git snake
```
4. Aller dans le répertoire du jeu :
```
cd snake
```
4. Lancer le jeu :
```
make run
```
*Good Luck & Have Fun*

---
### **À propos du projet :**

Ce projet #7 proposé par [Nicolas BERCHER](https://www.linkedin.com/in/nicolas-bercher), intervenant du [Gaming Campus](https://gamingcampus.fr/) nous a permis de découvrir pendant 4 semaines intenses : 
- Le langage de programmation **C++** & sa gestion mémoire
- Une utilisation approfondie de **Git & GitHub**
- Les outils sous **Linux** (Make, G++, Git)
- Une librairie graphique (**SDL2**)
- **Visual Code sous WSL**