/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c26_temp_alloc_801fe0b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802fa668 = 0x802fa668;
fn_802fa670 = 0x802fa670;
fn_802fb7ac = 0x802fb7ac;
lbl_803b28e4 = 0x803b28e4;
lbl_8045ebf8 = 0x8045ebf8;
SECTIONS {
  .text.tsonnet_c26_temp_alloc_801fe0b8 0x801fe0b8 : { *(.text.tsonnet_c26_temp_alloc_801fe0b8) }
  .sdata 0x804ab950 (NOLOAD) : {
    . = 0x0; lbl_804ab950 = .;
    . = 0x4; lbl_804ab954 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
