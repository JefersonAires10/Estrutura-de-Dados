#include <iostream>
#include <vector>
using namespace std;

vector<int> rotaciona(vector<int> &vet){
    vector<int> aux;
    int n = vet.size();
    aux.push_back(vet.at(n-1));
    for(int j=1; j<vet.size(); j++){
        aux.push_back(vet.at(j-1));
    }
    return aux;
    
}

void right_rotation(vector<int>& vet, int nrot){
    int n = vet.size();
    vector<int> aux(vet);
    for(int i =0;i<nrot;i++){
        aux=rotaciona(aux);
    }
    for(int i=0;i<aux.size();i++){
        vet[i]= aux[i];
    }
}


void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}
// mdsssssssssssssssssssssss
int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}
