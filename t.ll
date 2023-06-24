; ModuleID = './testcases/arr_def.c'
source_filename = "./testcases/arr_def.c"

@arr = global [4 x i32] [i32 1, i32 2, i32 3, i32 4]
@arr1 = global [2 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4]]
@c = global i32 2

define i32 @add(i32 %j) {
entry:
  %0 = add i32 %j, 1
  ret i32 %0
}

define i32 @main() {
entry:
  %0 = load i32, i32* @c, align 4
  %1 = call i32 @add(i32 %0)
  ret i32 %1
}
