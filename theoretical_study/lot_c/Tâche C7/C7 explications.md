# Tâche C7 — Histogramme et Graphe

Pour effectuer la tâche **C7**, nous l'avons divisée en deux parties :

---

## Partie 1 : Histogramme

Pour la partie **Histogramme**, afin de pouvoir utiliser la fonction `P_approx_2_1(1,2,n)`, nous avons créé un programme en C (`C7_histogramme.c`) qui génère toutes les mains aléatoires du joueur J2.  
Ces résultats ont été écrits dans un fichier intermédiaire.

Nous avons ensuite importé ce fichier dans **Google Sheets** pour afficher les courbes.

L'objectif était d'obtenir \( n = 10\,000 \) mains pour avoir un résultat plus précis, mais le programme s'est arrêté à **2 712** mains différentes pour le joueur **J2**.  
Nous avons donc tracé les histogrammes pour cette valeur de \( n = 2\,712 \).

---

Nous avons comparé :
- La **fréquence pratique** des mains (calculée à partir des simulations),
- à la **fréquence théorique** (calculée grâce aux probabilités déterminées lors de la tâche C5).

On remarque déjà que les valeurs sont à peu près similaires.

Voici le tableau utilisé :

![Tableau des mains](<Capture d’écran 2025-04-27 à 16.09.21.png>)

Puis nous avons tracé l'histogramme correspondant :

![Histogramme](<Capture d’écran 2025-04-27 à 16.13.09-1.png>)

---

### Analyse

On observe que :
- Les barres bleues (**fréquence pratique**) sont très proches des barres rouges (**fréquence théorique**).
- Cela indique que la **loi empirique** obtenue par simulation correspond bien à la **loi théorique**.
- De petites différences subsistent, dues aux **fluctuations aléatoires** (le nombre d'essais \( n \) est grand mais pas infini).

---

## Partie 2 : Graphe

Pour la partie **Graphe**, afin de pouvoir utiliser la fonction `P_approx_2_1_main(1,2,n)`, nous avons créé un second programme en C (`C7_graphe.c`).  
Ce programme génère, pour chaque \( n \), la valeur de l'approximation, et enregistre les résultats dans un fichier intermédiaire.

Nous avons ensuite importé ce fichier dans **Google Sheets** pour afficher le graphe.

Cette fois, nous avons bien obtenu \( n = 10\,000 \) simulations.  
Nous avons ainsi pu tracer le **nuage de points** pour cette valeur de \( n \).

Nous avons également superposé la droite d'équation :


y = $\mathbb P(C^2_1,C^2_2 = (2,3) | C^1_1,C^1_2 = (1,2))$

(calculée en tâche C5).

Voici le graphe obtenu :

![Graphe](<Capture d’écran 2025-04-27 à 15.50.31.png>)

---

### Analyse

On remarque que :
- Lorsque \( n \) est petit, la valeur de `P_approx_2_1_main(1,2,n)` fluctue beaucoup.
- Lorsque \( n \) devient grand, la valeur se stabilise autour d'une **valeur fixe** (la probabilité théorique \( = \frac{2}{6} \)) avec de **moins en moins de fluctuations**.
- On voit bien que le **nuage de points converge** vers la droite \( y \), ce qui montre que **l'estimateur est validé**.

---
