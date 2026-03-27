# Sistema de Gestión de Turnos - Estructura de Datos

## 1. Descripción
Este sistema de consola fue desarrollado en C++ para organizar turnos de atención de estudiantes mediante nombres y códigos.

## 2. Estructura Usada y Justificación
Se implementó una lista enlazada simple gestionada de forma manual (sin STL). 

**Justificación:** Al usar punteros a 'frente' y 'final', podemos insertar y eliminar elementos en tiempo constante, lo cual es ideal para una cola de atención (FIFO) por lo tanto esta estructura permite organizar los datos de memoria de manera eficiente. 

## 3. Complejidad Computacional
* **Inserción (Registrar):** O(1) - Gracias al puntero al último nodo.
* **Eliminación (Atender):** O(1) - Solo se mueve el puntero del frente.
* **Búsqueda:** O(n) - Requiere recorrer la lista secuencialmente hasta hallar el nombre.

## 4. Instrucciones de Compilación
1. Abrir el archivo '.cpp' en CodeBlocks.
2. Presionar `F9` para compilar y ejecutar.
