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
  getchar() ;

  printf("Describa el problema: ") ;
  fgets(nuevoTicket->descripcion, 200, stdin) ;

  nuevoTicket->prioridad = 3 ;
  nuevoTicket->hora = time(NULL) ;

  list_pushBack(ticket, nuevoTicket) ;

  printf("El ticket %s ha sido registrado correctamente.\n", nuevoTicket->id) ;
}

void mostrar_lista_tickets(List *tickets) {
  if (list_size(tickets) == 0) {
    printf("No hay tickets pendientes. \n") ;
  } else {
    printf("\nTickets pendientes: \n") ;
    
    printf("=============================================================================\n") ;
    printf("| %-2s | %-15s | %-13s | %-9s | %-20s |\n", 
               "#", "ID", "Prioridad", "Descripcion", "Hora") ;
    printf("=============================================================================\n") ;

    int index = 1 ;
    Ticket* temp = (Ticket *) list_first(tickets) ;
    while (temp != NULL) { 
      char horaStr[20];
      strftime(horaStr, sizeof(horaStr), "%H:%M:%S", localtime(&temp->hora)) ;

      printf("| %-2d | %-15s | %-10d | %-25.25s | %-8s |\n", 
                index, temp->id, temp->prioridad, temp->descripcion, horaStr) ; 
      index++ ; 
      temp = (Ticket*) list_next(tickets) ;
    }
    printf("=============================================================================\n") ;
  }  
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
      mostrar_lista_tickets(tickets) ;
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
