; ModuleID = './testcases/arr_def.c'
source_filename = "./testcases/arr_def.c"

@arr = global [4 x i32] [i32 1, i32 2, i32 3, i32 4]
@arr1 = global [2 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4]]
@c = global i32 2
@j = global i32 0

define i32 @add(i32 %j) {
entry:
  %0 = load i32, i32* @j, align 4
  %1 = add i32 %0, 1
  ret i32 %1
}

define i32 @main() {
entry:
  store i32 114, i32* @j, align 4
  %k = alloca i32, align 4
  %0 = load i32, i32* @j, align 4
  %1 = call i32 @add(i32 %0)
  store i32 %1, i32* %k, align 4
  %q = alloca i32, align 4
  %2 = load i32, i32* @j, align 4
  %3 = mul i32 %2, 100
  %4 = add i32 %3, 514
  store i32 %4, i32* %q, align 4
  %5 = load i32, i32* %q, align 4
  %6 = icmp sge i32 %5, 0
  %7 = load i32, i32* @j, align 4
  %8 = xor i32 %7, -1
  %9 = icmp sge i32 %8, 0
  %10 = and i1 %6, %9
  br i1 %10, label %true, label %toend

true:                                             ; preds = %entry
  ret i32 0

toend:                                            ; preds = %entry
  %11 = load i32, i32* getelementptr inbounds ([2 x [2 x i32]], [2 x [2 x i32]]* @arr1, i64 1, i64 0, i32 0), align 4
  %12 = add i32 %11, 1
  ret i32 %12
}
