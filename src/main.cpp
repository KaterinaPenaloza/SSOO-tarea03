#include <iostream>    // for cout
#include <fstream>
#include <future>
#include <thread>      // std::this_thread::sleep_for
#include <chrono>      // std::chrono::seconds
#include <csignal>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


//MANEJO DE SEÑALES
void signal_handler(int signal_num){
  pid_t pid = getpid();
  switch (signal_num){
    case SIGUSR1:
      std::cout << "SIGUSR1: " << pid << "\n";
      raise(SIGTERM);
      break;
    case SIGUSR2:
      std::cout << "SIGUSR2: " << pid << "\n";
      raise(SIGTERM);
      break;
    default:
      std::cout << "Detención no permitida \n";
      break;
  }
}

//FIBONACCI
uint32_t fibonacci(int a){
  if((a <= 2)){
	  return 1;
  }
  else {
	  return(fibonacci(a-1)+fibonacci(a-2));
  }
}

//IMPAR
uint32_t impar(int n){
  return ((2*n)-1);
}

//MAIN
int main(int argc, char* argv[]){
  int count = 0;
  int n = 1;
  int a = 2;

  //SIGUSR handler with sigaction()
  struct sigaction sa;
  sa.sa_handler = signal_handler; //calls the function
  sigemptyset(&sa.sa_mask);       //initialise and empty a signal set 
  sa.sa_flags = SA_RESTART;       //restart the function
  sigaction(SIGUSR1, &sa, NULL);  //SIGUSR1
  sigaction(SIGUSR2, &sa, NULL);  //SIGUSR2
  //SIGNALS handler with signal()
  std::signal(SIGINT, signal_handler);  //Ctrl-C
  std::signal(SIGTSTP, signal_handler); //Ctrl-Z
  std::signal(SIGQUIT, signal_handler); //Ctrl-\

  //FORK
  int result = fork();
  
  //********** Iterar 50 veces **********
  while(++count){ 

    //Codigo hijo (IMPAR)
  	if(result == 0){
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::cout << "Valor Impar: " << impar(n) << " - PID = " << getpid() << "\n";

    }

    //Codigo padre (FIBONACCI)
	  else if(result > 0){
      std::this_thread::sleep_for(std::chrono::seconds(1));
		  std::cout << "Valor Fibonacci: " << fibonacci(a) << " - PPID = " << getpid() << "\n";

	  }

    //Codigo de error del fork
	  else{
		  perror("Error en fork()");
		  exit(EXIT_FAILURE);
	  }

    //se aumenta n y a en cada iteracion
    n++;
    a++;
    
    //Al llegar a 50 iteraciones se hace terminan los procesos
    if(count == 50) {
		  std::raise(SIGTERM); 
	  }
  }
  //*************************************

return EXIT_SUCCESS;
}
