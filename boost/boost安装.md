###yum install gcc gcc-c++ bzip2 bzip2-devel bzip2-libs python-devel -y

如果不能就上网看yum离线安装。

1、unzip xxx.zip

2、chmod -R 755 xxx

3、sh ./bootstrap.sh

4、./b2

The following directory should be added to compiler include paths:
​          
​    /home/gang/BAK/boost_1_50_0
​      
The following directory should be added to linker library paths:
​      
​    /home/gang/BAK/boost_1_50_0/stage/lib

5、sudo ./b2 install --prefix=/usr/local 



<https://www.cnblogs.com/xiaobingqianrui/p/9328787.html>







## 测试程序

```c++
include <boost/lexical_cast.hpp>

include <iostream>

int main()

{

        using boost::lexical_cast;

        int a = lexical_cast<int>("123");

        double b = lexical_cast<double>("123.12");

        std::cout<<a<<std::endl;

        std::cout<<b<<std::endl;

        return 0;

}

```



