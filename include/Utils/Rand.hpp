#pragma once

class Random
{
private:
    static float RandFloat01();
    static float RandFloatMinus1To1();
public:
    static void Tests();
    //Min et Max inclus
    static int RandInt(int min, int max);
    //Min et Max inclus
    static float RandFloat(float min, float max);
    static void Init();
    static void InitSeed(int seed);
    Random();
    ~Random();
};


