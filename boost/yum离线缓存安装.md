1、开启yum缓存

vim /etc/yum.conf

cachedir=/var/cache/yum/

修改 keepcache=1

2、开启缓存后，用yum install安装的软件包会在/var/cache/yum中保存

redhet 在/var/cache/yum/base/packages/下

3、将/var/cache/yum中的文件打包，恢复到要用的离线系统中相同位置

4、yum -C update

5、yum -C install you-need-packagename

注意：两台电脑的系统要相同