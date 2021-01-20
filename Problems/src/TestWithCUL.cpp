#include "TestWithCUL.hpp"

CUL::CULInterface* TestWithCUL::s_culInterface = nullptr;

CUL::CULInterface* TestWithCUL::getCUL()
{
    return s_culInterface;
}

void TestWithCUL::SetUpTestCase()
{
    s_culInterface = CUL::CULInterface::createInstance();
}

void TestWithCUL::TearDownTestCase()
{
    delete s_culInterface;
    s_culInterface = nullptr;
}