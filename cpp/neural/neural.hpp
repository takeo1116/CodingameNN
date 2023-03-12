#pragma once
#include <iostream>
#include <array>
#include <stddef.h>

template <size_t N>
class FloatVector {
private:
    std::array<float, N> storage = {};
public:
    FloatVector (){

    }
    FloatVector (std::array<float, N> x){
        storage = x;
    }
    float& operator [] (size_t i){
        return storage[i];
    }
    size_t size(){
        return N;
    }
    void dump(){
        std::cout << "(";
        for (int i=0;i<N;i++)
            std::cout << storage[i] << (i == N-1 ? ")" : ", ");
        std::cout << std::endl;
    }
};

template <size_t N, size_t M>
class FloatMatrix {
private:
    std::array<FloatVector<N>, M> storage;
public:
    FloatMatrix (){

    }
    FloatMatrix (std::array<FloatVector<N>, M> x){
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
        std::cout << "{" << std::endl;
        for (int i=0;i<M;i++)
            storage[i].dump();
        std::cout << "}" << std::endl;
    }
};