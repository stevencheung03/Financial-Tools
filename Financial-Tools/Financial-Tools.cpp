#include <iostream>
#include <cmath>

#include "test.h"


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

int main()
{
    npv_test();
}
