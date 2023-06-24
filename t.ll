; ModuleID = 'testcases/arr_def.c'
source_filename = "testcases/arr_def.c"

@arr = global [4 x i32] [i32 1, i32 2, i32 3, i32 4]
@arr1 = global [2 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4]]

define i32 @main() {
entry:
  %0 = load i32, i32* getelementptr inbounds ([2 x [2 x i32]], [2 x [2 x i32]]* @arr1, i32 0, i32 1, i32 1), align 4
  %1 = load i32, i32* getelementptr inbounds ([2 x [2 x i32]], [2 x [2 x i32]]* @arr1, i32 0, i32 0, i32 1), align 4
  %2 = add i32 %0, %1
  ret i32 %2
}
