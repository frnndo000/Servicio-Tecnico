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
      gcc -o gestion_tickets gestion_tickets.c -ltdas
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

- **Errores en la entrada del usuario**: Si el usuario ingresa un ID inválido o un valor no esperado para la prioridad, podrían surgir problemas. Es recomendable implementar validaciones adicionales en el código para manejar estos casos de mejor manera.