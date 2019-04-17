 #include <sys/types.h>
  #include <unistd.h>
  #include <stdio.h>

  void main()
  {
     execl("./date", "date");
  }