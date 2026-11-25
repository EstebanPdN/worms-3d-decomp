/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f6a_construct_console_8028df60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13Text_803426b8 = 0x803426b8;
__14Names_800c4598 = 0x800c4598;
fn_801628b0 = 0x801628b0;
fn_8035ec68 = 0x8035ec68;
vt_8041c1b0 = 0x8041c1b0;
SECTIONS {
  .text.w3d_f6a_construct_console_8028df60 0x8028df60 : { *(.text.w3d_f6a_construct_console_8028df60) }
  .sdata 0x804abbf4 (NOLOAD) : {
    . = 0x0; instance_804abbf4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
