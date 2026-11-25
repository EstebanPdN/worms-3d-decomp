/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800e71ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
lbl_8038afbc = 0x8038afbc;
SECTIONS {
  .text.s8_static_init_800e71ac 0x800e71ac : { *(.text.s8_static_init_800e71ac) }
  .sdata 0x804aaed4 (NOLOAD) : {
    . = 0x0; lbl_804aaed4 = .;
    . = 0x3f28; lbl_804aedfc = .;
    . = 0x3f2c; lbl_804aee00 = .;
    . = 0x3f30; lbl_804aee04 = .;
    . = 0x3f34; lbl_804aee08 = .;
    . = 0x3f38; lbl_804aee0c = .;
    . = 0x3f3c; lbl_804aee10 = .;
    . = 0x3f40; lbl_804aee14 = .;
    . = 0x3f44; lbl_804aee18 = .;
    . = 0x3f48; lbl_804aee1c = .;
    . = 0x3f4c; lbl_804aee20 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
