#include<fem.hpp>
using namespace ngfem;
extern "C" {
void CompiledEvaluate(BaseMappedIntegrationRule & mir, BareSliceMatrix<double> results ) {

[[maybe_unused]] auto points = mir.GetPoints();
[[maybe_unused]] auto domain_index = mir.GetTransformation().GetElementIndex();
for ( auto i : Range(mir)) {
[[maybe_unused]] auto & ip = mir[i];
auto var_0_0_0 = points(i,0);
double var_1_0_0;
var_1_0_0 = 0x1p+0 /* (1.0000000000000000e+00) */;
auto var_2_0_0 = var_1_0_0 - var_0_0_0;
auto var_3_0_0 = var_0_0_0 * var_2_0_0;
auto var_4_0_0 = points(i,1);
auto var_5_0_0 = var_3_0_0 * var_4_0_0;
auto var_6_0_0 = var_5_0_0 * var_5_0_0;
auto var_7_0_0 = var_5_0_0 * var_3_0_0;
auto var_8_0_0 = var_6_0_0 + var_7_0_0;
auto var_9_0_0 = var_3_0_0 * var_3_0_0;
auto var_10_0_0 = var_8_0_0 + var_9_0_0;
auto var_11_0_0 = var_10_0_0 * var_10_0_0;
auto var_12_0_0 = var_11_0_0 * var_10_0_0;
auto var_13_0_0 = var_3_0_0 * var_3_0_0;
auto var_14_0_0 = var_12_0_0 * var_13_0_0;
auto var_15_0_0 = var_10_0_0 * var_10_0_0;
auto var_16_0_0 = var_3_0_0 * var_15_0_0;
auto var_17_0_0 = var_14_0_0 + var_16_0_0;
auto var_18_0_0 = var_3_0_0 * var_3_0_0;
auto var_19_0_0 = var_17_0_0 + var_18_0_0;
auto var_20_0_0 = var_5_0_0 * var_5_0_0;
auto var_21_0_0 = var_19_0_0 + var_20_0_0;
auto var_22_0_0 = var_10_0_0 * var_10_0_0;
auto var_23_0_0 = var_21_0_0 + var_22_0_0;
auto var_24_0_0 = var_23_0_0 + var_23_0_0;
auto var_25_0_0 = var_24_0_0 + var_23_0_0;
double var_26_0_0;
var_26_0_0 = var_25_0_0;
results(i,0) =var_26_0_0;

}
}

void CompiledEvaluateSIMD(SIMD_BaseMappedIntegrationRule & mir, BareSliceMatrix<SIMD<double>> results ) {

[[maybe_unused]] auto points = mir.GetPoints();
[[maybe_unused]] auto domain_index = mir.GetTransformation().GetElementIndex();
for ( auto i : Range(mir)) {
[[maybe_unused]] auto & ip = mir[i];
auto var_0_0_0 = points(i,0);
SIMD<double> var_1_0_0;
var_1_0_0 = 0x1p+0 /* (1.0000000000000000e+00) */;
auto var_2_0_0 = var_1_0_0 - var_0_0_0;
auto var_3_0_0 = var_0_0_0 * var_2_0_0;
auto var_4_0_0 = points(i,1);
auto var_5_0_0 = var_3_0_0 * var_4_0_0;
auto var_6_0_0 = var_5_0_0 * var_5_0_0;
auto var_7_0_0 = var_5_0_0 * var_3_0_0;
auto var_8_0_0 = var_6_0_0 + var_7_0_0;
auto var_9_0_0 = var_3_0_0 * var_3_0_0;
auto var_10_0_0 = var_8_0_0 + var_9_0_0;
auto var_11_0_0 = var_10_0_0 * var_10_0_0;
auto var_12_0_0 = var_11_0_0 * var_10_0_0;
auto var_13_0_0 = var_3_0_0 * var_3_0_0;
auto var_14_0_0 = var_12_0_0 * var_13_0_0;
auto var_15_0_0 = var_10_0_0 * var_10_0_0;
auto var_16_0_0 = var_3_0_0 * var_15_0_0;
auto var_17_0_0 = var_14_0_0 + var_16_0_0;
auto var_18_0_0 = var_3_0_0 * var_3_0_0;
auto var_19_0_0 = var_17_0_0 + var_18_0_0;
auto var_20_0_0 = var_5_0_0 * var_5_0_0;
auto var_21_0_0 = var_19_0_0 + var_20_0_0;
auto var_22_0_0 = var_10_0_0 * var_10_0_0;
auto var_23_0_0 = var_21_0_0 + var_22_0_0;
auto var_24_0_0 = var_23_0_0 + var_23_0_0;
auto var_25_0_0 = var_24_0_0 + var_23_0_0;
SIMD<double> var_26_0_0;
var_26_0_0 = var_25_0_0;
results(0,i) =var_26_0_0;

}
}

void CompiledEvaluateDeriv(BaseMappedIntegrationRule & mir, BareSliceMatrix<AutoDiff<1,double>> results ) {

[[maybe_unused]] auto points = mir.GetPoints();
[[maybe_unused]] auto domain_index = mir.GetTransformation().GetElementIndex();
for ( auto i : Range(mir)) {
[[maybe_unused]] auto & ip = mir[i];
auto var_0_0_0 = points(i,0);
AutoDiff<1,double> var_1_0_0;
var_1_0_0 = 0x1p+0 /* (1.0000000000000000e+00) */;
auto var_2_0_0 = var_1_0_0 - var_0_0_0;
auto var_3_0_0 = var_0_0_0 * var_2_0_0;
auto var_4_0_0 = points(i,1);
auto var_5_0_0 = var_3_0_0 * var_4_0_0;
auto var_6_0_0 = var_5_0_0 * var_5_0_0;
auto var_7_0_0 = var_5_0_0 * var_3_0_0;
auto var_8_0_0 = var_6_0_0 + var_7_0_0;
auto var_9_0_0 = var_3_0_0 * var_3_0_0;
auto var_10_0_0 = var_8_0_0 + var_9_0_0;
auto var_11_0_0 = var_10_0_0 * var_10_0_0;
auto var_12_0_0 = var_11_0_0 * var_10_0_0;
auto var_13_0_0 = var_3_0_0 * var_3_0_0;
auto var_14_0_0 = var_12_0_0 * var_13_0_0;
auto var_15_0_0 = var_10_0_0 * var_10_0_0;
auto var_16_0_0 = var_3_0_0 * var_15_0_0;
auto var_17_0_0 = var_14_0_0 + var_16_0_0;
auto var_18_0_0 = var_3_0_0 * var_3_0_0;
auto var_19_0_0 = var_17_0_0 + var_18_0_0;
auto var_20_0_0 = var_5_0_0 * var_5_0_0;
auto var_21_0_0 = var_19_0_0 + var_20_0_0;
auto var_22_0_0 = var_10_0_0 * var_10_0_0;
auto var_23_0_0 = var_21_0_0 + var_22_0_0;
auto var_24_0_0 = var_23_0_0 + var_23_0_0;
auto var_25_0_0 = var_24_0_0 + var_23_0_0;
AutoDiff<1,double> var_26_0_0;
var_26_0_0 = var_25_0_0;
results(i,0) =var_26_0_0;

}
}

void CompiledEvaluateDerivSIMD(SIMD_BaseMappedIntegrationRule & mir, BareSliceMatrix<AutoDiff<1,SIMD<double>>> results ) {

[[maybe_unused]] auto points = mir.GetPoints();
[[maybe_unused]] auto domain_index = mir.GetTransformation().GetElementIndex();
for ( auto i : Range(mir)) {
[[maybe_unused]] auto & ip = mir[i];
auto var_0_0_0 = points(i,0);
AutoDiff<1,SIMD<double>> var_1_0_0;
var_1_0_0 = 0x1p+0 /* (1.0000000000000000e+00) */;
auto var_2_0_0 = var_1_0_0 - var_0_0_0;
auto var_3_0_0 = var_0_0_0 * var_2_0_0;
auto var_4_0_0 = points(i,1);
auto var_5_0_0 = var_3_0_0 * var_4_0_0;
auto var_6_0_0 = var_5_0_0 * var_5_0_0;
auto var_7_0_0 = var_5_0_0 * var_3_0_0;
auto var_8_0_0 = var_6_0_0 + var_7_0_0;
auto var_9_0_0 = var_3_0_0 * var_3_0_0;
auto var_10_0_0 = var_8_0_0 + var_9_0_0;
auto var_11_0_0 = var_10_0_0 * var_10_0_0;
auto var_12_0_0 = var_11_0_0 * var_10_0_0;
auto var_13_0_0 = var_3_0_0 * var_3_0_0;
auto var_14_0_0 = var_12_0_0 * var_13_0_0;
auto var_15_0_0 = var_10_0_0 * var_10_0_0;
auto var_16_0_0 = var_3_0_0 * var_15_0_0;
auto var_17_0_0 = var_14_0_0 + var_16_0_0;
auto var_18_0_0 = var_3_0_0 * var_3_0_0;
auto var_19_0_0 = var_17_0_0 + var_18_0_0;
auto var_20_0_0 = var_5_0_0 * var_5_0_0;
auto var_21_0_0 = var_19_0_0 + var_20_0_0;
auto var_22_0_0 = var_10_0_0 * var_10_0_0;
auto var_23_0_0 = var_21_0_0 + var_22_0_0;
auto var_24_0_0 = var_23_0_0 + var_23_0_0;
auto var_25_0_0 = var_24_0_0 + var_23_0_0;
AutoDiff<1,SIMD<double>> var_26_0_0;
var_26_0_0 = var_25_0_0;
results(0,i) =var_26_0_0;

}
}

void CompiledEvaluateDDeriv(BaseMappedIntegrationRule & mir, BareSliceMatrix<AutoDiffDiff<1,double>> results ) {

[[maybe_unused]] auto points = mir.GetPoints();
[[maybe_unused]] auto domain_index = mir.GetTransformation().GetElementIndex();
for ( auto i : Range(mir)) {
[[maybe_unused]] auto & ip = mir[i];
auto var_0_0_0 = points(i,0);
AutoDiffDiff<1,double> var_1_0_0;
var_1_0_0 = 0x1p+0 /* (1.0000000000000000e+00) */;
auto var_2_0_0 = var_1_0_0 - var_0_0_0;
auto var_3_0_0 = var_0_0_0 * var_2_0_0;
auto var_4_0_0 = points(i,1);
auto var_5_0_0 = var_3_0_0 * var_4_0_0;
auto var_6_0_0 = var_5_0_0 * var_5_0_0;
auto var_7_0_0 = var_5_0_0 * var_3_0_0;
auto var_8_0_0 = var_6_0_0 + var_7_0_0;
auto var_9_0_0 = var_3_0_0 * var_3_0_0;
auto var_10_0_0 = var_8_0_0 + var_9_0_0;
auto var_11_0_0 = var_10_0_0 * var_10_0_0;
auto var_12_0_0 = var_11_0_0 * var_10_0_0;
auto var_13_0_0 = var_3_0_0 * var_3_0_0;
auto var_14_0_0 = var_12_0_0 * var_13_0_0;
auto var_15_0_0 = var_10_0_0 * var_10_0_0;
auto var_16_0_0 = var_3_0_0 * var_15_0_0;
auto var_17_0_0 = var_14_0_0 + var_16_0_0;
auto var_18_0_0 = var_3_0_0 * var_3_0_0;
auto var_19_0_0 = var_17_0_0 + var_18_0_0;
auto var_20_0_0 = var_5_0_0 * var_5_0_0;
auto var_21_0_0 = var_19_0_0 + var_20_0_0;
auto var_22_0_0 = var_10_0_0 * var_10_0_0;
auto var_23_0_0 = var_21_0_0 + var_22_0_0;
auto var_24_0_0 = var_23_0_0 + var_23_0_0;
auto var_25_0_0 = var_24_0_0 + var_23_0_0;
AutoDiffDiff<1,double> var_26_0_0;
var_26_0_0 = var_25_0_0;
results(i,0) =var_26_0_0;

}
}

void CompiledEvaluateDDerivSIMD(SIMD_BaseMappedIntegrationRule & mir, BareSliceMatrix<AutoDiffDiff<1,SIMD<double>>> results ) {

[[maybe_unused]] auto points = mir.GetPoints();
[[maybe_unused]] auto domain_index = mir.GetTransformation().GetElementIndex();
for ( auto i : Range(mir)) {
[[maybe_unused]] auto & ip = mir[i];
auto var_0_0_0 = points(i,0);
AutoDiffDiff<1,SIMD<double>> var_1_0_0;
var_1_0_0 = 0x1p+0 /* (1.0000000000000000e+00) */;
auto var_2_0_0 = var_1_0_0 - var_0_0_0;
auto var_3_0_0 = var_0_0_0 * var_2_0_0;
auto var_4_0_0 = points(i,1);
auto var_5_0_0 = var_3_0_0 * var_4_0_0;
auto var_6_0_0 = var_5_0_0 * var_5_0_0;
auto var_7_0_0 = var_5_0_0 * var_3_0_0;
auto var_8_0_0 = var_6_0_0 + var_7_0_0;
auto var_9_0_0 = var_3_0_0 * var_3_0_0;
auto var_10_0_0 = var_8_0_0 + var_9_0_0;
auto var_11_0_0 = var_10_0_0 * var_10_0_0;
auto var_12_0_0 = var_11_0_0 * var_10_0_0;
auto var_13_0_0 = var_3_0_0 * var_3_0_0;
auto var_14_0_0 = var_12_0_0 * var_13_0_0;
auto var_15_0_0 = var_10_0_0 * var_10_0_0;
auto var_16_0_0 = var_3_0_0 * var_15_0_0;
auto var_17_0_0 = var_14_0_0 + var_16_0_0;
auto var_18_0_0 = var_3_0_0 * var_3_0_0;
auto var_19_0_0 = var_17_0_0 + var_18_0_0;
auto var_20_0_0 = var_5_0_0 * var_5_0_0;
auto var_21_0_0 = var_19_0_0 + var_20_0_0;
auto var_22_0_0 = var_10_0_0 * var_10_0_0;
auto var_23_0_0 = var_21_0_0 + var_22_0_0;
auto var_24_0_0 = var_23_0_0 + var_23_0_0;
auto var_25_0_0 = var_24_0_0 + var_23_0_0;
AutoDiffDiff<1,SIMD<double>> var_26_0_0;
var_26_0_0 = var_25_0_0;
results(0,i) =var_26_0_0;

}
}

}
