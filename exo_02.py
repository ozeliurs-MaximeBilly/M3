import numpy as np


def Markov1Pas(state: int, transition_matrix: np.ndarray):
    r = np.random.rand()
    lst_cho = transition_matrix[state]
    x = 0
    for i in range(len(lst_cho)):
        if x < r < x + lst_cho[i]:
            return i
        else:
            x += lst_cho[i]


def UnePartie(transition_matrix: np.ndarray):
    state = 0
    while True:
        state = Markov1Pas(state, transition_matrix)
        if state == 4:
            return 1
        elif state == 5:
            return 2

def PleinDeParties(n: int, transition_matrix: np.ndarray):

    pass


# Matrice de transition
trans = np.array([[0.5, 0.5, 0, 0, 0, 0], [0, 0, 0.5, 0.5, 0, 0], [0, 0, 0, 0.5, 0.5, 0], [0.5, 0, 0, 0, 0, 0.5], [0, 0, 0, 0, 1, 0], [0, 0, 0, 0, 0, 1]])
print("Matrice de transition:")
print(trans)

print()
print("Matrice de transition puissance 3:")
print(np.linalg.matrix_power(trans, 3))

print()
print("Simulation d'un jeu")
print(f"J{UnePartie(trans)} a gagné !!!")

print()
print("Simulation d'un grand nombre de parties")
sim = PleinDeParties(5000, trans)
print()





