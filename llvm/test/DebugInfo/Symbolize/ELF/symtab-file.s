# REQUIRES: x86-registered-target
## When locating a local symbol, we can obtain the filename according to the
## preceding STT_FILE symbol.
# RUN: llvm-mc -filetype=obj -triple=x86_64 %s -o %t
# RUN: llvm-symbolizer --obj=%t 0 1 2 | FileCheck %s

## TODO Find the preceding STT_FILE symbol as the filename of a local symbol.
# CHECK:       local1
# CHECK-NEXT:  ??:0:0
# CHECK-EMPTY:
# CHECK-NEXT:  local2
# CHECK-NEXT:  ??:0:0
# CHECK-EMPTY:
# CHECK-NEXT:  local3
# CHECK-NEXT:  ??:0:0
# CHECK-EMPTY:

.file "1.c"
local1:
  nop

.file "2.c"
local2:
  nop

.file "3.c"
local3:
  nop
