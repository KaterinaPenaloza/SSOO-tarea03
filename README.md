# SSOO-tarea03
Autor: Katerina Peñaloza Caballería <br/>
Correo: katerina.penaloza@alumnos.uv.cl
## Trabajo realizado:
1) Bibliotecas utilizadas: iostream, fstream, future, thread, chrono, csignal, unistd.h, sys/types.h, sys/syscall.h, stdio.h, stdlib.h, string.h, sys/wait.h.
2) Enunciado: Escribir un programa en c++ que muestre por pantalla, la secuencia de Fibonacci y la serie de números impares a través de dos procesos en paralelo que lo realicen de la siguiente manera: un proceso padre mostrará la secuencia de Fibonacci y un proceso hijo mostrará la serie de números impares, sin embargo, el Código no puede parar su ejecución por ningún tipo de señal (específicamente ctrl+C, ctrt+Z, ctrt+\). La única forma de que el código termine su ejecución es al cumplir 50 iteraciones o enviar la señal kill -s SIGUSR2 667 para poder detener al hijo o kill -s SIGUSR1 666 para detener al padre. Si uno de los procesos es detenido el otro deberá de continuar con su ejecución.
3) Procedimiento:
- Para empezar se investigó acerca de la sucesión de fibonacci y la sumatoria de los numeros impares a través de internet y conocimientos previos. Luego se implementaron los algoritmos en python ya que es un lenguaje que se me hace más facil que c++ y lo "traduje" a c++.
- Después utilizé el ciclo while para mostrar los numeros por pantalla y tener la cuenta de las iteraciones que se realizan para que al llegar a 50 iteraciones termine automáticamente autoinvocando a los procesos la señal SIGTERM con la función raise(). Además para controlar la salida de los números por pantalla se hizo uso de la función this_thread::sleep_for(std::chrono::seconds(1)).
- Para que los procesos se ejecuten paralelamente, al principio se pensó en hacer uso de threads para tener un "verdadero paralelismo", pero decidí finalmente utilizar fork(), ya que de la otra manera se estaba haciendo muy dificil de implementar. Para implementar el fork() en el código usé como referencia los ejemplos entregados por el profesor en clases.
- Finalmente para el control de señales, se creó una función llamada signal_handler que toma como parámetro la señal recibida y con un switch case, dependiendo de que señal se pasó como parámetro se maneja de una u otra forma. En el caso de las señales enviadas por teclado (ctrl+C, ctrt+Z, ctrt+\), se cambia su acción por defecto por un mensaje que se muestra por pantalla que indica que la detención del programa no está permitida. Para atrapar las señales se utilizó la función signal(). En las señalas definidas por el programador (SIGUSR1 y SIGUSR2) se utilizó la función sigaction() ya que con la función signal() no atrapaba las señales y se ejecutaban sus acciones por defecto que es detener el programa igualmente, por eso para asegurarme que se está ejecutando lo que yo definí en el código hice que antes de invocar la señal de término, imprima un mensaje por pantalla mostrando el nombre de la señal (SIGUSR1 o SIGUSR2) y el pid del proceso.
*En esto último la mayoria de información la obtuve de https://en.wikipedia.org/wiki/Signal_(IPC).*
4) Conclusión y comentarios finales (leer opcional): Como conclusión quiero destacar que aprendí mucho más sobre los procesos y señales y fue muy divertido investigar acerca de todo esto y ver todas las cosas que se pueden hacer. Sin embargo me hubiera gustado sincronizar los procesos que actuaban en paralelo usando mutex, además de que el proceso que muestra los numeros impares termina primero que el de fibonacci, lo que considero un problema, en esto no pude hacer lo que normalmente se haría con los procesos padres e hijos (utilizar wait()) porque simplemente no funcionaba el programa como era esperado. Creo que lo más dificil fue crear el makefile pero luego de un día completo tratando de entender su funcionamiento y creación, finalmente lo pude entender completamente, incluso me atrevo decir que me convertí en una experta en makefiles y si no hubiera sido porque era un requerimiento en esta tarea creo que nunca me hubiera dado el tiempo de entender eso.
