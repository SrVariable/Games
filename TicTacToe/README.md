# TicTacToe

El juego TicTacToe (o 3 en raya) es un juego que consiste en que dos jugadores van marcando con 'x' o 'o' un tablero 3x3 de manera alternada. El juego termina cuando uno de los jugadores consigue hacer una línea de 3 símbolos iguales.

## Uso

Para probar el juego primero debes clonar el repositorio
```Bash
git clone https://github.com/SrRecursive/Games.git
```
Luego habrá que ir a la carpeta TicTacToe
```Bash
cd TicTacToe
```
Obtener el ejecutable
```Bash
make
```
Y para jugarlo
```Bash
make run
```

## Bugs

El código solamente utiliza las funciones write, read, malloc y free para añadir complejidad al programa, es por eso que tiene bugs si no se juega correctamente.

Si introduces un input inesperado el juego explotará y tendrás que pulsar **Ctrl + C** para salir del programa.
