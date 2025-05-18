# Tâche F.6 — Étude théorique des stratégies mixtes en première manche

## Hypothèses

- J1 a la main (2,3).
- J1 parie (V) avec probabilité p₁, donc J1 joue 3 si elle parie (V), 2 sinon (J1 parie (D)).
- J2 parie (V) avec probabilité q₁, donc joue sa carte haute si (V), donc joue sa carte basse sinon (J2 parie (D)).
- Loi de la main de J2 conditionnée à (2,3) :

| Main J2       | Probabilité |
|---------------|-------------|
| (1,1)         | 1/6         |
| (1,2)         | 2/6         |
| (1,3)         | 2/6         |
| (2,3)         | 1/6         |
| (2,2)         | 0           |
| (3,3)         | 0           |

## Cas détaillés

- (1,1) :
  - J2 joue 1 quel que soit le pari → J1 gagne toujours → gain J1 = 1
- (1,2) :
  - J2 joue (V) → J2 joue 2 → J1 :
    - joue (V) → 3 > 2 → gain J1 = 1
    - joue (D) → 2 = 2 → gain J1 = 0
  - J2 joue (D) → joue 1 → J1 gagne toujours → gain J1 = 1
- (1,3) :
  - J2 joue (V) → 3 vs 3 → gain J1 = 0
  - J2 joue (D) → joue 1 → J1 gagne toujours → gain J1 = 1
- (2,3) :
  - J2 joue (V) → 3 vs 3 → gain J1 = 0
  - J2 joue (D) → joue 2 → J1 :
    - joue (V) → 3 > 2 → gain J1 = 1
    - joue (D) → 2 = 2 → gain J1 = 0

## Espérance de gain de J1

**Espérance de gain de J1** :

 $\mathbb \ E[G^1_1](p₁, q₁) = \frac{1}{6} * 1 + \frac{2}{6} * (q₁ * p₁ + (1 - q₁)) + \frac{2}{6} * (1 - q₁) + \frac{1}{6} * (q₁·p₁)$

 $\mathbb \  =  \frac{1}{6} + \frac{1}{3}*(q₁ * p₁ + 1 - q₁) + \frac{1}{3}*(1 - q₁) + \frac{1}{6}(q₁ * p₁)$

$\mathbb \ = \frac{1}{2} * q₁ * p₁ +  \frac{1}{6} +  \frac{2}{3}*(1 - q₁)$

## Meilleure réponse de J1

Maximiser \(  $\mathbb \ E[G^1_1]$ \) en \( p₁ \), c’est une fonction affine → max pour :

- \( p₁ = 1 \) si \( q₁ > 0 \)
- \( p₁ ∈ [0,1] \) si \( q₁ = 0 \)

## Meilleure réponse de J2

On calcule \(  $\mathbb E[G^1_2](p₁, q₁) = 1 - E[G^1_1](p₁, q₁)$ \) (jeu à somme nulle)

Maximiser en \( q₁ \) : c’est une fonction affine décroissante si \( p₁ > 0 \), donc :

- \( q₁ = 0 \) si \( p₁ > 0 \)
- \( q₁ ∈ [0,1] \) si \( p₁ = 0 \)

## Équilibre de Nash

On vérifie si \( (p₁^*, q₁^*) = (1, 0) \) est un point fixe :

- p₁ = 1 est la meilleure réponse à q₁ = 0
- q₁ = 0 est la meilleure réponse à p₁ = 1

(p₁^*, q₁^*) = (1, 0) est donc un équilibre de Nash.
