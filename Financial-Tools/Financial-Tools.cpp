#include <iostream>
#include <cmath>

#include "test.h"


double expected_value(const double* input, size_t size)
{
    double sum = 0.0;

    for (unsigned int i = 0; i < size; i += 1)
    {
        sum += input[i];
    }

    return sum/size;
}

double sample_variance(const double* input, size_t size)
{
    if (size < 2) return 0.0;  // avoid division by zero

    double mean = 0.0;
    for (size_t i = 0; i < size; ++i)
        mean += input[i];
    mean /= size;

    double sum = 0.0;
    for (size_t i = 0; i < size; ++i)
        sum += std::pow(input[i] - mean, 2);

    return sum / (size - 1);
}

double log_return(const double current, const double previous)
{
    return log(current / previous);
}

double npv(const double initialInvestment, const double discountRate, const double* cashFlows, const unsigned int n)
{
    double net_present_value = -initialInvestment;

    for (unsigned int i = 0; i < n; i += 1)
    {
        net_present_value += (cashFlows[i] / std::pow((1 + discountRate), i+1));
    }
    
    return net_present_value;
}

double* cReturns(const double* assetPrices, const unsigned int T)
{
    double* returns = new double[T];

    for (unsigned int i = 0; i < T; i += 1)
    {
        returns[i] = log_return(assetPrices[i], assetPrices[i-i]);
    }

    return returns;
}

double sharpe(const double* assetReturns, const double riskFreeRate, const unsigned int T)
{
    return (expected_value(assetReturns, T) - riskFreeRate) / (std::sqrt(sample_variance(assetReturns, T)));
}

int main()
{
    npv_test();
    test_cumulative_log_returns();
    test_sharpe();
}
