#include <iostream>
#include <type_traits>
#include <typeinfo>

template <typename T1, typename... Ts>
class VariantNode {
private:
    std::aligned_union_t<0, Ts...> data_storage;
    std::size_t type_hash;
public:
    VariantNode<T1, Ts...>* prev, * next;
    ~VariantNode() { std::cout << "Descructor VariantNode\n"; }
    std::size_t get_type_hash() const {
        return this->type_hash;
    }

    template <typename T>
    void set_data(T data) {
        T* data_ptr = new(&data_storage) T(data); //I dont understand this syntax new (...) int(5)
        type_hash = typeid(T).hash_code();
    }

    template <typename T>
    VariantNode(T data) {
        this->set_data<T>(data);
    }

    template <typename T>
    VariantNode<T1, Ts...>& operator= (T data) {
        this->set_data<T>(data);
        return *this;
    }

    template <typename T>
    T get_data() {
        return *reinterpret_cast<T*>(&this->data_storage);
    }

    template <typename... Fs>
    friend std::ostream& operator<<(std::ostream& out, const VariantNode<Fs...>& node);
};

template <typename F>
void print_data(std::ostream& out, ::size_t type_hash, const void* data) {
    out << *reinterpret_cast<const F*>(data);
}

template <typename F1, typename F2, typename... Fs>
void print_data(std::ostream& out, ::size_t type_hash, const void* data) {
    if (type_hash == typeid(F1).hash_code())
        out << *reinterpret_cast<const F1*>(data);
    else
        print_data<F2, Fs...>(out, type_hash, data);
}

template <typename... Fs>
std::ostream& operator<< (std::ostream& out, const VariantNode<Fs...>& node) {
    print_data<Fs...>(out, node.get_type_hash(), &node.data_storage);
    return out;
}

template <typename... Ts>
class ID_Massiv
{
private:
    VariantNode<Ts...>* first, * last, * current;
    int len;
public:

    int get_len() { return len; }
    ID_Massiv() { first = last = current = nullptr; len = 0; }
    ~ID_Massiv()
    {
        current = first;
        while (first != nullptr)
        {
            first = first->next;
            delete  current;
            current = first;
        }
    };
    void Ate(VariantNode<Ts...>* var_class)
    {
        if (first == nullptr) //Отредачить потом на проверку просто first
        {
            last = current = first = var_class; len++;
        }
        else {
            var_class->next = first;
            first->prev = var_class;
            first = var_class;
            len++;
        }
    };

    template <typename T>
    void Ate(T data) {
        this->Ate(new VariantNode<Ts...>(data));
    }

    VariantNode<Ts...>& operator[](int number)
    {
        current = last;
        int i = 0;  bool key = true;
        while (current != nullptr && key)
        {
            if (i++ == number)
            {
                return *current;
                key = false;
            }
            current = current->prev;
        }
    }
};

int main() {
    ID_Massiv<int, double, char> mass;

    mass.Ate(3);
    mass.Ate(2.4);

    std::cout << mass[0] << ' ' << mass[1] << std::endl;

    mass[0] = 'a';
    mass[1] = 5;

    std::cout << mass[0] << ' ' << mass[1] << std::endl;
    mass[0] = 5.7;
    mass[1] = 'm';

    std::cout << mass[0] << ' ' << mass[1] << std::endl;

    return 0;
}