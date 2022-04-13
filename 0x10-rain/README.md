# 0x10. Rain

## 0. Rain
### Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.
- Prototype: def rain(walls)
- walls is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
- If the list is empty return 0.
```
jesse@ubuntu:~/0x10$ 
jesse@ubuntu:~/0x10$ ./0_main.py
6
6
jesse@ubuntu:~/0x10$
```
### Some visual representations:
#### Walls [0,1,0,2,0,3,0,4] 
#### ![Visualization of rain being contained with the walls [0,1,0,2,0,3,0,4]](https://holbertonintranet.s3.amazonaws.com/uploads/medias/2021/4/85ef782020ac6efdc7004b62ea86724a552285b4.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20220413%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20220413T122607Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=84c515c98a159796a157f0bbc8de4435de2a2498fbaae094a11db0de481aa743)
#### Walls [2,0,0,4,0,0,1,0]
#### ![Visualization of rain being contained with the walls [2,0,0,4,0,0,1,0]](https://holbertonintranet.s3.amazonaws.com/uploads/medias/2021/4/9a27c3e4e214e55b3c0b8b1439fdc99b4a184ff5.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20220413%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20220413T122607Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=54a75aeb25fac916498aef4e76605d98523b0c0d99ca79842051fa76e5625979)