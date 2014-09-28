[![Build Status](https://travis-ci.org/nbouteme/OpenGL-Demo.svg?branch=master)](https://travis-ci.org/nbouteme/OpenGL-Demo)

OpenGL-Demo
===========

Démo pour les math.

## Dépendances

- Bibliothèque implémentant le standard OpenGL
- GLM
- SOIL
- GLEW
- GLFW

### Matériel

Le GPU doit supporter le standard OpenGL 3.3 (Disponible sur les GPU intégrés Intel avec les derniers pilotes, depuis au moins Sandy Bridge, le pilote libre nouveau pour GPU nVidia aussi <sub><sup>même si les performances sont terribles</sub></sup>, et les GPU intégrés sur les AMD-A4 bas de gamme)

Bref, vous n'avez aucune excuses.

Pour compiler:

Faire une fois:
`git clone https://github.com/nbouteme/OpenGL-Demo`

`cd OpenGL-Demo`
`mkdir build`
`cd build`
`cmake ..`

Puis à chaque modification du code:
`` make -j`nproc` ``
dans le répertoire "build"

## À faire

- [x] Implementer un parser de fichiers .obj (Sans support des textures et matériaux)
- [ ] Implementer les contrôles au clavier de manière plus souple.
- [ ] Dessiner les cristaux (1/3)
- [x] Écrire les shaders pour un éclairage basique.

### Et si on a le temps.

- [ ] Implémenter une shadow map
- [ ] Shaders
  - [ ] Translucidité
  - [ ] Reflets


## Support

En théorie, le projet est multi-plateforme, en pratique, il a été compilé seulement sous Ubuntu et Arch Linux.
Vous devriez arriver à compiler sous Windows avec un environnement type-Unix (a.k.a. MSYS2 ou Cygwin)

### Installer les dépendances sous Ubuntu ~~(a.k.a. pls halp imma noob)~~

Travis exécutant un script sur une machine virtuelle Ubuntu, vous pouvez vous référer au fichier .travis.yml pour une liste des commandes à taper dans un terminal.
Cela devrait suffire pour les dépendances.

Les utilisateurs de distributions plus avant-gardistes (lire: non basée sur Debian) peuvent se débrouiller :^)
