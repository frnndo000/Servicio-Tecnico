#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char id [30] ;
  char descripcion [200] ;
  int dispositivo ;
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

  printf("Seleccione tipo de dispositivo:\n") ;
  printf("(1) Smartphone\n") ;
  printf("(2) Computador\n") ;
  printf("(3) Electrodomestico\n") ;
  printf("(4) Television\n") ;
  printf("(5) Otro\n") ;
  scanf("%d", &nuevoTicket->dispositivo) ;
  getchar() ;

  printf("Describa el problema: ") ;
  fgets(nuevoTicket->descripcion, 200, stdin) ;
  nuevoTicket->descripcion[strcspn(nuevoTicket->descripcion, "\n")] = 0 ;

  nuevoTicket->prioridad = 3 ;
  nuevoTicket->hora = time(NULL) ;

  list_pushBack(ticket, nuevoTicket) ;
  printf("El ticket %s ha sido registrado correctamente.\n", nuevoTicket->id) ;
}

void asignar_prioridad(List *tickets) {
  char id[30];
  printf("Ingrese ID del ticket para modificar su prioridad: ") ;
  scanf("%s", id) ;

  Ticket *t = list_first(tickets) ;
  while (t != NULL) {
    if (strcmp(t->id, id) == 0) {
      printf("Seleccione nueva prioridad (1-Alto, 2-Medio, 3-Bajo): ") ;
      scanf("%d", &t->prioridad) ;
      printf("Prioridad actualizada correctamente.\n") ;
      return ;
    }
    t = list_next(tickets) ;
  }
  printf("No se encontro el ticket con ID %s\n", id) ;
}

void mostrar_lista_tickets(List *tickets) {
  if (list_size(tickets) == 0) {
    printf("No hay tickets pendientes. \n") ; 
    return ;
  } 
  
  List *ordenados = list_create() ;
  Ticket *t = list_first(tickets) ;
  while (t != NULL) {
    list_pushBack(ordenados, t) ;
    t = list_next(tickets) ;
  }
  
  //list_sort(ordenados, comparar_tickets) ; 

  printf("\nTickets pendientes:\n") ;
  printf("=============================================================================\n") ;
  printf("| %-3s | %-10s | %-10s | %-25s | %-8s |\n", 
               "#", "ID", "Prioridad", "Descripcion", "Hora") ;
  printf("=============================================================================\n") ;

  int index = 1 ;
  t = list_first(ordenados) ;
  while (t != NULL) { 
    char horaStr[20];
    strftime(horaStr, sizeof(horaStr), "%H:%M:%S", localtime(&t->hora)) ;
    char *prio = t->prioridad == 1 ? "Alto" : t->prioridad == 2 ? "Medio" : "Bajo" ;
    printf("| %-3d | %-10s | %-10d | %-25.25s | %-8s |\n", 
                index, t->id, t->prioridad, t->descripcion, horaStr) ; 
    index++ ; 
    t = list_next(ordenados) ;
  }
    printf("=============================================================================\n") ;
} 

int main() {
  char opcion;
  List* lista_tickets = list_create() ;
  do {
    mostrarMenuPrincipal();

    printf("Ingrese su opcion: ");
    scanf(" %c", &opcion); 

    switch (opcion) {
    case '1': registrar_ticket(lista_tickets) ;
      break;
    case '2': asignar_prioridad(lista_tickets) ;
      break;
    case '3': mostrar_lista_tickets(lista_tickets) ;
      break;
    case '4'://procesar_siguiente_ticket(lista_tickets) ;
      break;
    case '5'://buscar_ticket(lista_tickets) ;
      break;
    case '6':
      puts("Saliendo del sistema de gestion de tickets...");
      break;
    default:
      puts("Opcion no valida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6') ;

  list_clean(lista_tickets) ;

  return 0;
}
