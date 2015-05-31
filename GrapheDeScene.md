# Introduction #

Le graphe de scène a pour but de simplifier la création et la transformation d'objets OpenGL.

# Objets impliqués #

## `SceneElement` ##

Cette classe est la mère de toutes les autres classes. Elle peut également représenter des objects simples (sphères, cube, soucoupes volantes, etc).

  * `void _init(void)`
  * `void render(void)`
  * `void animate(int timerInterval)`

## `Scene` ##

Cette classe est la racine d'une scène OpenGL. Elle dérive de `SceneCompositeObject`.

  * `void _setCamera(void)`

## `SceneCompositeObject` ##

Cette classe représente un object composite : il possède des enfants de type `SceneObject`.

  * `void addChild(SceneElement element)`
  * `void removeChild(SceneElement element)`
  * `vector<SceneElement> getChildren(void)`

## `Transformation` ##

Cette classe applique une transformation aux objets sous sa responsabilité.

  * `void _transform(void)`