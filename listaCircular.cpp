#include <iostream>
using namespace std;
/**
 * Se define la estrucutura para la lista.
 * @param data Dato del nodo.
 * @param next Puntero al siguiente nodo.
 */
struct Node
{
    int data;
    Node *next;
};

/**
 * Función para agregar un elemento al final de la lista
 * @param [out] head Puntero al puntero que indica la dirrecion de memoria del ultimo Nodo creado de la lista. (Primera vez es nullptr)
 * @param [in] value Valor que sea va designar segun al nuevo Nodo que se va a crear.
 * @param newNode Variable puntero que hace referencia al objeto, y que guarda la posicion de memoria.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void createOne(Node *&head, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
}
/**
 * Funcion para insetar un valor en una posicion X.
 * @param [out] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista. (Primera vez es nullptr. Y se actualiza si se inserta al incio.
 * @param [in] position Posicion de la lista en la que se va a insertar el dato.
 * @param [in] value Valor del dato que se va a ingresar del Nodo.
 * @param newNode Variable puntero que hace referencia al objeto, y que guarda la posicion de memoria.
 */
void createInPosition(int value, Node *&head, int position)
{
    Node *newNode = new Node; // Se crea un nuevo Nodo, y '*newNode' guarda la posicion en memoria del objeto. (Puntero)
    newNode->data = value;    // Se actualiza el valor de 'newNode.data' segun 'value'
    newNode->next = nullptr;  // Se actualiza el valor de 'newNode.next' a 'nullptr'

    // Validacion para saber si 'head' tiene alguna direccion en memoria. (No hay otro Nodo. Es el Primer nodo)
    if (head == nullptr)
    {
        head = newNode; // 'head' se actualiza de manera global y guarda ahora la direccion en memoria del primer nodo de la lista.
        head->next = head;
    }
    // Parte para cuando ya existe un nodo (Lista con un valor), y se va agregar uno nuevo.
    else
    {
        Node *current = head; // Se crea un nuevo Node 'current' para moverse entre posiciones.
        int i = 0;            // Variable para llevar el indice actual.
        Node *aux;
        aux = current;
        bool band = true;

        do
        {
            if (i == position)
            {
                newNode->next = current->next; // 'newNode.next' se actualiza y apunta al nodo actual. (El nuevo nodo apunta al nodo que apuntaba'current')
                current->next = newNode;       // 'current.next' de actualiza y apunta al nuevo nodo (El nodo alcutal apunta )
                band = false;
                break;
            }
            i++;
            current = current->next;

        } while (current != head || head != nullptr);
        if (band)
        {
            cout << "Posicion fuera de la lista, ingrese mas valores" << endl;
        }
    }
}
/**
 * Funcion para buscar un valor e imprir la posicion en la que está.
 * @param [in] value Valor que se buscará en la lista.
 * @param [in] head  Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param current Variable tipo nodo que se usa para moverse entre la lista.
 * @param i Variable referente a la poscion actual de la lista. (Indice)
 * @param band Boolean para valdiar si se encuentra un elemento.
 */
void readOne(int value, Node *head)
{
    // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    Node *current = head;
    current = current->next;
    Node *aux;
    aux = current->next;
    // Se crea la variable 'i' para indicar la poscion actual de la lista.
    int i = 0;
    // Se crea la variable 'band' para validacion.
    bool band = true;
    // Ciclo while para recorrer la lista

    do
    {

        // Validacion para saber si el valor de 'current.data' es igual a 'value' (Si se encontró el valor)
        if (current->data == value)
        {
            // Se imprime la posicion donde se encontró el valor.
            cout << "Valor encontrado posicion: "
                 << i << endl;
            // Se cambia el valor de 'band'
            band = false;
        }
        // Se cambia el apuntado de 'current' a 'current.next' (Ahora apunta donde apunta 'current')
        current = current->next;
        // Se suma uno a 'i'
        i++;
    } while (current->next != aux);

    // Validacion para saber si se encontró el valor en la lista. (En el caso que si se haya encontrado anteriormente 'band' se pone en false)
    if (band)
    {
        // Impresion cuando no se encontró nada
        cout << "Valor no encontrado " << endl;
    }
}
/**
 * Función para imprimir la lista
 * @param [in] head Puntero que hace referencia al espacio de memoria del primer nodo.
 * @param current Puntero que guarda el espacio de memoria de 'head'.
 *
 */
