#include <DataTypes/IDataType.h>
#include <Functions/FunctionFactory.h>
#include <Functions/FunctionMathUnary.h>


namespace DB
{
namespace
{
    struct RadiansName
    {
        static constexpr auto name = "radians";
    };

    template <typename T>
    Float64 radians(T d)
    {
        Float64 radians = d * (M_PI / 180);
        return radians;
    }

    using FunctionRadians = FunctionMathUnary<UnaryFunctionVectorized<RadiansName, radians>>;
}

void registerFunctionRadians(FunctionFactory & factory)
{
    factory.registerFunction<FunctionRadians>(FunctionFactory::CaseInsensitive);
}

}
