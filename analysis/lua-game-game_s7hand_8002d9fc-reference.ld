/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002d9fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8004E460 = 0x8004e460;
fn_80181640 = 0x80181640;
fn_8018179C = 0x8018179c;
lbl_80372B14 = 0x80372b14;
lbl_80372B20 = 0x80372b20;
lbl_80372B24 = 0x80372b24;
SECTIONS {
  .text.w3d_auto_8002d9fc 0x8002d9fc : { *(.text.w3d_auto_8002d9fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
