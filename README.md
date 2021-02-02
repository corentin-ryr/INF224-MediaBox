
# INF224 - c++ project

## First part


## Jouer un media

On ne peut pas directement jouer un media dans la classe media car on a pas encore le type de fichier a ouvrir, la mehode pour l'ouvrir peut varier entre les types de fichier.
On crée donc une methode abstraite dans media. On definie cette methode dans les classe filles.
Apres cet ajout, on ne peut plus instancier de classe Media. Cela est du au fait que cette classe est maintenant abstraite.


## Faire une liste

Pour faire une liste pouvant contenir des images et des videos, on fait une liste contenant des media. Cependant, media est une classe abstraite, on doit donc faire une liste de pointeur de media. En Java, il n'aurait pas ete necessaire de passer par des pointeurs mais le reste aurait ete similaire.
Ce qui permet de faire cela est la propriété de polymorphisme.

## Classe film

Pour que l'objet ait le controle complet sur ses données de durée, on peut faire une copie du tableau lorsqu'on le recoit (avec le "new").

Lorsque l'on renvoit les données de Film par des accesseurs, il ne faut pas renvoyer directement l'adresse utilisée en interne dans la classe. On ajoute "const" devant le type de retour des getteurs pour eviter ce prbleme.

## Fuites de memoire

A chaque fois que l'on utilise "new" on prend de l'espace memoire qui ne sera pas rendu automatiquement a la destruction de l'instance de classe. Il faut donc ajouter des "delete" pour chaque variable d'instance créée de cette manière. <br>
Dans "Film" on supprime le tableau des durées.

Il y a deux type de copie, la copie superficielle et la copie profonde. Lorsque l'on fait une copie superficielle, on copie juste le pointeur, modifier le tzbleau original modifiera alors aussi le tableau copié. A l'inverse, une copie profonde copie chaque donnée du tableau, on a donc deux versions independantes du tableau.


## Empécher l'utilisation de "new" par une classe autre que MediaManager

On veut empécher la création d'un objet multimédia sans passer par MediaManager. Si on laisse l'utilisateur créer un film sans passer par MediaManager, on risque des fuites de memoire si la destruction de ces objets instancié hors manager sont mal détruit.
Pour cela, on met les constructeurs de chaque objet multimédia (images, video, film...) en privé et on ajoute la classe MediaManager en tant qu'ami.
On fait de même pour la classe Group.