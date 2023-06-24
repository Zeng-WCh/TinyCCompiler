; ModuleID = './testcases/arr_def.c'
source_filename = "./testcases/arr_def.c"

@arr = global [4 x i32] [i32 0, i32 0, i32 3, i32 4]

define i32 @main() {
entry:
  %0 = load i32, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i32 0, i32 1), align 4
  %ifcond = icmp ne i32 %0, 0
  br i1 %ifcond, label %true, label %false

true:                                             ; preds = %entry
  ret i32 1

false:                                            ; preds = %entry
  store i32 113, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i32 0, i32 1), align 4
  br label %toend

toend:                                            ; preds = %false
  %1 = load i32, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i32 0, i32 1), align 4
  %2 = load i32, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i32 0, i32 2), align 4
  %3 = add i32 %1, %2
  ret i32 %3
}
