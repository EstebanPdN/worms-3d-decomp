/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002f354)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
lbl_8040DB38 = 0x8040db38;
SECTIONS {
  .text.w3d_auto_8002f354 0x8002f354 : { *(.text.w3d_auto_8002f354) }
  .sdata 0x804acd44 (NOLOAD) : {
    . = 0x0; lbl_804ACD44 = .;
    . = 0x4a10; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
