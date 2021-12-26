

#include "Random.h"

namespace logic {
    namespace utility {

        Random::Random() {
            randomEngine = std::mt19937(rd());
        };

        Random::~Random() = default;

        Random &Random::Instance() {
            static Random instance;
            return instance;
        }

        int Random::uniformIntDistribution(const int a, const int b) {
            std::uniform_int_distribution<int> uint_dist(a, b);
            return uint_dist(randomEngine);
        }

        float Random::uniformRealDistribution(const float a, const float b) {
            std::uniform_real_distribution<float> ureal_dist(a, b);
            return ureal_dist(randomEngine);
        }

        bool Random::bernoulliDistribution(const float p) {
            std::bernoulli_distribution bern_dist(p);
            return bern_dist(randomEngine);
        }

        int Random::binomialDistribution(const float p, const int t) {
            std::binomial_distribution<int> bin_dist(t, p);
            return bin_dist(randomEngine);
        }

        int Random::negativeBinomialDistribution(const float p, const int k) {
            std::negative_binomial_distribution<int> neg_bin_dist(k, p);
            return neg_bin_dist(randomEngine);
        }

        int Random::geometricDistribution(const float p) {
            std::geometric_distribution<int> geo_dist(p);
            return geo_dist(randomEngine);
        }

        int Random::poissonDistribution(const float mean) {
            std::poisson_distribution<int> poission_dist(mean);
            return poission_dist(randomEngine);
        }

        float Random::exponentialDistribution(const float lambda) {
            std::exponential_distribution<float> exp_dist(lambda);
            return exp_dist(randomEngine);
        }

        float Random::gammaDistribution(const float alpha, const float beta) {
            std::gamma_distribution<float> gamma_dist(alpha, beta);
            return gamma_dist(randomEngine);
        }

        float Random::weibullDistribution(const float a, const float b) {
            std::weibull_distribution<float> weibull_dist(a, b);
            return weibull_dist(randomEngine);
        }

        float Random::extremeValueDistribution(const float a, const float b) {
            std::extreme_value_distribution<float> extreme_dist(a, b);
            return extreme_dist(randomEngine);
        }

        float Random::normalDistribution(const float mean, const float stddev) {
            std::normal_distribution<float> normal_dist(mean, stddev);
            return normal_dist(randomEngine);
        }

        float Random::lognormalDistribution(const float m, const float s) {
            std::lognormal_distribution<float> lognormal_dist(m, s);
            return lognormal_dist(randomEngine);
        }

        float Random::cauchyDistribution(const float a, const float b) {
            std::cauchy_distribution<float> cauchy_dist(a, b);
            return cauchy_dist(randomEngine);
        }

        int Random::discreteDistribution(const std::initializer_list<double>& probabilities) {
            std::discrete_distribution<int> disc_dist(probabilities);
            return disc_dist(randomEngine);
        }

        float Random::piecewiseConstantDistribution(const std::vector<float>& intervals, const std::vector<float>& densities) {
            std::piecewise_constant_distribution<float> piecew_const_dist(&intervals[0], &intervals[0]+intervals.size(), &densities[0]);
            return piecew_const_dist(randomEngine);
        }

        float Random::piecewiseLineairDistribution(const std::vector<float>& intervals, const std::vector<float>& densities) {
            std::piecewise_constant_distribution<float> piecew_lin_dist(&intervals[0], &intervals[0]+intervals.size(), &densities[0]);
            return piecew_lin_dist(randomEngine);
        }
    }
}







