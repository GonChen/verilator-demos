# verilator-demo-decoder
A simple template example of how to use Verilator

To run type `make`

Verilator的原理实际上是将Verilog源码编译成单/多线程的C++源代码来进行仿真，
其将所需要仿真的dut编译为一个类，dut的IO口则被编译为类成员。
Verilator不单单只是简单的把Verilog编译为C++，Verilator还会将代码进行优化，
编译成优化过的C++模型来进行仿真。

C++ harness可以理解为你自己规定仿真过程，并使用Verilator规定的语义来进行表达。
书写其有一定的规则，但是只做一些比较基本的仿真，所需要了解的并不多，如下：

  * 包含Verilator核心头文件：verilated.h。如果要加上生成.vcd波形文件的支持，还需要包含verilated_vcd_c.h。同时将需要进行仿真的Verilog代码编译得到的头文件包含进来，如上述的译码器则需要包含头文件VDecoder.h。
  * 初始化模块对象以及波性文件对象，如上例子分别对应VDecoder以及VerilatedVcdC对象。并对Verilator做适当的初始化工作。
  * 编写仿真流程，其核心则是dut顶层对象的eval()方法。
  * 清理工作，包括指针指向空间释放以及文件流关闭等工作。


