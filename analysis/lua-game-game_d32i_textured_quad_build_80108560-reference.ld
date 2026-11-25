/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32i_textured_quad_build_80108560)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
add_801d4544 = 0x801d4544;
blend_80399bd8 = 0x80399bd8;
iface_801ef174 = 0x801ef174;
lock_801ef048 = 0x801ef048;
make_8020b680 = 0x8020b680;
query_801d0858 = 0x801d0858;
replace_80174820 = 0x80174820;
service_8020b648 = 0x8020b648;
t_80413db0 = 0x80413db0;
t_804143e0 = 0x804143e0;
t_804144f8 = 0x804144f8;
t_80414518 = 0x80414518;
t_804146e0 = 0x804146e0;
t_80414780 = 0x80414780;
t_80414830 = 0x80414830;
t_80414870 = 0x80414870;
t_804148d0 = 0x804148d0;
t_80415b00 = 0x80415b00;
t_80415c00 = 0x80415c00;
t_80415c30 = 0x80415c30;
t_80415d60 = 0x80415d60;
texA_801d0898 = 0x801d0898;
texB_801d086c = 0x801d086c;
SECTIONS {
  .text.d32i_textured_quad_build_80108560 0x80108560 : { *(.text.d32i_textured_quad_build_80108560) }
  .rodata 0x80399bec : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; global_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
