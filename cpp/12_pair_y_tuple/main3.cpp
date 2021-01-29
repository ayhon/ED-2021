/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/* Distintas formas de implementar una función que devuelva
   varios resultados

   Aquí se muestra el uso de la clase pair
   */

#include <iostream>
#include <limits>
#include <utility>

std::pair<int, int> min_max(int *array, int longitud) {
  int min = std::numeric_limits<int>::max();
  int max = std::numeric_limits<int>::min();

  for (int i = 0; i < longitud; i++) {
    min = std::min(min, array[i]);
    max = std::max(max, array[i]);
  }

  return {min, max};
  // return std::pair<int, int>(min, max);
}

int main() {
  int arr[] = {5, 1, -4, 10, 24, 8, -1};
  int longitud = sizeof(arr) / sizeof(int);

  std::pair<int, int> p = min_max(arr, longitud);
  std::cout << "Min = " << p.first << " | Max = " << p.second << std::endl;

  // Uso de la sintaxis permitida a partir de C++17
  auto [min, max] = min_max(arr, longitud);
  std::cout << "Min = " << min << " | Max = " << max << std::endl;

  return 0;
}
