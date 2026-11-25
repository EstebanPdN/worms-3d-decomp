/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801cde2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eb834 = 0x801eb834;
fn_801ebf38 = 0x801ebf38;
fn_801ece2c = 0x801ece2c;
fn_801efd34 = 0x801efd34;
lbl_803ae8e4 = 0x803ae8e4;
lbl_803ae960 = 0x803ae960;
lbl_803ae994 = 0x803ae994;
lbl_803ae9bc = 0x803ae9bc;
lbl_803ae9e4 = 0x803ae9e4;
lbl_8045d7f0 = 0x8045d7f0;
lbl_8045ed1c = 0x8045ed1c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801cde2c 0x801cde2c : { *(.text.w3d_s20_register_properties_801cde2c) }
  .sdata 0x804b0534 (NOLOAD) : {
    . = 0x0; lbl_804b0534 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
