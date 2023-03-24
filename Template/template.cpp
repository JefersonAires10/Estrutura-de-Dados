#include <iostream>
#include <string>
#include <vector>

using namespace std;

// compara dois inteiros e retorna o maior entre eles
namespace UFC {
    template< typename T > 
    T max(T x, T y)
    { 
        if (x >= y) 
            return x;
        else
            return y;
    }

    template <typename N>
    void print(vector<N> &vec)
    {
        for (int i = 0; i < (int)vec.size(); i++) 
        {
            cout << vec[i] << " ";
            cout << endl;
        }
    }
}
int main()
{
    cout << UFC::max(34, 67) << endl;
    cout << UFC::max(54.7, 67.8) << endl;
    cout << UFC::max("ana", "aba") << endl;

}

