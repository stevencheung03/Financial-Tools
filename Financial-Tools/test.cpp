#include <iostream>

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
