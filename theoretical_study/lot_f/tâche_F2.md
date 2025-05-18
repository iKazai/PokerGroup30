# Tâche F.2 — Étude théorique des gains en première manche, stratégies pures

## Hypothèses

- J1 a la main (1,2) et parie (V) → elle joue la carte de valeur 2.
- J2 parie (D) → elle joue la carte de plus **basse** valeur.
- Distribution conditionnelle de la main de J2 donnée par la tâche C.5 :

| Main J2       | Probabilité |
|---------------|-------------|
| (1,2)         | 1/6         |
| (1,3)         | 2/6         |
| (2,3)         | 2/6         |
| (3,3)         | 1/6         |
| (1,1)         | 0           |
| (2,2)         | 0           |

## Résultats pour chaque main

### (1,2) : J2 joue 1

- J1 joue 2 et J2 joue 1 → (G^1_1,G^1_2)=(1,0)

### (1,3) : J2 joue 1

- J1 joue 2 et J2 joue 1 → (G^1_1,G^1_2)=(1,0)

### (2,3) : J2 joue 2

- J1 joue 2 et J2 joue 2 → (G^1_1,G^1_2)=(0,0)

### (3,3) : J2 joue 3

- J1 joue 2 et J2 joue 3 → (G^1_1,G^1_2)=(0,1)

## Loi de (G^1_1,G^1_2)

| (G^1_1,G^1_2) | Probabilité |
|------------|-------------|
| (1,0)      | 3/6         |
| (0,0)      | 2/6         |
| (0,1)      | 1/6         |

## Lois marginales

### G^1_1

- P(1) = 3/6
- P(0) = 3/6

### G^1_2

- P(1) = 1/6
- P(0) = 5/6

## Espérances des gains des deux joueurs

- E[G^1_1] = 3/6 = 0.5
- E[G^1_2] = 1/6 ≈ 0.167
