#pragma once
#include <vector>
#include <cstdint>
#include <cassert>

template<typename T>
class HeapMin
{
protected:
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
    size_t PercolateUp(size_t i){
        size_t father = Father(i);
        while(i > 0 && data[i] < data[father]){
            T temp = data[father];
            data[father] = data[i];
            data[i] = temp;
            i = father;
            father = Father(i);
        }
        return i;
    }
public:
    HeapMin()
    {
    }
    HeapMin(size_t size)
    {
        data.reserve(size);
    }
    size_t PercolateDown(size_t i){
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
        return i;
    }
    size_t Push(T elm)
    {
        data.emplace_back(elm);
        return PercolateUp(data.size() - 1);
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
    size_t size(){
        return data.size();
    }
};

template<typename T>
class HeapMax
{
protected:
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
    size_t PercolateUp(size_t i){
        size_t father = Father(i);
        while(i > 0 && data[i] > data[father]){
            T temp = data[father];
            data[father] = data[i];
            data[i] = temp;
            i = father;
            father = Father(i);
        }
        return i;
    }
public:
    HeapMax()
    {
    }
    HeapMax(std::vector<T> tab)
    {
        data = tab;
        size_t size_half = data.size()/2;
        for (int i = size_half-1; i >= 0; i--)
        {
            PercolateDown(i);
        }
    }
    HeapMax(size_t size)
    {
        data.reserve(size);
    }
    size_t PercolateDown(size_t i){
        size_t r_child = Right(i);
        size_t l_child = Left(i);
        size_t max = i;
        if(l_child < data.size() && data[max] < data[l_child])
        {
            max = l_child;
        }
        if(r_child < data.size() && data[max] < data[r_child])
        {
            max = r_child;
        }
        if(max != i){
            T temp = data[max];
            data[max] = data[i];
            data[i] = temp;
            PercolateDown(max);
        }
        return i;
    }
    size_t Push(T elm)
    {
        data.emplace_back(elm);
        return PercolateUp(data.size() - 1);
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
    size_t size(){
        return data.size();
    }
};
template<typename T>
void HeapSortDescending(std::vector<T>& tab)
{
    HeapMax heap(tab);
    for(size_t i = 0; i < tab.size(); i++)
    {
        T obj = heap.Pop();
        tab[i] = obj;
        heap.PercolateDown(i);
    }
}

template<typename T>
class OrderedPair
{
private:
public:
    T value;
    int key;
    OrderedPair(): key(0)
    {

    }
    OrderedPair(const T& value, int key): value(value), key(key)
    {

    }
    bool operator==(const OrderedPair<T>& other){
        return other.key == key;
    }
    bool operator!=(const OrderedPair<T>& other){
        return other.key != key;
    }
    bool operator>(const OrderedPair<T>& other){
        return key > other.key;
    }
    bool operator>=(const OrderedPair<T>& other){
        return key >= other.key;
    }
    bool operator<(const OrderedPair<T>& other){
        return key < other.key;
    }
    bool operator<=(const OrderedPair<T>& other){
        return key <= other.key;
    }
};

template<typename T>
class PriorityQueue: public HeapMin<OrderedPair<T>>
{
public:
    size_t Push(T elm, int key)
    {
        return HeapMin<OrderedPair<T>>::Push(OrderedPair<T>(elm, key));
    }
    size_t ChangeKey(T elm, int key)
    {
        for (size_t i = 0; i < this->data.size(); i++)
        {
            OrderedPair<T> &p = this->data[i];
            if(p.value != elm)
            {
                continue;
            }
            return ChangeKeyByIndex(i, key);
        }
        return -1;
    }
    size_t ChangeKeyByIndex(size_t i, int key)
    {
        OrderedPair<T> &p = this->data[i];
        if(p.key < key){
            p.key = key;
            return HeapMin<OrderedPair<T>>::PercolateDown(i);
        }else{
            p.key = key;
            return HeapMin<OrderedPair<T>>::PercolateUp(i);
        } 
    }
    void DeleteNode(T elm)
    {
        for (size_t i = 0; i < this->data.size(); i++)
        {
            OrderedPair<T> &p = this->data[i];
            if(p.value != elm)
            {
                continue;
            }
            DeleteNodeByIndex(i);
        }
    }
    void DeleteNodeByIndex(size_t id)
    {
        OrderedPair<T> temp = this->data[id];
        this->data[id] = this->data[this->data.size()-1];
        this->data[this->data.size() - 1] = temp;
        HeapMin<OrderedPair<T>>::PercolateUp(id);
        this->data.pop_back();
    }
};