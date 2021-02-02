#pragma once

#include "TestWithCUL.hpp"

class LC_1370_increasing_decreasing_string:
    public TestWithCUL
{
protected:

    LC_1370_increasing_decreasing_string();

    virtual ~LC_1370_increasing_decreasing_string();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};