# get_next_line

Projet de l’école **42** : implémenter une fonction en C capable de lire **une ligne complète à la fois** à partir d’un descripteur de fichier, quelle que soit sa taille.  
La fonction doit gérer la lecture de manière efficace grâce à un **buffer** et être capable de lire depuis différents types de FD (fichiers, stdin, pipes…).

---

## Objectifs du projet

- Apprendre à manipuler les **descripteurs de fichiers**.
- Comprendre et utiliser les fonctions systèmes :
  - `read`
  - `malloc` / `free`
- Gérer des **buffers dynamiques** et les découpages de chaînes.
- Rendre une fonction réutilisable et robuste.

---

## Fonctionnalités

- Fonction prototype obligatoire :

```c
char *get_next_line(int fd);
```
---

Compilation
Exemple de commande pour compiler (avec BUFFER_SIZE = 42) :
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
Pour le bonus :
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl
```

Exécution :
```bash
./gnl
```
