import numpy as np
import time

def Markov1Pas(state: int, transition_matrix: np.ndarray):
    r = np.random.rand()
    lst_cho = transition_matrix[state]
    x = 0
    for i in range(len(lst_cho)):
        if x < r < x + lst_cho[i]:
            return i
        else:
            x += lst_cho[i]


def TempsEtats(state: int, n: int, transition_matrix: np.ndarray):
    tps_passe = [0 for _ in range(len(transition_matrix[0]))]
    for i in range(n):
        state = Markov1Pas(state, transition_matrix)
        tps_passe[state] += 1
    return tps_passe


# On a la matrice de transition du hamster suivante
trans = np.array([[0, 0.7, 0.3], [0.05, 0.9, 0.05, ], [0, 0.8, 0.2]])
print("Matrice de transition du hamster:")
print(trans)

oldtrans = trans

for i in range(5):
    trans = np.matmul(oldtrans, trans)

print()
print("Matrice de transition du hamster puissance 5:")
print(trans)

trans = oldtrans

tm = time.perf_counter()
for i in range(99999):
    trans = np.matmul(oldtrans, trans)
tm = time.perf_counter() - tm

print()
print(f"Matrice de transition du hamster avec un très grand n en {tm}:")
print(trans)

print()
print("Vecteur d de la distribution invariante:")
print(trans[0])

trans = oldtrans

tm = time.perf_counter()
trans = np.linalg.matrix_power(trans, 99999)
tm = time.perf_counter() - tm

print()
print(f"Matrice de transition du hamster avec un très grand n en {tm}:")
print(trans)

trans = oldtrans

print()
print(Markov1Pas(2, trans))

print()
print("Comptage des etats consécutifs:")
print(TempsEtats(0, 100, trans))

lst = TempsEtats(0, 100, trans)
print()
print("Matrice a comparer a la distribution invariante:")
print([val/sum(lst) for val in lst])
