.text 
.global main 
main:
.main0:
  #prologue
  pushq %rbp
  movq %rsp, %rbp
  movl $1, -4(%rbp)
  movl $3, -4(%rbp)
  movl -4(%rbp), %eax

  # epilogue
  popq %rbp
  ret
