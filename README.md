# Reverse-exercise
# Introduce
本项目来自于HuhstSec，作用于实验室的Re训练，每道题突出考查一个知识点，作为专项练习使用
# inlinehook
考察inlinehook知识点
# junkcode1
考察永真条件跳转花指令
# junkcode2
考察利用esp定律跳过花指令
# ollvm-flat
编译参数为clang -mllvm -fla -mllvm -split-num=5 ./ollvm-flat.cpp -o ollvm-flat
使用Pluto-Obfuscator
# native-Andriod
考察native动态注册，主要逆向点为静态链接.so文件，可以使用jadx自带的调试或者Frida hook等操作解题，如果需要编译需要注意在Android studio中的activity_main.xml文件中更新头像的图片地址
![1_BigPic](https://github.com/SHangwendada/Reverse-exercise/assets/102873474/b2688605-ac4b-435d-93ed-ac6efa64c841)
