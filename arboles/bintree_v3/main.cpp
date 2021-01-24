/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#include "bintree.h"
#include <iostream>
#include <sstream>

// Coste lineal con respecto al número de nodos de tree.
template <typename T> int height(const BinTree<T> &tree) {
  if (tree.empty()) {
    return 0;
  } else {
    return 1 + std::max(height(tree.left()), height(tree.right()));
  }
}

// Coste cuadrático con respecto al número de nodos de tree.
template <typename T> bool balanced1(const BinTree<T> &tree) {
  if (tree.empty()) {
    return true;
  } else {
    bool bal_left = balanced(tree.left());
    bool bal_right = balanced(tree.right());
    int height_left = height(tree.left());
    int height_right = height(tree.right());
    return bal_left && bal_right && abs(height_left - height_right) <= 1;
  }
}

// Coste lineal con respecto al número de nodos de tree.
template <typename T> bool balanced2(const BinTree<T> &tree) {
  bool balanced;
  int height;
  balanced_height(tree, balanced, height);
  return balanced;
}

template <typename T>
void balanced_height(const BinTree<T> &tree, bool &balanced, int &height) {
  if (tree.empty()) {
    balanced = true;
    height = 0;
  } else {
    bool bal_left, bal_right;
    int height_left, height_right;
    balanced_height(tree.left(), bal_left, height_left);
    balanced_height(tree.right(), bal_right, height_right);
    balanced = bal_left && bal_right && abs(height_left - height_right) <= 1;
    height = 1 + std::max(height_left, height_right);
  }
}

int main() {
  BinTree<std::string> tree = {{"3"}, "+", {{"9"}, "*", {"7 "}}};
  std::cout << tree << std::endl;

  std::istringstream istr("(((. 9 .) + (. 5 .)) * ((. 10 .) + (. 6 .)))");
  BinTree<std::string> other = read_tree<std::string>(istr);
  std::cout << other << std::endl;

  BinTree<int> comun = {{7}, 3, {9}};
  BinTree<int> t1 = {{}, 5, comun};
  BinTree<int> t2 = {comun, 4, {8}};

  std::cout << t1 << std::endl;
  std::cout << t2 << std::endl;

  std::cout << "Altura de 'tree': " << height(tree) << std::endl;
  std::cout << "Altura de 'other': " << height(other) << std::endl;
  std::cout << "Altura de 't1': " << height(t1) << std::endl;
  std::cout << "Altura de 't2': " << height(t2) << std::endl;
  std::cout << "Altura de 'comun': " << height(comun) << std::endl;

  std::cout << "¿Está 'tree' equilibrado? " << balanced2(tree) << std::endl;
  std::cout << "¿Está 'other' equilibrado? " << balanced2(other) << std::endl;
  std::cout << "¿Está 't1' equilibrado? " << balanced2(t1) << std::endl;
  std::cout << "¿Está 't2' equilibrado? " << balanced2(t2) << std::endl;
  std::cout << "¿Está 'comun' equilibrado? " << balanced2(comun) << std::endl;

  return 0;
}
