; ModuleID = './testcases/arr_def.c'
source_filename = "./testcases/arr_def.c"

@arr = global [4 x i32] [i32 1, i32 2, i32 3, i32 4]
@arr1 = global [2 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4]]
@c = global i32 2

define i32 @main() {
entry:
  %i = alloca i32, align 4
  %0 = load i32, i32* @c, align 4
  %1 = add i32 %0, 2
  store i32 %1, i32* %i, align 4
  br label %cond

cond:                                             ; preds = %entry, %toend
  %2 = load i32, i32* %i, align 4
  %ifcond = icmp ne i32 %2, 0
  br i1 %ifcond, label %body, label %end

body:                                             ; preds = %cond
  %3 = load i32, i32* %i, align 4
  %4 = add i32 %3, 1
  store i32 %4, i32* %i, align 4
  %5 = load i32, i32* %i, align 4
  %6 = icmp eq i32 %5, 5
  br i1 %6, label %true, label %toend

true:                                             ; preds = %body
  br label %end

toend:                                            ; preds = %body
  br label %cond

end:                                              ; preds = %true, %cond
  %7 = load i32, i32* %i, align 4
  ret i32 %7
}
