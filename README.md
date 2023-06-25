### Third party usage test
In this project, we're going to use these following third party.  
1. gflags
2. glogs
3. muduo
4. brpc
5. etc.

### How to organize a project with third_party?
You can see third party source code in `src/third_party/`, for 
example, gflags in `src/third_party/gflags`.   
All the static
third party libraries are in the folder `third_party/3rdlib`.

### How to compile this project?
* Makefile  
  ```shell 
  cd test-third-party  
  make
  
* CMake  
  ```shell
  cd test-third-party  
  mkdir build
  cd build  
  cmake ..  
  make  
### How to run this project?
  `cd test-third-party`  
  `./third_party_test  --flagfile=conf/project.conf`
