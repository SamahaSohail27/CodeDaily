# Bellman Ford and Dijisktra
- Through the Graph in the image we can see dijikstra gives wrong results because we have already updates B as child of C . But after that C was again updated thorgh 
  another edge. In this case we should now again update B beacuse B is child of C and C is changed. But B is not updated even we can come to B thorugh C now whith shorter 
  distance. So To handle such negative cases we use Bellman Ford Algorithm is used .
