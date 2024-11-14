// deja am corectat si am adaugat algoritmi STL
#include <iostream>
#include <vector>
#include <algorithm> // asta algoritmi STL
#include <memory>    // asta pentruu smart pointers
#include "point.hpp"
#include "apple.hpp"
#include "board.hpp"

int main() {
    //  crearea tabeleii de joc si lista de mere
    Board gameBoard(20, 20);
    std::vector<std::shared_ptr<Apple>> apples = {
        std::make_shared<Apple>(Point(5, 5)),
        std::make_shared<Apple>(Point(10, 10)),
        std::make_shared<Apple>(Point(3, 7))
    };

    // afisarea initaila a tabelei si a listei de mere
    std::cout << "Board size: " << gameBoard << std::endl;
    std::cout << "Apples positions:" << std::endl;
    for (const auto& apple : apples) {
        std::cout << *apple << std::endl;
    }

    // sortarea merelor dupa pozitia x folosind STL
    std::sort(apples.begin(), apples.end(), [](const std::shared_ptr<Apple>& a, const std::shared_ptr<Apple>& b) {
        return a->GetPosition().x < b->GetPosition().x;
    });
    std::cout << "Apples after sorting by x position:" << std::endl;
    for (const auto& apple : apples) {
        std::cout << *apple << std::endl;
    }

    // cautarea unui mar de la pozitia la (5,5)
    auto it = std::find_if(apples.begin(), apples.end(), [](const std::shared_ptr<Apple>& apple) {
        return apple->GetPosition() == Point(5, 5);
    });
    if (it != apples.end()) {
        std::cout << "Apple found at (5, 5)" << std::endl;
    } else {
        std::cout << "Apple not found at (5, 5)" << std::endl;
    }

    // copierea vectorului de mere in alt vector folosind STL
    std::vector<std::shared_ptr<Apple>> copiedApples(apples.size());
    std::copy(apples.begin(), apples.end(), copiedApples.begin());
    std::cout << "Copied apples positions:" << std::endl;
    for (const auto& apple : copiedApples) {
        std::cout << *apple << std::endl;
    }

    return 0;
}
