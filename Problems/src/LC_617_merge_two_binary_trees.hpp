#pragma once

#include "TestWithCUL.hpp"

class LC_617_merge_two_binary_trees:
    public TestWithCUL
{
protected:

    LC_617_merge_two_binary_trees();

    virtual ~LC_617_merge_two_binary_trees();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};