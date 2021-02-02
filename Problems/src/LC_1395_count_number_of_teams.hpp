#pragma once

#include "TestWithCUL.hpp"

class LC_1395_count_number_of_teams:
    public TestWithCUL
{
protected:

    LC_1395_count_number_of_teams();

    virtual ~LC_1395_count_number_of_teams();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;

    static CUL::LOG::ILogger* s_logger;

private:

};