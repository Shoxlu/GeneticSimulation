#pragma once
#include <vector>

template<typename T>
class HeapMin
{
private:
    std::vector<T> data;
    size_t Right(size_t i)
    {
        return 2 * i + 2;
    }
    size_t Left(size_t i)
    {
        return 2 * i + 1;
    }
    size_t Father(size_t i)
    {
        return (i - 1) / 2;
    }
    void PercolateDown(size_t i){
        size_t r_child = Right(i);
        size_t l_child = Left(i);
        size_t min = i;
        if(l_child < data.size() && data[min] > data[l_child])
        {
            min = l_child;
        }
        if(r_child < data.size() && data[min] > data[r_child])
        {
            min = r_child;
        }
        if(min != i){
            T temp = data[min];
            data[min] = data[i];
            data[i] = temp;
            PercolateDown(min);
        }
    }
    void PercolateUp(size_t i){
        size_t father = Father(i);
        while(i > 0 && data[i] < data[father]){
            T temp = data[father];
            data[father] = data[i];
            data[i] = temp;
            i = father;
            father = Father(i);
        }
    }
public:
    HeapMin()
    {
    }
    HeapMin(size_t size)
    {
        data.reserve(size);
    }
    void Push(T elm)
    {
        data.emplace_back(elm);
        PercolateUp(data.size() - 1);
    }
    T& Top(){
        return data[0];
    }
    T Pop(){
        assert(!IsEmpty());
        T elm = Top();
        T last = data[data.size()-1];
        data.pop_back();
        if(!IsEmpty()){
            data[0] = last;
            PercolateDown(0);
        }
        return elm;
    }
    bool IsEmpty(){
        return data.size() == 0;
    }
    T operator[](size_t i)
    {
        return data[i];
    }
    std::vector<T> &GetRawData(){
        return data;
    }
};

template<typename T>
class OrderedPair
{
private:
    T value;
    int rank;

public:
    OrderedPair(const T& value, int rank): value(value), rank(rank)
    {

    }
    bool operator==(const OrderedPair<T>& other){
        return other.rank == rank;
    }
    bool operator!=(const OrderedPair<T>& other){
        return other.rank != rank;
    }
    bool operator>(const OrderedPair<T>& other){
        return rank > other.rank;
    }
    bool operator>=(const OrderedPair<T>& other){
        return rank >= other.rank;
    }
    bool operator<(const OrderedPair<T>& other){
        return rank < other.rank;
    }
    bool operator<=(const OrderedPair<T>& other){
        return rank <= other.rank;
    }
};

