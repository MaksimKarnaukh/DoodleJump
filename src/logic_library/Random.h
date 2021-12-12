//
// Created by centu on 17/11/2021.
//
// https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
// https://stackoverflow.com/questions/7114043/random-number-generation-in-c11-how-to-generate-how-does-it-work
// https://en.cppreference.com/w/cpp/numeric/random

#ifndef DOODLEJUMP_RANDOM_H
#define DOODLEJUMP_RANDOM_H

#include <random>

namespace logic {

    class Random {

        std::random_device rd;
        std::mt19937 randomEngine; // mersenne_twister_engine (seeded with randomDevice())

        Random();
        ~Random();

    public:

        static Random& sInstance;

        Random(const Random &) = delete;
        Random(const Random &&) = delete;

        Random& operator=(const Random &) = delete;
        Random& operator=(const Random &&) = delete;

        static Random& Instance();

    public:

        // Uniform distributions

        int uniformIntDistribution(int a, int b);

        float uniformRealDistribution(float a, float b);

        // Bernoulli distributions

        bool bernoulliDistribution(float p);

        int binomialDistribution(float p, int t);

        int negativeBinomialDistribution(float p, int k);

        int geometricDistribution(float p);

        // Poisson distributions

        int poissonDistribution(float mean);

        float exponentialDistribution(float lambda);

        float gammaDistribution(float alpha, float beta);

        float weibullDistribution(float a, float b);

        float extremeValueDistribution(float a, float b);

        // Normal distributions

        float normalDistribution(float mean, float stddev);

        float lognormalDistribution(float m, float s);

        float cauchyDistribution(float a, float b);

        // Sampling distributions

        int discreteDistribution(const std::initializer_list<double>& probabilities);

        // https://www.boost.org/doc/libs/1_75_0/doc/html/boost/random/piecew_1_3_35_5_6_31_1_1_1.html
        float piecewiseConstantDistribution(const std::vector<float>& intervals, const std::vector<float>& densities);

        // https://www.boost.org/doc/libs/1_75_0/doc/html/boost/random/piecew_1_3_35_5_6_32_1_1_1.html
        float piecewiseLineairDistribution(const std::vector<float>& intervals, const std::vector<float>& densities);

    };

}

#endif //DOODLEJUMP_RANDOM_H
