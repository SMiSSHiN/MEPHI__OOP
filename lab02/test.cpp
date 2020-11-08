// #include "cissoidDioclesFunc.cpp"

#include "cissoidDiocles.h"
#include "gtest/gtest.h"

using namespace curves;

TEST(CissoidDioclesConstructor, DefoultConstructor)
{
    CissoidDiocles object;
    ASSERT_EQ(1, object.getRad()); // ОК
    ASSERT_NE(-3, object.getRad());
    ASSERT_NE(0, object.getRad());
}

TEST(CissoidDioclesConstructor, TestException)
{
    ASSERT_NO_THROW(CissoidDiocles object(4));
    ASSERT_ANY_THROW(CissoidDiocles object(-1)); // OK
}

TEST(CissoidDioclesMethods, Setters)
{
    CissoidDiocles object;
    object.setRad(4);
    ASSERT_EQ(4, object.getRad()); // OK
    ASSERT_NE(-1, object.getRad());
    ASSERT_NE(0, object.getRad());
    ASSERT_ANY_THROW(object.setRad(-1)); // OK
}

TEST(CissoidDioclesMethods, Functions)
{
    CissoidDiocles object;
    const double err = 0.00001;

    ASSERT_NEAR(12*pow(PI, 2)*pow(1, 3), object.volume(), err); // OK
    ASSERT_NEAR(2*1*pow(sin(1), 3)/cos(1), object.distance(1), err); // OK
    ASSERT_ANY_THROW(object.distance(10)); // OK
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}