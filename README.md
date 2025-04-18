# Sistema de Gestión de Tickets

# Descripcion
Este es un sistema de gestion de tickets para un servicio tecnico. Permite a los usuarios registrar tickets, asignarles prioridad, procesarlos, buscar y mostrar tickets pendientes.

## Como compilar y ejecutar
Este sistema ha sido desarrollado en lenguaje C y puede ejecutarse fácilmente utilizando **Visual Studio Code**. Para comenzar a trabajar con el sistema en tu equipo local, sigue estos pasos:

### Requisitos previos:

- Tener instalado [Visual Studio Code].
- Instalar la extensión **C/C++** (Microsoft).
- Tener instalado un compilador de C (como **gcc**). Si estás en Windows, se recomienda instalar [MinGW].

### Pasos para compilar y ejecutar:

1. **Descarga y descomprime el archivo** `.zip` en una carpeta de tu elección.
2. **Abre el proyecto en Visual Studio Code**
    - Inicia Visual Studio Code.
    - Selecciona `Archivo > Abrir carpeta...` y elige la carpeta donde descomprimiste el proyecto.
3. **Compila el código**
    - Abre el archivo principal (`tarea1.c`).
    - Abre la terminal integrada (`Terminal > Nueva terminal`).
    - En la terminal, compila el programa con el siguiente comando (ajusta el nombre si el archivo principal tiene otro nombre):
      ```
      gcc tdas/*.c tarea1.c -Wno-unused-result -o tarea1
      ```

4. **Ejecución**
    - Una vez compilado, puedes ejecutar el programa con el siguiente comando:
      ```bash
      ./tarea1
      ```
## Opciones que funcionan correctamente

1. **Registrar ticket**: Permite al usuario registrar un nuevo ticket, asignándole un ID, una descripción y un dispositivo. El ticket se asigna una prioridad baja por defecto.
   
2. **Asignar prioridad al ticket**: Permite modificar la prioridad de un ticket ya registrado, seleccionando entre "Alto", "Medio" o "Bajo".
   
3. **Mostrar lista de tickets pendientes**: Muestra todos los tickets en espera, ordenados por prioridad y hora de registro.

4. **Procesar siguiente ticket**: Permite procesar el ticket de mayor prioridad (el de menor valor de prioridad). El ticket se muestra y luego se elimina de la lista al procesarlo.

5. **Buscar ticket**: Permite buscar un ticket por su ID y mostrar sus detalles.

Posibles causas de fallos:
- **Falta de la librería `tdas`**: Si no se puede encontrar o usar la librería `tdas` correctamente, se generará un error de compilación. Hay que asegurarse de que la librería esté bien vinculada y disponible.

- **Errores en la entrada del usuario**: Si el usuario ingresa un ID inválido, un ID repetido o un valor no esperado para la prioridad, podrían surgir problemas. Es recomendable implementar validaciones adicionales en el código para manejar estos casos de mejor manera.

## Ejemplo de interacción con la programa

**Paso 1: Iniciar el programa**

Al ejecutar el programa, verás el siguiente menú:
```
========================================
----------- Servicio Tecnico -----------
========================================

1) Registrar ticket
2) Asignar prioridad al ticket
3) Mostrar lista de tickets pendientes
4) Procesar siguiente ticket
5) Buscar ticket
6) Mostrar ticket en espera
7) Salir
```
**Paso 2: Registrar un ticket**

Selecciona la opción '1' para registrar un ticket. El programa te pedirá ingresar un ID, una descripción del problema y selecciona el tipo de dispositivo:
```
Ingrese ID del ticket: 12345
Describa el problema: Pantalla rota
Seleccione tipo de dispositivo:
(1) Smartphone
(2) Computador
(3) Electrodomestico
(4) Television
(5) Otro
```

**Paso 3: Registrar un ticket**
Selecciona la opción '2' para asignar una prioridad al ticket. El sistema te pedirá el ID del ticket y te permitirá elegir la nueva prioridad.
```
Ingrese ID del ticket para modificar su prioridad: 12345
Seleccione nueva prioridad (1-Alto, 2-Medio, 3-Bajo): 1
Ingrese ID del ticket para modificar su prioridad: 12345
```

**Paso 4: Mostrar tickets pendientes**
Selecciona la opción '3' para mostrar la lista de tickets pendientes. Los tickets se mostrarán ordenados por prioridad y hora de registro.
```
Tickets pendientes:
=============================================================================
| # | ID        | Prioridad  | Descripcion                | Hora     |
=============================================================================
| 1 | 12345     | Alto       | Pantalla rota             | 12:30:45 |
=============================================================================
```
**Paso 5: Procesar siguiente ticket**
Selecciona la opción '4' para procesar el siguiente ticket. El ticket de mayor prioridad será mostrado y eliminado de la lista.
```
Procesando ticket: 12345
Dispositivo: Smartphone
Descripcion: Pantalla rota
Prioridad: Alto
Hora: 12:30:45
```

**Paso 6: Buscar ticket**
Selecciona la opción '5' para buscar un ticket por su ID. El programa te mostrará los detalles del ticket.
```
Ingrese ID a buscar: 12345
ID: 12345
Dispositivo: Smartphone
Descripcion: Pantalla rota
Prioridad: Alto
Hora de registro: 12:30:45
```

**Paso 7: Salir**
Selecciona la opción '6' para salir del programa.
```
Saliendo del sistema...
```