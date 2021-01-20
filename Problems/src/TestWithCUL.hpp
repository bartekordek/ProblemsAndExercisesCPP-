#pragma once

#include "Gtest.hpp"
#include "CUL/CULInterface.hpp"

class TestWithCUL:
    public ::testing::Test
{
public:
    CUL::CULInterface* getCUL();
protected:
    static void SetUpTestCase();
    static void TearDownTestCase();
private:
    static CUL::CULInterface* s_culInterface;
};