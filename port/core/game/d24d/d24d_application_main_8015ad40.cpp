#include "w3d_ptr.h"
#line 1 "d24d_application_main_8015ad40.cpp"
// d24d: 0x8015ad40 (180 bytes). Program entry: run the runtime's static
// construction, print the heap break, install the argument object, store the
// arguments without the program name, run the application, clear the installed
// object, shut down and print the heap break again. Returns 0. The argument
// object's constructor (0x8015b254) and destructor (0x8015b2a4, in-charge flag)
// are out of line.
extern "C" void __main();
extern "C" int printf(Ptr32<const char>, ...);
extern "C" Ptr32<void> w3d_heap_morecore(int);
extern "C" int w3d_auto_8020b3bc(int);
extern "C" int w3d_auto_8020b414();
extern "C" void w3d_application_entry_801267f8();
struct d24d_Arguments {
    Ptr32<void> strings;
    d24d_Arguments();
    ~d24d_Arguments();
};
extern "C" void w3d_auto_8015c3f4(Ptr32<d24d_Arguments>);
extern "C" int d24d_arguments_set_8015b330(Ptr32<d24d_Arguments>, int, Ptr32<Ptr32<char>>);
extern char d24d_heap_format_803a4260[];

extern "C" int d24d_application_main_8015ad40(int argc, Ptr32<Ptr32<char>> argv) {
    __main();
    printf(d24d_heap_format_803a4260, w3d::VA(w3d_heap_morecore(0)));
    w3d_auto_8020b3bc(0);
    {
        d24d_Arguments arguments;
        w3d_auto_8015c3f4(&arguments);
        if (argc) d24d_arguments_set_8015b330(&arguments, argc - 1, argv + 1);
        w3d_application_entry_801267f8();
        w3d_auto_8015c3f4(0);
        w3d_auto_8020b414();
        printf(d24d_heap_format_803a4260, w3d::VA(w3d_heap_morecore(0)));
    }
    return 0;
}


