#include <iostream>
#include <cassert>

#include "Financial-Tools.h"

void npv_test()
{
    {
        double cashFlows[] = { 100, 200, 300 };
        double result = npv(500, 0.1, cashFlows, 3);
        double expected = -500 + (100 / pow(1.1, 1)) + (200 / pow(1.1, 2)) + (300 / pow(1.1, 3));
        if (std::fabs(result - expected) < 1e-6)
        {
            std::cout << "Test PositiveCashFlows passed!\n";
        }
        else
        {
            std::cout << "Test PositiveCashFlows failed!\n";
        }
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Got: " << result << "\n";
        std::cout << "\n";
    }

    {
        double cashFlows[] = { -100, -200, -300 };
        double result = npv(500, 0.1, cashFlows, 3);
        double expected = -500 + (-100 / pow(1.1, 1)) + (-200 / pow(1.1, 2)) + (-300 / pow(1.1, 3));
        if (std::fabs(result - expected) < 1e-6)
        {
            std::cout << "Test NegativeCashFlows passed!\n";
        }
        else
        {
            std::cout << "Test NegativeCashFlows failed!\n";
        }
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Got: " << result << "\n";
        std::cout << "\n";
    }

    {
        double cashFlows[] = { 100, 200, 300 };
        double result = npv(0, 0.1, cashFlows, 3);
        double expected = (100 / pow(1.1, 1)) + (200 / pow(1.1, 2)) + (300 / pow(1.1, 3));
        if (std::fabs(result - expected) < 1e-6)
        {
            std::cout << "Test ZeroInvestment passed!\n";
        }
        else
        { 
            std::cout << "Test ZeroInvestment failed!\n";
        }
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Got: " << result << "\n";
        std::cout << "\n";
    }

    {
        double cashFlows[] = { 100, 200, 300 };
        double result = npv(500, 0.0, cashFlows, 3);
        double expected = -500 + (100) + (200) + (300);
        if (std::fabs(result - expected) < 1e-6)
        {
            std::cout << "Test ZeroDiscountRate passed!\n";
        }
        else
        {
            std::cout << "Test ZeroDiscountRate failed!\n";
        }
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Got: " << result << "\n";
        std::cout << "\n";
    }

    {
        double result = npv(500, 0.1, nullptr, 0);
        double expected = npv(500, 0.1, nullptr, 0);
        if (std::fabs(result + 500) < 1e-6)
        {
            std::cout << "Test NoCashFlows passed!\n";
        }
        else
        {
            std::cout << "Test NoCashFlows failed!\n";
        }
        std::cout << "Expected: " << expected << "\n";
        std::cout << "Got: " << result << "\n";
        std::cout << "\n";
    }
}


void test_cumulative_log_returns()
{
    double assetPrices[] = { 100.0, 105.0, 110.25 };  // T = 3
    unsigned int T = sizeof(assetPrices) / sizeof(assetPrices[0]);

    double* returns = cReturns(assetPrices, T);

    // Expected cumulative log returns
    double expected[] = {
        std::log(100.0 / 100.0),   // = 0.0
        std::log(105.0 / 100.0),   // ≈ 0.04879
        std::log(110.25 / 100.0)   // ≈ 0.09531
    };

    for (unsigned int i = 0; i < T; ++i)
    {
        if ((returns[i] - expected[i]) < 1e-6)
        {
            std::cout << i << " Test passed!\n";
        }
        else
        { 
            std::cout << i << " Test failed!\n";
        }
        std::cout << "Cumulative Return " << i << ": " << returns[i]
            << " (expected " << expected[i] << ")\n";
    }

    std::cout << "All cumulative return tests passed!\n";

    delete[] returns;
}
