// Experimental GC32 mapped reads. Native addresses and access widths observed;
// mapped-storage validity and complete API remain external. No hardware execution.
extern "C" unsigned sol35p6_mapped_flag_80311400() { return *reinterpret_cast<volatile unsigned*>(0xcc006c00u) & 1u; }
extern "C" unsigned sol35p6_mapped_byte_80311604() { return *reinterpret_cast<volatile unsigned*>(0xcc006c04u) & 255u; }
extern "C" unsigned sol35p6_mapped_highbit_8031a2b4() { return *reinterpret_cast<volatile unsigned short*>(0xcc005000u) >> 15; }
