// Copyright (c) Microsoft Corporation
// Licensed under the MIT license. See LICENSE file in the project root for full license information.


#define DEFINE_TEST_CASE_TAEF(TestCaseMethodName)  \
    BEGIN_TEST_METHOD(TestCaseMethodName) \
        TEST_METHOD_PROPERTY(L"Owner", TEST_CLASS_OWNER) \
    END_TEST_METHOD()

#define DEFINE_TEST_CASE_WITH_DESC(TestCaseMethodName, TestCaseDescription)  \
    BEGIN_TEST_METHOD(TestCaseMethodName) \
        TEST_METHOD_PROPERTY(L"Owner", TEST_CLASS_OWNER) \
        TEST_METHOD_PROPERTY(L"Description", TestCaseDescription) \
    END_TEST_METHOD()

#define DEFINE_TEST_CASE_PROPERTIES_TAEF(x) \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Owner", TEST_CLASS_OWNER) \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
        END_TEST_METHOD_PROPERTIES() \
        UnitTestBaseProperties t(L#x)

#define DEFINE_TEST_CASE_PROPERTIES_TAEF_IGNORE() \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Owner", TEST_CLASS_OWNER) \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
            TEST_METHOD_PROPERTY(L"Ignore", L"1") \
        END_TEST_METHOD_PROPERTIES()

#define DEFINE_TEST_CASE_PROPERTIES_TAEF_FOCUS() \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Owner", TEST_CLASS_OWNER) \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
            TEST_METHOD_PROPERTY(L"Focus", L"1") \
        END_TEST_METHOD_PROPERTIES()

#define DEFINE_TEST_CASE_PROPERTIES_TAEF_FAILING() \
        BEGIN_TEST_METHOD_PROPERTIES() \
            TEST_METHOD_PROPERTY(L"Owner", TEST_CLASS_OWNER) \
            TEST_METHOD_PROPERTY(L"Setup", L"1") \
            TEST_METHOD_PROPERTY(L"Failing", L"1") \
        END_TEST_METHOD_PROPERTIES()

#define DEFINE_TEST_CASE_WITH_DATA(TestCaseMethodName,TestCaseDataName,TestCaseDataValues)  \
    BEGIN_TEST_METHOD(TestCaseMethodName) \
        TEST_METHOD_PROPERTY(L"Owner", TEST_CLASS_OWNER) \
        TEST_METHOD_PROPERTY(TestCaseDataName,TestCaseDataValues) \
    END_TEST_METHOD()

#define DEFINE_TEST_CLASS_SETUP() \
    TEST_CLASS_SETUP(TestClassSetup) { UnitTestBase::StartResponseLogging(); return true; } \
    TEST_CLASS_CLEANUP(TestClassCleanup) { UnitTestBase::RemoveResponseLogging(); return true; }  \

#ifdef USING_TAEF
    //void VERIFY_ARE_EQUAL_STR(Platform::String^ expected, std::wstring actual);
    //void VERIFY_ARE_EQUAL_STR(Platform::String^ expected, Platform::String^ actual);
    //void VERIFY_ARE_EQUAL_STR(std::wstring expected, std::wstring actual);

    #define DEFINE_TEST_CLASS(x) class x : public UnitTestBase
    #define DEFINE_TEST_CLASS_PROPS(x) TEST_CLASS(x);\
        DEFINE_TEST_CLASS_SETUP();
    #define DEFINE_TEST_CASE(x) TEST_METHOD(x)
    #define DEFINE_TEST_CASE_PROPERTIES(x) DEFINE_TEST_CASE_PROPERTIES_TAEF(x)
    #define DEFINE_TEST_CASE_PROPERTIES_IGNORE(x) DEFINE_TEST_CASE_PROPERTIES_TAEF_IGNORE()
    #define DEFINE_TEST_CASE_PROPERTIES_FOCUS(x) DEFINE_TEST_CASE_PROPERTIES_TAEF_FOCUS()
    #define DEFINE_TEST_CASE_PROPERTIES_FAILING(x) DEFINE_TEST_CASE_PROPERTIES_TAEF_FAILING()
    #define VERIFY_ARE_EQUAL_INT(x, y) VERIFY_ARE_EQUAL(static_cast<int64_t>(x), static_cast<int64_t>(y))
    #define VERIFY_ARE_EQUAL_UINT(x, y) VERIFY_ARE_EQUAL(static_cast<uint64_t>(x), static_cast<uint64_t>(y))
    #define VERIFY_ARE_EQUAL_DOUBLE(x, y) VERIFY_ARE_EQUAL(static_cast<double>(x), static_cast<double>(y))
    #define VERIFY_ARE_EQUAL_STR_IGNORE_CASE(x, y) VERIFY_ARE_EQUAL_STRING_IGNORE_CASE(x, y)
    #define TEST_LOG(x) LogFormatString(x)
    #define ENABLE_SCREEN_LOGGING 1

    void VerifyEqualStr(Platform::String^ expected, std::wstring actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
    void VerifyEqualStr(Platform::String^ expected, Platform::String^ actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
    void VerifyEqualStr(std::wstring expected, std::wstring actual, std::wstring actualName, const WEX::TestExecution::ErrorInfo& errorInfo);
    //#define VERIFY_ARE_EQUAL_STR(__expected, __actual) VerifyEqualStr((__expected), (__actual), (L#__actual), PRIVATE_VERIFY_ERROR_INFO)
#else 
    #define DEFINE_TEST_CLASS(x) TEST_CLASS(x)
    #define DEFINE_TEST_CLASS_PROPS(x) ;
    //#define DEFINE_TEST_CASE(x) DEFINE_TEST_CASE_TE(x)
    #define DEFINE_TEST_CASE_PROPERTIES(x) DEFINE_TEST_CASE_PROPERTIES_TE()
    #define DEFINE_TEST_CASE_PROPERTIES_IGNORE(x) DEFINE_TEST_CASE_PROPERTIES_TE()
    #define DEFINE_TEST_CASE_PROPERTIES_FOCUS(x) DEFINE_TEST_CASE_PROPERTIES_TE()
    #define DEFINE_TEST_CASE_PROPERTIES_FAILING(x) DEFINE_TEST_CASE_PROPERTIES_TE()
    #define TEST_LOG(x) Logger::WriteMessage(x)
    #define VERIFY_ARE_NOT_EQUAL(expected, actual) Assert::AreNotEqual(expected, actual)
#endif



