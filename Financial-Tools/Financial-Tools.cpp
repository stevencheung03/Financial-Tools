#include <iostream>
#include <cmath>

#include "test.h"


double expected_value(const double* input)
{
    double sum = 0.0;

    for (unsigned int i = 0; i < sizeof(input); i += 1)
    {
        sum += input[i];
    }

    return sum/sizeof(n);
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
        net_present_value += (cashFlows[i] / pow((1 + discountRate), i+1));
    }
    
    return net_present_value;
}

double* cReturns(const double* assetPrices, const unsigned int T)
{
    double* returns = new double[T-1];

    for (unsigned int i = 1; i < T; i += 1)
    {
        returns[i - 1] = log_return(assetPrices[i], assetPrices[i - 1]);
    }

    return returns;
}

double sharpe(const double* assetReturns, const double riskFreeRate, const unsigned int T)
{
    return 0.0
}

int main()
{
    npv_test();
}
