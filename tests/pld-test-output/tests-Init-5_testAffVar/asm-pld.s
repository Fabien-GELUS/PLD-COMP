.text 
.global main 
main: 
  # prologue
  pushq %rbp
  movq %rsp, %rbp

  # body 
 movl $42, -4(%rbp)
 movl $100, -8(%rbp)
 movl -8(%rbp), %eax
 movl %eax, -4(%rbp)
  movl -4(%rbp), %eax

  # epilogue
  popq %rbp
  ret
