#include <assert.h>
#include <Utils/utils.hpp>

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
    vec_tests();
}