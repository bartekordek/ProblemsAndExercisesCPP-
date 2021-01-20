#pragma once

#include "TestWithCUL.hpp"

class LC_1588_sum_of_all_odd_length_subarrays:
    public TestWithCUL
{
protected:

    LC_1588_sum_of_all_odd_length_subarrays();

    virtual ~LC_1588_sum_of_all_odd_length_subarrays();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};