void readAll(Node *head)
{
    // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    Node *current = head->next;
    int i = 0;
    if (head != NULL)
    {
        // Ciclo para recorrer la lista siempre y cuando 'current' no sea nullptr (Para recorrer de inicio a fin la lista).
        do
        {
            // Se imprime el valor de 'current.data'
            cout << current->data << " ";
            // Se actualiza la varaible 'current' a la direccion en memoria del siguiente nodo guardado en 'current.next'.
            current = current->next;
            i++;
            if (i == 8)
            {
                break;
            }
        } while (current != head->next);
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}
/**
 * Funcion para actualizar un valor en la posicion
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] value Variable del nuevo valor que se quiere colocar en la lista
 * @param [in] position Posicion de la lista en la que se va a insertar el dato.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void updateOne(Node *&head, int new_value, int position)
{
    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    current = current->next;
    int i = 0; // Variable para llevar el indice actual.
    Node *aux;
    aux = current;
    bool band = true;
    // Validacion para verificar si la lista no está vacia
    if (head != NULL)
    {
        // Ciclo while para recorrer la lista
        do
        {
            if (i == position)
            {
                current->data = new_value;
                cout << "DATO ACTUALIZADO" << endl;
                band = false;
                break;
            }
            i++;
            current = current->next;
        } while (current != aux);

        // Validacion para cuando 'current'apunta a nulo (Fin de la lista) (Validacion para que el programa se crashee)
        if (band)
        {
            // Impresion de posicion fuera de la longitud actual de la lista
            cout << "Posicion fuera de la lista, ingrese mas valores" << endl;
        }
    }
    // Parte cuando la lista está vacia
    else
    {
        cout << "Nada que editar" << endl;
    }
}
/**
 * Funcion para actualizar al primir numero que coincide con 'value'.
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] new_value Variable del nuevo valor que se quiere colocar en la lista
 * @param [in] filter Variable de filtro para buscar el valor a editar.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void updateFirts(Node *&head, int new_value, int filter)
{
    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    current = current->next;
    Node *aux;
    aux = current->next;
    bool band = true;
    // Validacion para saber si la lista está vacia
    if (head != NULL)
    {
        do
        {
            if (current->data == filter)
            {
                //  Actualiza el dato a lo que esté en la variable 'new_value'
                current->data = new_value;
                // Impresion de confirmacion
                cout << "Se actualizó el dato" << endl;
                band = false;
                break;
            }
            current = current->next;
        } while (current->next != aux);

        // Validacion para ver si se llegó al final de la lista sin encontrar el valor
        if (band)
        {
            cout << "VALOR NO ENCONTRADO" << endl;
        }
    }
    // Cuando la lista está vacia
    else
    {
        cout << "Nada que actualizar" << endl;
    }
}
/**
 * Funcion para actualizar todos los datos iguales a 'filter'
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] new_value Variable del nuevo valor que se quiere colocar en la lista
 * @param [in] flter Variable de filtro para buscar el valor a editar.
 * @param current Variable puntero que hace referencia al direccion de memoria actual del ultimo nodo seleccionado de la lista. ()
 */
void updateAll(Node *&head, int new_value, int filter)
{
    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'
    Node *aux;
    aux = current;
    bool band = true;
    // Validacion para comprar si la lista no esté vacia
    if (current != NULL)
    {
        do
        {
            if (current->data == filter)
            {
                // Se actualiza el valor del nodo actual al valor de 'new_value'
                current->data = new_value;
                cout << "Valor actualizado" << endl;
                band = false;
            }
            current = current->next;

        } while (current != head);
        /* while (aux != current->next)
         {

         }*/

        if (band)
        {
            cout << "No se encontró ningur valor" << endl;
        }
    }
    // Parte cuando la lista está vacia
    else
    {
        cout << "Nada que editar" << endl;
    }
}
/**
 * Funcion para eliminar un nodo en la posicion X
 * @param [in] head Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] filter Variable que sea usa como filtro, debe ser igual al valor de la lista en la posicion X.
 * @param [in] position Posicion de la lista en la que se va a eliminar el dato.
 * @param past Variable node para guardar el nodo anterior para despues actualizar su apuntador
 */
void deleteOne(Node *&head, int filter, int position)
{

    Node *current = head; // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
    current = current->next;
    Node *past = NULL; // Se crea un puntero para de tipo Nodo iniciado en null.
    Node *aux;
    aux = current->next;
    int i = 0;        // Variable para llevar el indice actual.
    bool band = true; // Boleano para indicar si un valor de encontró o no

    // Ciclo while para recorre la lista
    do
    {
        if (current->data == filter && position == i && i == 0)
        {
            head->next = current->next;
            delete current; // Se libera la memoria de current
            band = false;   // Se coloca la bandera el false para indicar que si se borró un dato
            cout << "Valor eliminado despues de cabeza " << endl;
            break;
        }

        // 1                  1         0      0          Y        Y
        if (current->data == filter && position == i && current == head)
        {

            // head = head->next;
            aux = head->next;
            delete current;
            head = past;
            head->next = aux;
            band = false; // Se coloca la bandera el false para indicar que si se borró un dato
            cout << "Valor eliminado es la cabeza " << endl;
            break;
        }

        if (current->data == filter && position == i)
        {

            past->next = current->next; // Se actualiza el puntero del nodo anterior a donde esté apuntado 'current'
            delete current;             // Se libera la memoria de current
            band = false;               // Se coloca la bandera el false para indicar que si se borró un dato
            cout << "Valor eliminado " << endl;
            break;
        }

        // 'past' pasa a ser 'current' para así guardarlo y no perder el nodo anterior
        past = current;
        // Se rota a donde esté apuntando 'current'
        current = current->next;
        // Se le agrega uno al indice
        i++;
    } while (current->next != aux);

    // Validacon para saber si el un dato fue eliminado
    if (band)
    {
        cout << "Valor no eliminado " << endl;
    }
}
/**
 * Funcion para borrar al primir numero que coincide con 'value'.
 * @param [in] head  Puntero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] value Valor que se va a borrar de la lista.
 * @param current Variable tipo Node para moverse en la lista.
 * @param past Variable tipo Node para guardar el nodo anterior de manera temporal.
 *
 */
void deleteFirts(Node *&head, int filter)
{
    Node *current = head; // Se crea un nuevo Node 'current' para moverse entre posiciones.
    current = current->next;
    Node *past = NULL; // // Se crea un nuevo Node 'past' para guardar el Nodo anterior.
    bool band = true;
    Node *aux;
    aux = current->next;

    // Validacion para saber si la lista está vacia.
    if (head != NULL)
    {
        do
        {
            if (current->data == filter && current == head)
            {
                past->next = head->next;
                head = past;
                delete current;
                cout << "Valor eliminado es la cabeza" << endl;
                break;
            }
            if (current->data == filter && head->next == current)
            {
                head->next = current->next;
                delete current;
                cout << "Valor eliminado siguiente a cabeza" << endl;
                break;
            }
            if (current->data == filter)
            {
                past->next = current->next;
                delete current;
                cout << "Valor eliminado" << endl;
                break;
            }

            past = current;
            current = current->next;
        } while (current->next != aux);
    }
    // Impresion cuando la lista está vacia
    else
    {
        cout << "Nada que borrar" << endl;
    }
}
/**
 * Funcion para eliminar todos los datos que coincidan.
 * @param [in] head untero al puntero que indica la dirrecion de memoria del primer Nodo de la lista.
 * @param [in] filter Variable de filtro para buscar el valor a borrar.
 * @param current Variable tipo Node para moverse en la lista.
 * @param past  Variable node para guardar el nodo anterior para despues actualizar su apuntador
 */
void deleteAll(Node *&head, int filter)
{
    Node *current = head;
    Node *past = nullptr;
    bool found = false;

    if (head != nullptr)
    {
        do
        {
            if (current->data == filter)
            {
                Node *temp = current;
                if (current == head)
                {
                    head = current->next;
                    past->next = head;
                }
                else
                {
                    past->next = current->next;
                }
                current = current->next;
                delete temp;
                found = true;
            }
            else
            {
                past = current;
                current = current->next;
            }
        } while (current != head);

        if (found)
        {
            std::cout << "Se eliminaron todos los nodos con el valor " << filter << std::endl;
        }
        else
        {
            std::cout << "No se encontró ningún nodo con el valor " << filter << std::endl;
        }
    }
    else
    {
        std::cout << "La lista está vacía" << std::endl;
    }
}
/**
 * @param head Variable puntero nulo.
 * @param temp Variable puntero que hace referencia a la direccion de memoria que está guardada en 'head'.
 */
int main()
{
    Node *head = nullptr; // Se crea un puntero de tipo Nodo vacio.
    int data, choise, position, filter, new_value;
    do
    {
        cout << "OPCIONES: " << endl;
        cout << "0. CreateOne: Para crear una dato al final de la fila" << endl;
        cout << "1. createInPosition: Para insetar un dato en una posicion" << endl;
        cout << "2. ReadOne: Para leer y mostar el indice de los datos segun el dato" << endl;
        cout << "3. ReadAll: Para leer todos los datos de la lista" << endl;
        cout << "4. UpdateOne: Para actualizar el valor segun la poscion" << endl;
        cout << "5. UpdateFirts: Para actualizar el valor del primer dato encontrado segun el filtro" << endl;
        cout << "6. UpdateAll: Para actualizar todos los valores seguna el filtro a un nuevo valor" << endl;
        cout << "7. DeleteOne: Para eliminar un valor segun la posicion" << endl;
        cout << "8. DeleteFirts: Para eliminar el valor del primer dato encontrado segun el filtro " << endl;
        cout << "9. DeleteAll: Para eliminar todos los valores seguna el filtro" << endl;
        cin >> choise;
        // Switch que maneja las posibles opciones
        switch (choise)
        {
        case 0:
            cout << "Valor a ingresar: ";
            cin >> data;
            createOne(head, data);
            break;

        case 1:
            cout << "Valor a ingresar: ";
            cin >> data;
            cout << "Posicion: ";
            cin >> position;
            createInPosition(data, head, position);
            break;
        case 2:
            cout << "Dato a buscar: ";
            cin >> data;
            readOne(data, head);
            break;
        case 3:
            // cout << "CABEZA ES: " << head->data << endl;
            readAll(head);
            break;
        case 4:
            cout << "Dato a actualizar: ";
            cin >> data;
            cout << "Posicion de la lista para actualizar: ";
            cin >> position;
            updateOne(head, data, position);
            break;
        case 5:
            cout << "Datos que va a reemplezar: ";
            cin >> filter;
            cout << "Dato por el cual va a reemplazar: ";
            cin >> new_value;
            updateFirts(head, new_value, filter);
            break;
        case 6:
            cout << "Datos que va a reemplezar: ";
            cin >> filter;
            cout << "Datos por el cual va a reemplazar: ";
            cin >> new_value;
            updateAll(head, new_value, filter);
            break;
        case 7:
            cout << "Dato a eliminar: ";
            cin >> filter;
            cout << "Posicion: ";
            cin >> position;
            deleteOne(head, filter, position);
            break;
        case 8:
            cout << "Dato a eliminar: ";
            cin >> data;
            deleteFirts(head, data);
            break;
        case 9:
            cout << "Datos a eliminar: ";
            cin >> data;
            deleteAll(head, data);
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }

        cout << "\nOpciones: \n"
             << "0:Finalizar 1:Seguir" << endl;
        cin >> choise;
        // system("cls");
    } while (choise == 1);

    // Incio de impresion.
    cout << "Lista final: " << endl;
    // Se llama a la lista readAll, y se pasa el parametro head.
    readAll(head);
    // Ciclo While que se ejecuta siempre y cuando 'head' sea diferente a nullptr.
    /*while (head != nullptr)
         {
             // Se crea un puntero para de tipo Nodo que es igual a la variable 'head'.
             Node *temp = head;
             // Se actualiza el valor de 'head' al siguiente espacio en memoria del siguiente Nodo..
             head = head->next;
             // Se libera la memoria, segun 'temp'.
             delete temp;
         }*/
    system("PAUSE");
    return 0;
}
