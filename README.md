[![Build Status](https://travis-ci.org/nbouteme/OpenGL-Demo.svg?branch=master)](https://travis-ci.org/nbouteme/OpenGL-Demo)

OpenGL-Demo
===========

Demo pour les math.

## Dépendences

- Bibliotheque implemantant le standard OpenGL
- GLM
- SOIL
- GLFW

Pour compiler:

Faire une fois:
`git clone https://github.com/nbouteme/OpenGL-Demo`

`cd OpenGL-Demo`
`mkdir build`
`cd build`
`cmake ..`

Puis à chaque modification du code:
`` make -j`nproc` ``
dans le repertoire "build"

## À faire

- [x] Implementer un parser de fichiers .obj (Sans support des textures et materiaux)
- [ ] Implementer les contrôles au clavier de manière plus souple.
- [ ] Dessiner les cristaux (1/3)
- [x] Ecrire les shaders pour un éclairage basique.

### Et si on a le temps.

- [ ] Implementer une shadow map
- [ ] Shaders
  - [ ] Translucidité
  - [ ] Reflets


## Support

En théorie, le projet est multi-plateforme, en pratique, il a été compiler seulement sous Ubuntu et Arch Linux.

### Installer les dépendences sous Ubuntu

Travis éxècutant un script sur une machine virtuelle Ubuntu, vous pouvez vous réferer au fichier .travis.yml pour une liste des commandes à taper dans un terminal.
Cela devrait suffire pour les dépendances.

Les utilisateurs de distributions plus avant-gardistes (lire: non basée sur Debian) peuvent se débrouiller :^)
