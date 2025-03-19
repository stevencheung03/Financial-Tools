#ifndef FINANCIAL_TOOLS_H
#define FINANCIAL_TOOLS_H

double npv(const double initialInvestment, const double discountRate, const double* cashFlows, const unsigned int n);

// double* cReturns(const double* assetPrices, const unsigned int T);

// double sharpe(const double* assetReturns, const double riskFreeRate, const unsigned int T);

// double* smas(const double* assetPrices, const unsigned int k, const unsigned int T);

// double* prices(const double* meanLogReturns, const double initialPrice, const unsigned int T);

#endif
