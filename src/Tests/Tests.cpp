#include <assert.h>
#include <Utils/utils.hpp>
#include <Utils/Heap/Heap.hpp>
void rand_tests(){
    Random::Init();
    Random::Tests();
}

void PrintHeap(HeapMin<int> h){
    std::vector<int> data = h.GetRawData();
    for(int& i : data){
        log_printf("%d, ", i);
    }
    log_printf("\n");
}

void PrintTab(std::vector<int> t){
    for(int& i : t){
        log_printf("%d, ", i);
    }
    log_printf("\n");
}

void PrintQueue(PriorityQueue<float> h){
    std::vector<OrderedPair<float>> data = h.GetRawData();
    for(OrderedPair<float>& i : data){
        log_printf("%f %d, ", i.value, i.key);
    }
    log_printf("\n");
}

void heap_test()
{
    
    HeapMin<int> h;
    h.Push(3);
    PrintHeap(h);
    h.Push(10);
    PrintHeap(h);
    h.Push(2);
    PrintHeap(h);
    h.Push(8);
    PrintHeap(h);
    h.Push(1);
    PrintHeap(h);
    h.Push(120);
    PrintHeap(h);
    h.Push(30);
    h.Push(13);
    h.Push(4);
    h.Push(6);
    PrintHeap(h);
    log_printf("Deconstruction of Heap:\n");
    int elm = 0;
    while (!h.IsEmpty())
    {
        elm = h.Pop();
        log_printf("%d, ", elm);
    }
    log_printf("\nEnd of heap tests\n");
    PriorityQueue<float> q;
    q.Push(2.3, 0);
    q.Push(1.3, 2);
    q.Push(2.9, 1);
    q.Push(3.7, 3);
    q.Push(1.2, 1);
    PrintQueue(q);
    // q.ChangeKey(2.3, 10);
    // PrintQueue(q);
    q.DeleteNode(2.9);
    PrintQueue(q);
    log_printf("Deconstruction of PrioQueue:\n");
    OrderedPair<float> elm1(0.0, 0);
    while (!q.IsEmpty())
    {
        elm1 = q.Pop();
        log_printf("%f %d, ", elm1.value, elm1.key);
    }
    log_printf("\nEnd of PrioQueue tests\n");
    std::vector<int> t;
    t.emplace_back(3);
    t.emplace_back(1);
    t.emplace_back(5);
    t.emplace_back(2);
    t.emplace_back(9);
    t.emplace_back(7);
    HeapSortDescending(t);
    log_printf("Heap Sort descending:\n");
    PrintTab(t);
    t.emplace_back(192);
    HeapSortDescending(t);
    log_printf("Heap Sort descending 2:\n");
    PrintTab(t);
}


void vec_tests(){
    Vec a = Vec(1, 2);
    assert(a == Vec(1, 2));
    assert(a != Vec(2, 2));
    assert(a != Vec(1, 3));
    a -= Vec(1, 2);
    assert(a == Vec(0, 0));
    a = a + 4.0 * Vec(4, 1);
    assert(a == Vec(16, 4));
    a = a - Vec(1, 2)* 4.0;
    assert(a == Vec(12, -4));
    a = a / 4.0;
    assert(a == Vec(3, -1));
    a *= 6.0;
    assert(a == Vec(18, -6));
    a /= 2.0;
    assert(a == Vec(9, -3));
    a = -a;
    assert(a == Vec(-9, 3));
    a += Vec(9, -3);
    assert(a == Vec(0, 0));
}

void tests(){
    rand_tests();
    vec_tests();
    heap_test();
}