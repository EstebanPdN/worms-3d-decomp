/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28i_ribbon_strip_80122bfc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
attach_801750f4 = 0x801750f4;
iface_801ef174 = 0x801ef174;
lock_801ef048 = 0x801ef048;
make_8020b680 = 0x8020b680;
query_801d0858 = 0x801d0858;
t_80414518 = 0x80414518;
t_80414710 = 0x80414710;
t_80414780 = 0x80414780;
t_80414850 = 0x80414850;
t_80414870 = 0x80414870;
t_804148d0 = 0x804148d0;
t_80415b00 = 0x80415b00;
t_80415c00 = 0x80415c00;
t_80415c30 = 0x80415c30;
t_80415cb0 = 0x80415cb0;
texA_801d0898 = 0x801d0898;
texB_801d086c = 0x801d086c;
SECTIONS {
  .text.d28i_ribbon_strip_80122bfc 0x80122bfc : { *(.text.d28i_ribbon_strip_80122bfc) }
  .rodata 0x8039b7f4 : { *(.rodata) }
  .sdata 0x804b186c (NOLOAD) : {
    . = 0x0; shared_804b186c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
