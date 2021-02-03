#pragma once

#include "TestWithCUL.hpp"

class LC_728_self_dividing_numbers:
    public TestWithCUL
{
protected:

    LC_728_self_dividing_numbers();

    virtual ~LC_728_self_dividing_numbers();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};