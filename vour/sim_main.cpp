#include <iostream>

#include "Vour.h"
#include "verilated.h"
#define VM_TRACE 1
#if VM_TRACE
#include <verilated_vcd_c.h>       // Trace file format header
#endif
unsigned long int main_time = 0;   // Current simulation time
unsigned long int end_time = 1000;   // Current simulation time

int main(int argc, char **argv, char **env)
{
        Verilated::commandArgs(argc, argv);
        Vour *top = new Vour;
        #if VM_TRACE                       // If verilator was invoked with --trace
        Verilated::traceEverOn(true);    // Verilator must compute traced signals
        VL_PRINTF("Enabling waves...\n");
        VerilatedVcdC* tfp = new VerilatedVcdC;
        top->trace(tfp, 99);            // Trace 99 levels of hierarchy
        tfp->open ("vour.vcd");      // Open the dump file
        #endif
        while (!Verilated::gotFinish() && main_time < end_time)
        {
                if (top->clock)
                        std::cout << " " << top->fn << std::endl;
                top->clock ^= 1;
                top->eval();
                #if VM_TRACE
                if( tfp ) tfp->dump( main_time ); // Create waveform trace for this timestamp
                #endif
                main_time++;
        }

        #if VM_TRACE
        if( tfp ) tfp->close();
        #endif
        delete tfp;
        delete top;
        printf("main_time=%ld \n", main_time);
        exit(0);
}
