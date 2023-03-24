#include <iostream>
#include <sstream>
using namespace std;

// classe que implementa uma lista redimensionável
class Vector
{
private:
    int m_capacity{0}; // esse {} é o modo de inicializar default do c++ a partir do c++11
    int m_size{0};
    int *m_data{nullptr}; // inicializar pra não conter lixo

public:
    // construtor vazio
    Vector()
    {
        // inicialize this->m_capacity com 10
        this->m_capacity = 10;
        // inicialize this->m_size com 0
        this->m_size = 0;
        // crie memória dinamicamente para this->m_data com tamanho m_capacity
        this->m_data = new int[m_capacity];
    }
    // construtor
    Vector(int capacity)
    {
        // se capacity <= 0, entao inicialize this->m_capacity com 10
        if (capacity <= 0)
        {
            this->m_capacity = 10;
        }
        // caso contrario, inicialize this->m_capacity com capacity.
        else
        {
            this->m_capacity = capacity;
            this->m_size = 0;
            this->m_data = new int[m_capacity];
        }
        // inicialize this->m_size com 0
        // crie memória dinamicamente para this->m_data com tamanho m_capacity
    }

    // destrutor
    ~Vector()
    {
        delete[] this->m_data;
    }

    int size()
    {
        return m_size;
    }

    int capacity()
    {
        return m_capacity;
    }

    // como seu vector tem atritutos do tipo ponteiros, você precisa criar um
    // construtor de cópia e um operador de atribuição ou terá erros do tipo double-free

    // construtor de cópia
    // aqui você ensina seu vector a ser criado a partir de outro vector
    // Ex:
    // Vector v(4);
    // Vector v2(v);
    Vector(Vector &other)
    {
        // inicialize this->m_capacity com other.m_capacity
        this->m_capacity = other.m_capacity;
        // inicialize this->m_size com other.m_size
        this->m_size = other.m_size;
        // libere a memória em this->m_data
        this->m_data = 0;
        // crie memória dinamicamente para this->m_data com tamanho m_capacity
        this->m_data = new int[m_capacity];
        // copie os elementos de other.data para this->m_data
        for (int i = 0; i < other.size(); i++)
        {
            this->m_data[i] = other.m_data[i];
        }
    }

    // O operador de atribuição será invocado quando você fizer um Vector receber outro
    // Ex:
    // Vector vec(4);
    // vec = Vector(6);
    // nesse ponto, os atributos de this já foram inicializados,
    // mas você precisa alterá-los para copiar os valores de other
    const Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            // inicialize this->m_capacity com other.m_capacity
            this->m_capacity = other.m_capacity;
            // inicialize this->m_size com other.m_size
            this->m_size = other.m_size;
            // se this->m_data não for nulo, devolva a memória com delete
            if (this->m_data != nullptr)
            {
                delete[] this->m_data;
            }
            else
            {
                this->m_data = new int[other.m_capacity];
                for (int i = 0; i < other.m_capacity; i++)
                {
                    this->m_data = other.m_data;
                }
            }
            // crie nova memória para this->m_data do tamanho de other.m_capacity
            // copie os dados de other.m_data para this->m_data
        }
        return *this;
    }

    // adiciona um valor ao final da lista
    void push_back(int value)
    {
        // se vector estiver cheio, aumenta o tamanho para o dobro do tamanho anterior
        if (m_size == m_capacity)
        {
            m_capacity * 2;
        }
        // depois, adiciona value ao final do vector
        m_data[m_size] = value;
        // incrementa m_size
        m_size++;
    }

    // remove um valor do final da lista
    int pop_back()
    {
        // se a lista estiver vazia, então lance um erro do tipo std::runtime_error
        if (m_size == 0)
        {
            throw std::runtime_error("Lista vazia");
        }
        // caso contrário:
        else
        {
            // 1. remova o valor do final do vector e guarde-o em uma variavel auxiliar
            int *aux = this->m_data[this->m_size - 1];
            // 2. decremente m_size
            m_size--;
            // 3. se m_size < m_capacity/2, diminua m_capacity para m_capacity/2
            if (this->m_size < (this>m_capacity / 2))
            {
                this->m_capacity = this->m_capacity / 2;
                int *auxiliar = new int(this->m_capacity / 2);
                for (int i = 0; i < this->m_size; i++) 
                {
                    this->auxiliar[i] = this->m_data[i];
                }
                delete[] this->m_data;
                this->m_data = this->auxiliar;
            }
            // 4. diminua o tamanho de m_data para m_capacity/2 e realoque os elementos
            // 5. retorne o valor removido
            return aux;
        }
    }

    // esse é o toString
    // retorna uma string contendo a lista formatada
    // Ex: uma lista com elementos 2,3,4,5 deve ser
    //  retornada como a string: "[2,3,4,5]"
    std::string toString()
    {
        std::stringstream ss;
        ss << "[";
        int *atual = m_data->m_size;
        while (atual != nullptr)
        {
            ss << atual->m_size << " ";
            atual = atual->m_size;
        }
        ss << "]";
        return ss.str();
    }

    /*std::string toString()
    {
        std::stringstream ss;
        ss << "[";
        Node *atual = m_head->next;
        while (atual != nullptr)
        {
            ss << atual->value << " ";
            atual = atual->next;
        }
        ss << "]";
        return ss.str();
    }
*/
};
/* NAO MEXA DAQUI PRA BAIXO */
int main()
{
    string line, cmd;
    int value;
    Vector v(0);
    while (true)
    {
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "init")
        {
            ss >> value;
            v = Vector(value);
        }
        else if (cmd == "status")
        {
            cout << "size:" << v.size() << " capacity:" << v.capacity() << "\n";
        }
        else if (cmd == "push_back")
        {
            while (ss >> value)
                v.push_back(value);
        }
        else if (cmd == "pop_back")
        {
            ss >> value;
            cout << "popped: ";
            for (int i = 0; i < value; ++i)
                cout << v.pop_back() << " ";
            cout << endl;
        }
        else if (cmd == "show")
        {
            cout << v.toString() << endl;
        }
        else
        {
            cout << "fail: comando invalido\n";
        }
    }
}
