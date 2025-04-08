#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char id [30] ;
  char descripcion [200] ;
  int prioridad ;
  time_t hora ;
} Ticket ;

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("----------- Servicio Tecnico -----------");
  puts("========================================");

  puts("1) Registrar ticket");
  puts("2) Asignar prioridad al ticket");
  puts("3) Mostrar lista de tickets pendientes");
  puts("4) Procesar siguiente ticket");
  puts("5) Buscar ticket ");
  puts("6) Salir");
}

void registrar_ticket(List *ticket) {
  Ticket* nuevoTicket = malloc(sizeof(Ticket)) ;

  if (!nuevoTicket) {
    printf("Error al crear el nuevo ticket") ;
    return ;
  }

  printf("Registrar nuevo ticket\n") ;
  printf("Ingrese su ID: ") ;
  scanf("%s", nuevoTicket->id) ;

  nuevoTicket->prioridad = 3 ;
  nuevoTicket->hora = time(NULL) ;

}

void mostrar_lista_tickets(List *ticket) {
  // Mostrar pacientes en la cola de espera
  printf("Tickets en espera: \n");
  // Aquí implementarías la lógica para recorrer y mostrar los pacientes
}

int main() {
  char opcion;
  List* tickets = list_create() ; // Lista para almacenar los tickets.
  do {
    mostrarMenuPrincipal();

    printf("Ingrese su opcion: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_ticket(tickets) ;
      break;
    case '2':
      // Lógica para asignar prioridad
      break;
    case '3':
      //mostrar_lista_pacientes(pacientes);
      break;
    case '4':
      // Lógica para atender al siguiente paciente
      break;
    case '5':
      // Lógica para mostrar pacientes por prioridad
      break;
    case '6':
      puts("Saliendo del sistema de gestion de tickets...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(tickets);

  return 0;
}
