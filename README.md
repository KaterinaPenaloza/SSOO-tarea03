# SSOO-tarea03
Autor: Katerina Peñaloza Caballería <br/>
Correo: katerina.penaloza@alumnos.uv.cl
## **NO LEER DE MOMENTO, ESTADO DE PRODUCCION**
## Trabajo realizado:
BIBLIOTECAS UTILIZADAS:
enunciado: Esta tarea tiene como objetivo introducirlo al manejo de procesos y uso de señales  en C++. Escriba un programa en C++17 que muestre por pantalla, la secuencia de Fibonacci y la serie de números impares ∑(2n-1). Para esto genere 2 procesos en paralelo que realicen la operación solicitada, de la siguiente manera:
1)	Un proceso padre deberá de mostrar la secuencia de Fibonacci y un proceso hijo deberá de mostrar la Serie de números impares. En el ejemplo que se ve a continuación el proceso padre 666 muestra la secuencia de Fibonacci {1,2,3,5,…} y el proceso hijo 667 muestra la serie de números impares {1,3,5,7,…}.
2)	El Código no puede parar su ejecución por ningún tipo de señal como se muestra en el siguiente recuadro (ninguna acción por consola debe detener el código: Ej: ctrl+C, ctrt+Z, ctrt+\). La única forma de que el código termine su ejecución es al completar 50 veces la iteración del ciclo o enviando una señal desde otra consola como se explica en el siguiente punto (3).
3)	Considera utilizar la sentencia this_thread::sleep_for(std::chrono::seconds(1))para controlar el tiempo de salida de los números.
3)	Para detener la ejecución deberá de abrir otra terminal y enviar la señal kill -s SIGUSR2 667 para poder detener al hijo o kill -s SIGUSR1 666 para detener al padre. Si uno de los procesos es detenido el otro deberá de continuar con su ejecución.

procedimiento: Para empezar se investigó acerca de la sucesión de fibonacci y la sumatoria de los numeros impares a través de https://es.wikipedia.org/wiki/Sucesi%C3%B3n_de_Fibonacci y conocimientos previos. 
se implementó el algoritmo en python xq es mi lenguaje favorito y es facil, me salio a la primera B|
se tradujo a c++ :/
utilize el ciclo while para mostrar los numeros por pantalla, ya que no vi otro modo de hacerlo, asi se me hizo mas facil en vez de usar recursion que ni se usarlo
lurego de tener esas  funciones listas se procede a hacer el resto, re facil
para que los procesos se ejecuten paralelamente, se hizo uso del fork()
para coordinarlos el chrono sleep o algo asi
se hizo un periodo de tsteo del programa

//20-11
https://en.wikipedia.org/wiki/Signal_(IPC)#Handling_signals  aqui dice que para handle las signals hay que usar signal(2) or sigaction(2) entonces asi se pudo handlear las señales SIGUSR1 y SIGUSR2 que antes no funcionaban porque hacian su accion por defecto pero ahora si se puede y funciona bien

eso.
finalmente se investigo acerca de los make y makefile que ni idea de eso, de hecho todavia  no se xd
