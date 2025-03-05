/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:32:28 by alvutina          #+#    #+#             */
/*   Updated: 2024/10/31 10:32:29 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Create a zombie on the heap using newZombie
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // Explicitly delete the heap-allocated zombie to invoke the destructor
    // Create a zombie on the stack using randomChump
    randomChump("StackZombie");
    return 0;
}
/*
Куча (heap) с помощью newZombie:
Функция newZombie создает зомби в куче, который остается доступен вне области действия функции.
Важно освободить память с помощью delete, чтобы предотвратить утечку памяти.

Стек (stack) с помощью randomChump:
Функция randomChump создает зомби на стеке, и этот зомби будет уничтожен при выходе из функции,
так как в C++ все объекты на стеке автоматически удаляются.*/
/*
Heap with newZombie:
The newZombie function creates a zombie on the heap, which remains accessible outside the function’s scope.
It’s important to release the memory using delete to prevent memory leaks.

Stack with randomChump:
The randomChump function creates a zombie on the stack, and this zombie will be destroyed when the function exits,
as in C++ all objects on the stack are automatically deleted.
*/
