; ModuleID = './testcases/arr_def.c'
source_filename = "./testcases/arr_def.c"

@arr = global [4 x i32] [i32 1, i32 2, i32 3, i32 4]

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i32 0, i32 0), i32* %a, align 8
  %0 = add i32* %a, i32 10
  store i32* %0, i32* %a, align 8
  store i32* %a, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i32 0, i32 3), align 8
}
