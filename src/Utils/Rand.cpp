#include <Utils/Rand.hpp>
#include <Utils/Error/error.hpp>
#include <random>
#include <assert.h>
#include <time.h>

Random::Random()
{
}

Random::~Random()
{
}

void Random::Tests()
{
    size_t n_tests = 20;
    for (size_t i = 0; i < n_tests; i++)
    {
        float r = Random::RandFloat01();
        assert(r <= 1 && r >= 0);
        // log_printf("%f,", r);
    }
    // log_printf("\n");
    for (size_t i = 0; i < n_tests; i++)
    {
        float r = Random::RandFloatMinus1To1();
        assert(r <= 1 && r >= -1);
        // log_printf("%f,", r);
    }
    // log_printf("\n");
    for (size_t i = 0; i < n_tests; i++)
    {
        int r = Random::RandInt(-3, 4);
        assert(r <= 4 && r >= -3);
        // log_printf("%d,", r);
    }
    // log_printf("\n");
    for (size_t i = 0; i < n_tests; i++)
    {
        float r = Random::RandFloat(-3, 4);
        assert(r <= 4 && r >= -3);
        // log_printf("%f,", r);
    }
    float mu = 100;
    float s = 20;
    for(size_t i = 0; i < n_tests; i++)
    {
        float r = Random::NormalWithdraw(mu, s);
        log_printf("%f,", r);
    }
    log_printf("\n");
}

void Random::Init(){
    InitSeed(time(NULL));
}

void Random::InitSeed(int seed){
    srand(seed);
}

float Random::RandFloat01(){
    return (float)rand() / RAND_MAX;
}

//Je suis pas sûr que ce soit utile 
float Random::RandFloatMinus1To1(){
    return (RandFloat01() - 0.5) * 2.0;
}

float Random::RandFloat(float min, float max)
{
    return RandFloat01() * (max - min) + min;
}

//Assume que min <= max...
int Random::RandInt(int min, int max){
    return rand() % (max - min + 1) + min;
}

bool Random::RandBool()
{
    return RandInt(0, 1) == 1;
}

double Random::Normal(double mu,double sigma)
{

    double u1 = RandFloat01();
    double u2 = RandFloat01();

    // éviter log(0)
    if (u1 < 1e-12)
        u1 = 1e-12;

    double z = std::sqrt(-2.0 * std::log(u1))
                * std::cos(2.0 * M_PI * u2);

    return mu + sigma * z;
    // double gauss_constant = 1.0 / sqrt(2 * M_PI);
    // double t = Random::RandFloat(-1, 1);
    // return exp((-1.0 / 2.0) * (t - mu) * (t - mu) / (sigma * sigma))/(sigma*sqrt(2*M_PI));
}
double Random::NormalWithdraw(double x,double delta_x)
{

    return Normal(x, delta_x / 3);
    // double gauss_constant = 1.0 / sqrt(2 * M_PI);
    // double t = Random::RandFloat(-1, 1);
    // return exp((-1.0 / 2.0) * (t - mu) * (t - mu) / (sigma * sigma))/(sigma*sqrt(2*M_PI));
}