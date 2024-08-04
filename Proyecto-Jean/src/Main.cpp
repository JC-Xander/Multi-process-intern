#include <iostream> 
/** 
 * Nos Permite imprimir en consola
 * Metodos utilizados
 * - cout: 
 -------------------------------------------------------------------*/
#include <sys/shm.h>
/** 
 -------------------------------------------------------------------*/
#include <unistd.h>
/** 
 -------------------------------------------------------------------*/
#include <string>
/** 
 -------------------------------------------------------------------*/
#include <sys/ipc.h>
/** 
 -------------------------------------------------------------------*/
#include <sys/stat.h>
/** 
 -------------------------------------------------------------------*/
#include <sys/sem.h>
/** 
 -------------------------------------------------------------------*/
#include <wait.h>
/**
 * La utilizamos para que el proceso padre espera a que finalicen los 
 * procesos hijo
 * Metodo
 * wait()
 -------------------------------------------------------------------*/

#include <stdio.h>
/** 
 -------------------------------------------------------------------*/

// --- Librerias que llaman a semget semaforos identificadores ---
#include <fcntl.h>
/** 
 -------------------------------------------------------------------*/
#include <sys/sem.h> 
/** 
 -------------------------------------------------------------------*/

// --------- LIBRERIAS PERSONALIZADAS ------------
#include "Becario.h"
/** 
 -------------------------------------------------------------------*/
#include "Jefe.h"
/** 
 -------------------------------------------------------------------*/
using namespace std;

#define N_JEFE 2   // Numero de Jefes
#define SEM_JEFE 0 // Proceso JEFE

int main() {
    perror("Fallo Critico");
    // ----- Crear Semaforo ------
    int sem, r;

    // -------- Memoria compartida --------
    key_t Clave;
    int ID_Memoria;
    Jefe* jefasos = NULL;

    Clave = ftok("/bin/ls", 33);
    if (Clave == -1) {
        cout << "No consigo clave para memoria compartida" << endl;
        exit(0);
    }

    ID_Memoria = shmget(Clave, (sizeof(Jefe) * SEM_JEFE), 0777 | IPC_CREAT);
    if (ID_Memoria == -1) {
        cerr << "No se pudo obtener el ID para la memoria compartida" << std::endl;
        exit(1);
    }

    jefasos = (Jefe*)shmat(ID_Memoria, nullptr, 0);
    if (jefasos == (void*)-1) {
        cout << "No consigo memoria compartida" << endl;
        exit(0);
    }

    pid_t pid;
    for (int i = 0; i < SEM_JEFE; i++) {
        pid = fork();
        if (pid == -1) {
            cout << "Fallo al crear el nuevo proceso";
        }

        if (pid == 0) {
            {
                cout << "Nuevo Proceso" << endl;
                Jefe nuevo(10);
                cout << nuevo << endl;
                jefasos[i] = nuevo;
            }
            exit(0);
        }
    }

    // Esperar a que todos los procesos hijos terminen
    for (int i = 0; i < SEM_JEFE; i++) {
        wait(nullptr);
    }

    // Ahora es seguro imprimir los resultados
    cout << "========================" << endl;
    for (int i = 0; i < SEM_JEFE; i++) {
        cout << jefasos[i] << endl;
    }

    shmdt((void*)jefasos);
    shmctl(ID_Memoria, IPC_RMID, (struct shmid_ds*)NULL);
    return 0;
}
