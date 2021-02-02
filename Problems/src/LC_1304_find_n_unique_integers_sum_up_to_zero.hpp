#pragma once

#include "TestWithCUL.hpp"

class LC_1304_find_n_unique_integers_sum_up_to_zero:
    public TestWithCUL
{
protected:

    LC_1304_find_n_unique_integers_sum_up_to_zero();

    virtual ~LC_1304_find_n_unique_integers_sum_up_to_zero();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};