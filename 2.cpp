#include <iostream>
#include <vector>

template <typename T>
class Stack {
public:
std::vector<T> dane;
    Stack() = default;
    Stack(std::initializer_list<T> lista) : dane(lista) {}

    void push(const T& wartosc) {
        dane.push_back(wartosc);
    }
friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
        os << "{";
        for (size_t i = 0; i < stack.dane.size(); ++i) {
            os << stack.dane[i];
            if (i != stack.dane.size() - 1) {
                os << ", ";
            }
        }
        os << "}";
        return os;
    }
    void merge(const Stack<T>& nowe) {
    for (const auto& item : nowe.dane) {
        this->push(item);
    }
}
friend std::istream& operator>>(std::istream& is, Stack<T>& stack) {
    T wartosc;
    is >> wartosc;
    stack.push(wartosc);
    return is;
}
    
    
};

int main() {
    Stack<int> intStack;
    Stack<int> il= {10, 20, 30};
    
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    
    std::cout << "Int stack: " << intStack << std::endl;
    std::cout << "il: " << il << std::endl;
    intStack.merge(il);
    std::cout << "polaczoneint: " << intStack << std::endl;

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    Stack<std::string> ss = {"World", "!"};


    std::cout << "String stack: " << stringStack << std::endl;
    std::cout << "ss: " << ss << std::endl;
    
    
    stringStack.merge(ss);
    std::cout << "polaczone string: " << stringStack << std::endl;

    return 0;
}
