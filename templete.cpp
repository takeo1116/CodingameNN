// NNをC++で使用するテンプレート
#include <iostream>
#include <array>
#include <stddef.h>
using namespace std;

template <size_t N>
class FloatVector {
private:
    array<float, N> storage = {};
public:
    FloatVector (){

    }
    FloatVector (array<float, N> x){
        storage = x;
    }
    float& operator [] (size_t i){
        return storage[i];
    }
    size_t size(){
        return N;
    }
    void dump(){
        cout << "(";
        for (int i=0;i<N;i++)
            cout << storage[i] << (i == N-1 ? ")" : ", ");
        cout << endl;
    }
};

template <size_t N, size_t M>
class FloatMatrix {
private:
    array<FloatVector<N>, M> storage;
public:
    FloatMatrix (){

    }
    FloatMatrix (array<FloatVector<N>, M> x){
        storage = x;
    }
    FloatVector<N>& operator [] (size_t i){
        return storage[i];
    }
    FloatVector<M> operator * (FloatVector<N> x){
        FloatVector<M> y;
        for (int i=0;i<M;i++)
            for (int j=0;j<N;j++)
                y[i] += storage[i][j] * x[j];
        return y;
    }
    void dump(){
        cout << "{" << endl;
        for (int i=0;i<M;i++)
            storage[i].dump();
        cout << "}" << endl;
    }
};

int main(){
    FloatVector<2> vector({1.0, 2.2});
    vector.dump();
    FloatMatrix<2, 3> matrix({FloatVector<2>({1, 2}), FloatVector<2>({3, 4}), FloatVector<2>({5, 6})});
    matrix[0][0] = 1.0f;
    matrix.dump();
    (matrix * vector).dump();
    cout << matrix[0][0] << endl;
    return 0;
}