/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800fe1a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fd7f4 = 0x800fd7f4;
fn_8015f518 = 0x8015f518;
fn_801629f8 = 0x801629f8;
lbl_80360ff0 = 0x80360ff0;
lbl_803618f0 = 0x803618f0;
lbl_803981d0 = 0x803981d0;
lbl_803e8354 = 0x803e8354;
SECTIONS {
  .text.s8_static_init_800fe1a4 0x800fe1a4 : { *(.text.s8_static_init_800fe1a4) }
  .sdata 0x804af13c (NOLOAD) : {
    . = 0x0; lbl_804af13c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
