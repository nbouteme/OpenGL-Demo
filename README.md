[![Build Status](https://travis-ci.org/nbouteme/OpenGL-Demo.svg?branch=master)](https://travis-ci.org/nbouteme/OpenGL-Demo)

OpenGL-Demo
===========

Demo pour les math.

Pour compiler:

Faire une fois:
`git clone https://github.com/nbouteme/OpenGL-Demo`

`cd OpenGL-Demo`
`mkdir build`
`cd build`
`cmake ..`

Puis à chaque modification du code:
`` make -j`nproc` ``


## À faire

* Implementer un parser de fichiers .obj (Sans support des textures et materiaux)
* Implementer les contrôles au clavier de manière plus souple.
* Dessiner les cristaux
* Ecrire les shaders pour un éclairage basique.

### Et si on a le temps.

* Implementer une shadow map
* Shaders
  * Translucidité
  * Reflets
