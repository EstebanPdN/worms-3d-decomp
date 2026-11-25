/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801b9a18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801f2358 = 0x801f2358;
lbl_803ab45c = 0x803ab45c;
lbl_803ab524 = 0x803ab524;
lbl_8045d05c = 0x8045d05c;
lbl_8045d070 = 0x8045d070;
lbl_8045e2cc = 0x8045e2cc;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801b9a18 0x801b9a18 : { *(.text.w3d_s10_register_properties_801b9a18) }
  .sdata 0x804b03b0 (NOLOAD) : {
    . = 0x0; lbl_804b03b0 = .;
    . = 0x4; lbl_804b03b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
