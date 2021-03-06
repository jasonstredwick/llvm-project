//===- RunnerUtils.cpp - Utils for MLIR exec on targets with a C++ runtime ===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements basic functions to debug structured MLIR types at
// runtime. Entities in this file may not be compatible with targets without a
// C++ runtime. These may be progressively migrated to CRunnerUtils.cpp over
// time.
//
//===----------------------------------------------------------------------===//

#include "mlir/ExecutionEngine/RunnerUtils.h"

extern "C" void _mlir_ciface_print_memref_vector_4x4xf32(
    StridedMemRefType<Vector2D<4, 4, float>, 2> *M) {
  impl::printMemRef(*M);
}

extern "C" void _mlir_ciface_print_memref_i8(UnrankedMemRefType<int8_t> *M) {
  impl::printMemRef(*M);
}

extern "C" void _mlir_ciface_print_memref_i32(UnrankedMemRefType<int32_t> *M) {
  impl::printMemRef(*M);
}

extern "C" void _mlir_ciface_print_memref_i64(UnrankedMemRefType<int64_t> *M) {
  impl::printMemRef(*M);
}

extern "C" void _mlir_ciface_print_memref_f32(UnrankedMemRefType<float> *M) {
  impl::printMemRef(*M);
}

extern "C" void _mlir_ciface_print_memref_f64(UnrankedMemRefType<double> *M) {
  impl::printMemRef(*M);
}

extern "C" void print_memref_i32(int64_t rank, void *ptr) {
  UnrankedMemRefType<int32_t> descriptor = {rank, ptr};
  _mlir_ciface_print_memref_i32(&descriptor);
}

extern "C" void print_memref_i64(int64_t rank, void *ptr) {
  UnrankedMemRefType<int64_t> descriptor = {rank, ptr};
  _mlir_ciface_print_memref_i64(&descriptor);
}

extern "C" void print_memref_f32(int64_t rank, void *ptr) {
  UnrankedMemRefType<float> descriptor = {rank, ptr};
  _mlir_ciface_print_memref_f32(&descriptor);
}

extern "C" void print_memref_f64(int64_t rank, void *ptr) {
  UnrankedMemRefType<double> descriptor = {rank, ptr};
  _mlir_ciface_print_memref_f64(&descriptor);
}

extern "C" void
_mlir_ciface_print_memref_0d_f32(StridedMemRefType<float, 0> *M) {
  impl::printMemRef(*M);
}
extern "C" void
_mlir_ciface_print_memref_1d_f32(StridedMemRefType<float, 1> *M) {
  impl::printMemRef(*M);
}
extern "C" void
_mlir_ciface_print_memref_2d_f32(StridedMemRefType<float, 2> *M) {
  impl::printMemRef(*M);
}
extern "C" void
_mlir_ciface_print_memref_3d_f32(StridedMemRefType<float, 3> *M) {
  impl::printMemRef(*M);
}
extern "C" void
_mlir_ciface_print_memref_4d_f32(StridedMemRefType<float, 4> *M) {
  impl::printMemRef(*M);
}
