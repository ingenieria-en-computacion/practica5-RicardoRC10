#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una nueva tail vacía y la devuelve.
 * 
 * @return Una nueva tail vacía. Si la creación falla, el estado de la tail es inválido.
 * @details Esta función inicializa una tail vacía. 
 */
Queue queue_create() {
    Queue tail;
    tail.head = -1;
    tail.tail = -1;
    tail.len = TAM;
    return tail;
}

/**
 * Inserta un elemento al final de la tail.
 * 
 * @param tail Referencia a la tail donde se insertará el elemento.
 * @param dato Dato que se insertará en la tail.
 * @details Esta función añade el dato `dato` al final de la tail.
 */
void queue_enqueue(Queue* tail, Data dato) {
    if ((tail->tail + 1) % tail->len == tail->head) {
        printf("Error: La tail está llena.\n");
        return;
    }
    if (tail->head == -1) {
        tail->head = 0;
    }
    tail->tail = (tail->tail + 1) % tail->len;
    tail->datos[tail->tail] = dato;
}

/**
 * Elimina y devuelve el elemento al frente de la tail.
 * 
 * @param tail Referencia a la tail de la cual se eliminará el elemento.
 * @return El dato que estaba al frente de la tail. Si la tail está vacía, devuelve un valor de error.
 * @details Esta función elimina el elemento al frente de la tail y lo devuelve.
 */
Data queue_dequeue(Queue* tail) {
    if (queue_is_empty(tail)) {
        printf("Error: La tail está vacía.\n");
        return -1; // Valor de error
    }
    Data dato = tail->datos[tail->head];
    if (tail->head == tail->tail) {
        tail->head = -1;
        tail->tail = -1;
    } else {
        tail->head = (tail->head + 1) % tail->len;
    }
    return dato;
}

/**
 * Verifica si la tail está vacía.
 * 
 * @param tail Referencia a la tail que se desea verificar.
 * @return `true` si la tail está vacía, `false` si no lo está. 
 * @details Esta función comprueba si la tail no contiene elementos.
 */
bool queue_is_empty(Queue* tail) {
    return tail->head == -1;
}

/**
 * Obtiene el elemento al frente de la tail sin eliminarlo.
 * 
 * @param tail Referencia a la tail de la cual se desea obtener el elemento.
 * @return El dato que está al frente de la tail. Si la tail está vacía, devuelve un valor de error.
 * @details Esta función devuelve el elemento al frente de la tail sin modificarla.
 */
Data queue_front(Queue* tail) {
    if (queue_is_empty(tail)) {
        printf("Error: La tail está vacía.\n");
        return -1; // Valor de error
    }
    return tail->datos[tail->head];
}

/**
 * Vacía la tail, eliminando todos sus elementos.
 * 
 * @param tail Referencia a la tail que se desea vaciar.
 * @details Esta función hace que los índices head y tail tomen el valor de -1.
 */
void queue_empty(Queue* tail) {
    tail->head = -1;
    tail->tail = -1;
}

/**
 * Elimina la tail, asegurando que quede vacía.
 * 
 * @param tail Referencia a la tail que se desea eliminar.
 * @details Esta función deja la tail vacía.
 */
void queue_delete(Queue* tail) {
    queue_empty(tail);
}


