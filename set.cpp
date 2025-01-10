#include <iostream>

class Set {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    Set() : root(nullptr) {}

    // Konstruktor kopiujący
    Set(const Set& other) : root(nullptr) {
        if (other.root) {
            insert(other.root->value); // Kopiowanie wartości root
            copy(other.root->left);    // Rekurencyjne kopiowanie lewej części
            copy(other.root->right);   // Rekurencyjne kopiowanie prawej części
        }
    }

    // Destruktor
    ~Set() {
        while (root) {
            remove(root->value); // Usuwamy po kolei wartości
        }
    }

    // Operator przypisania
    Set& operator=(const Set& other) {
        if (this != &other) {
            while (root) {
                remove(root->value);  // Usuń aktualne drzewo
            }
            if (other.root) {
                insert(other.root->value); // Skopiuj wartości
                copy(other.root->left);
                copy(other.root->right);
            }
        }
        return *this;
    }

    // Metoda insert
    Set& insert(int value) {
        if (!root) {
            root = new Node(value);
        } else {
            Node* current = root;
            while (true) {
                if (value < current->value) {
                    if (!current->left) {
                        current->left = new Node(value);
                        break;
                    }
                    current = current->left;
                } else if (value > current->value) {
                    if (!current->right) {
                        current->right = new Node(value);
                        break;
                    }
                    current = current->right;
                } else {
                    break; // Wartość już istnieje, nie dodawaj
                }
            }
        }
        return *this;
    }

    // Stała metoda count
    int count(int value) const {
        Node* current = root;
        while (current) {
            if (value == current->value) {
                return 1;
            } else if (value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return 0;
    }

private:
    // Pomocnicza metoda do kopiowania elementów
    void copy(Node* node) {
        if (node) {
            insert(node->value);
            copy(node->left);
            copy(node->right);
        }
    }

    // Pomocnicza metoda do usuwania elementów
    void remove(int value) {
        Node** current = &root;
        while (*current) {
            if (value == (*current)->value) {
                Node* nodeToDelete = *current;
                if (!nodeToDelete->left) {
                    *current = nodeToDelete->right;
                } else if (!nodeToDelete->right) {
                    *current = nodeToDelete->left;
                } else {
                    Node** successor = &nodeToDelete->right;
                    while ((*successor)->left) {
                        successor = &(*successor)->left;
                    }
                    nodeToDelete->value = (*successor)->value;
                    Node* temp = *successor;
                    *successor = (*successor)->right;
                    nodeToDelete = temp;
                }
                delete nodeToDelete;
                return;
            } else if (value < (*current)->value) {
                current = &(*current)->left;
            } else {
                current = &(*current)->right;
            }
        }
    }
};

// Przykładowy program
int main() {
    Set set1, set2;
    set1.insert(1);
    (set2 = set1).insert(1).insert(3);
    const Set set3 = Set(set2).insert(4);

    for (int key = 0; key < 5; ++key) {
        std::cout << set1.count(key);
    }
    std::cout << std::endl;

    for (int key = 0; key < 5; ++key) {
        std::cout << set2.count(key);
    }
    std::cout << std::endl;

    for (int key = 0; key < 5; ++key) {
        std::cout << set3.count(key);
    }
    std::cout << std::endl;

    return 0;
}